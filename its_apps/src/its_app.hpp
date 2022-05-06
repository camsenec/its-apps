/* 
 * This file is modified
 * by Tomoya Tanaka <deepsky2221@gmail.com>
 * from <https://github.com/riebl/vanetza/blob/master/tools/socktap/main.cpp>
 * at 2022-05-06.
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

/* 
 * State Changes
 * - Options are added.
 * - DEN, MAP and SPAT applications are added.
*/


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
#include <boost/asio/io_service.hpp>
#include <boost/asio/signal_set.hpp>
#include <boost/program_options.hpp>
#include <rclcpp/rclcpp.hpp>
#include <iostream>

namespace asio = boost::asio;
namespace gn = vanetza::geonet;
namespace po = boost::program_options;
using namespace vanetza;

class ItsApp: public rclcpp::Node
{   
    public:
        ItsApp();
};
