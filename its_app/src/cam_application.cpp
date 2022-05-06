/* 
 * This file is modified
 * by Tomoya Tanaka <deepsky2221@gmail.com>
 * from <https://github.com/riebl/vanetza/blob/master/tools/socktap/cam_application.cpp>
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
 * - Include file paths are changed.
*/


#include "cam_application.hpp"
#include "vanetza-extension/asn1/cam.hpp"
#include "vanetza-extension/facilities/functions.hpp"
#include "vanetza-extension/facilities/cam_functions.hpp"
#include "vanetza-extension/asn1/packet_visitor.hpp"
#include <vanetza/geonet/data_request.hpp>
#include <vanetza/geonet/tests/network_topology.hpp>
#include <vanetza/btp/ports.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>

// This is a very simple CA application sending CAMs at a fixed rate.
using namespace vanetza;
using namespace std::chrono;

void CamApplication::print_received_message(bool flag)
{
    print_rx_msg_ = flag;
}

CamApplication::PortType CamApplication::port()
{
    return vanetza::btp::ports::CAM;
}

void CamApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    vanetzaExtension::asn1::PacketVisitor<vanetzaExtension::asn1::Cam> visitor;
    std::shared_ptr<const vanetzaExtension::asn1::Cam> cam = boost::apply_visitor(visitor, *packet);

    std::cout << "CAM application received a packet with " << (cam ? "decodable" : "broken") << " content" << std::endl;
    if (cam && print_rx_msg_) {
        std::cout << "Received CAM contains\n";
        vanetzaExtension::facilities::cam::print_indented(std::cout, *cam, "  ", 1);
    }
}
