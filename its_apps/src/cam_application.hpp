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


#ifndef CAM_APPLICATION_HPP
#define CAM_APPLICATION_HPP

#include "its_app.hpp"
#include "application.hpp"
#include "its_apps_interfaces/msg/cam.hpp"
#include "vanetza-extension/asn1/cam.hpp"
#include <rclcpp/rclcpp.hpp>
#include <vanetza/common/clock.hpp>
#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>


class CamApplication : public Application
{
public:
    explicit CamApplication(rclcpp::Publisher<its_apps_interfaces::msg::Cam>::SharedPtr);
    PortType port() override;
    void indicate(const DataIndication&, UpPacketPtr) override;
    void print_received_message(bool flag);

private:
    void publish(const vanetzaExtension::asn1::Cam&);
    
    bool print_rx_msg_ = false;
    rclcpp::Publisher<its_apps_interfaces::msg::Cam>::SharedPtr publisher_;

};

#endif /* CAM_APPLICATION_HPP_EUIC2VFR */
