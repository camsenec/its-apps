/* 
 * (C) 2022 Tomoya Tanaka <deepsky2221@gmail.com> 
 *
 * This file is part of its_apps.
 *
 * its_apps is free software: you can redistribute it and/or modify it 
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or 
 * any later version.
 * its_apps is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License and 
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * and GNU Lesser General Public License along with its_apps. 
 * If not, see <https://www.gnu.org/licenses/>. 
 */


#include "its_app.hpp"
#include "ethernet_device.hpp"
#include "cam_application.hpp"
#include "denm_application.hpp"
#include "spatem_application.hpp"
#include "mapem_application.hpp"
#include "link_layer.hpp"
#include "positioning.hpp"
#include "router_context.hpp"
#include "security.hpp"
#include "time_trigger.hpp"
#include "its_apps_interfaces/msg/cam.hpp"
#include "rclcpp/rclcpp.hpp"
#include <boost/asio/io_service.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/program_options.hpp>
#include <iostream>

#ifdef ITS_APPS_WITH_GPSD
#   include "gps_position_provider.hpp"
#endif

namespace asio = boost::asio;
namespace gn = vanetza::geonet;
namespace po = boost::program_options;
using namespace vanetza;

ItsApp::ItsApp() : Node("its_apps_node")
{
    this->declare_parameter<std::string>("link-layer", "ethernet");
    this->declare_parameter<std::string>("interface", "lo");
    this->declare_parameter<bool>("require-gnss-fix", true);
    this->declare_parameter<bool>("print-rx", false);
    this->declare_parameter<std::vector<std::string>>("applications", {"ca", "den", "spat", "map"});
    this->declare_parameter<std::string>("positioning", "gpsd");
    this->declare_parameter<double>("latitude", 48.7668616);
    this->declare_parameter<double>("longitude", 11.423068);
    this->declare_parameter<double>("pos_confidence", 5.0);
    this->declare_parameter<std::string>("security", "dummy");
    this->declare_parameter<std::string>("certificate", "");
    this->declare_parameter<std::string>("certificate-key", "");
    this->declare_parameter<std::vector<std::string>>("certificate-chain", {});
#ifdef ITS_APPS_WITH_GPSD
    this->declare_parameter<std::string>("gpsd_host", gpsd::shared_memory);
    this->declare_parameter<std::string>("gpsd_port", gpsd::default_port);
#endif

    rclcpp::Publisher<its_apps_interfaces::msg::Cam>::SharedPtr cam_publisher 
        = this->create_publisher<its_apps_interfaces::msg::Cam>("cam_basic", 10);

    try {
        asio::io_service io_service;
        TimeTrigger trigger(io_service);
        
        // Initialize network interface
        std::string device_name; 
        this->get_parameter<std::string>("interface", device_name);
        EthernetDevice device(device_name.c_str());

        // Initialize link layer 
        std::string link_layer_name;
        this->get_parameter<std::string>("link-layer", link_layer_name);
        
        auto link_layer =  create_link_layer(io_service, device, link_layer_name);
        if (!link_layer) {
            std::cerr << "No link layer '" << link_layer_name << "' found." << std::endl;
            return;
        }

        // Configure management information base
        gn::MIB mib;
        mib.itsGnLocalGnAddr.mid(device.address());
        mib.itsGnLocalGnAddr.is_manually_configured(true);
        mib.itsGnLocalAddrConfMethod = geonet::AddrConfMethod::Managed;
        mib.itsGnSecurity = false;
        mib.itsGnProtocolVersion = 1;

        // Initialize position provider
        std::string positioning;
        double latitude;
        double longitude;
        double pos_confidence;
        this->get_parameter("positioning", positioning);
        this->get_parameter("latitude", latitude);
        this->get_parameter("longitude", longitude);
        this->get_parameter("pos_confidence" ,pos_confidence);
        PositionParams position_params = {positioning, latitude, longitude, pos_confidence};
#ifdef ITS_APPS_WITH_GPSD
        std::string gpsd_host;
        std::string gpsd_port;
        this->get_parameter<std::string>("gpsd_host", gpsd_host);
        this->get_parameter<std::string>("gpsd_port", gpsd_port);
        position_params = {positioning, latitude, longitude, pos_confidence, gpsd_host, gpsd_port};
#endif
        auto position_provider = create_position_provider(io_service, position_params, trigger.runtime());
        if (!position_provider) {
            std::cerr << "Requested positioning method is not available\n";
            return;
        }
         
        // Initialize security entity 
        std::string security;
        std::string certificate;
        std::string certificate_key; 
        std::vector<std::string> certificate_chain;
        this->get_parameter("security", security);
        this->get_parameter("certificate", certificate);
        this->get_parameter("certificate-key", certificate_key);
        this->get_parameter("certificate-chain", certificate_chain);
        SecurityParams security_params = {security, certificate, certificate_key, certificate_chain};
        auto security_entity = create_security_entity(trigger.runtime(), security_params, *position_provider);
        if (security_entity) {
            mib.itsGnSecurity = true;
        }
        
        // Initialize router context
        RouterContext context(mib, trigger, *position_provider, security_entity.get());
        bool is_require_position_fix;
        this->get_parameter("require-gnss-fix", is_require_position_fix);
        context.require_position_fix(is_require_position_fix);
        context.set_link_layer(link_layer.get());

        // Initialize ITS applications 
        bool is_print_rx;
        this->get_parameter("print-rx", is_print_rx);
        std::map<std::string, std::unique_ptr<Application>> apps;
        std::vector<std::string> app_names;
        this->get_parameter("applications", app_names);
        for (const std::string& app_name : app_names) {
            if (apps.find(app_name) != apps.end()) {
                std::cerr << "application '" << app_name << "' requested multiple times, skip\n";
                continue;
            }
            if (app_name == "ca") {
                std::unique_ptr<CamApplication> ca {
                    new CamApplication(cam_publisher)
                };
                ca->print_received_message(is_print_rx);
                apps.emplace(app_name, std::move(ca));
            } else if (app_name == "den") {
                std::unique_ptr<DenmApplication> den {
                    new DenmApplication()
                };
                den->print_received_message(is_print_rx);
                apps.emplace(app_name, std::move(den));
            } else if (app_name == "spat") {
                std::unique_ptr<SpatemApplication> spatem {
                    new SpatemApplication()
                };
                spatem->print_received_message(is_print_rx);
                apps.emplace(app_name, std::move(spatem));
            } else if (app_name == "map") { 
                std::unique_ptr<MapemApplication> mapem {
                    new MapemApplication()
                };
                mapem->print_received_message(is_print_rx);
                apps.emplace(app_name, std::move(mapem));
            } else {
                std::cerr << "skip unknown application '" << app_name << "'\n";
            }
        }

        if (apps.empty()) {
            std::cerr << "Warning: No applications are configured, only GN beacons will be exchanged\n";
        }

        for (const auto& app : apps) {
            std::cout << "Enable application '" << app.first << "'...\n";
            context.enable(app.second.get());
        }
        
        // Start io_service
        io_service.run();
    } catch (PositioningException& e) {
        std::cerr << "Exit because of positioning error: " << e.what() << std::endl;
        return;
    } catch (std::exception& e) {
        std::cerr << "Exit: " << e.what() << std::endl;
        return;
    }
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ItsApp>());
    rclcpp::shutdown();
    return 0;
}
