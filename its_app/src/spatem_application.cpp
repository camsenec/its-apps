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


#include "spatem_application.hpp"
#include "vanetza-extension/asn1/spatem.hpp"
#include "vanetza-extension/facilities/cam_functions.hpp"
#include "vanetza-extension/asn1/packet_visitor.hpp"
#include <vanetza/btp/ports.hpp>
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <chrono>
#include <exception>
#include <functional>
#include <iostream>


using namespace std::chrono;


void SpatemApplication::print_received_message(bool flag)
{
    print_rx_msg_ = flag;
}

SpatemApplication::PortType SpatemApplication::port()
{
    return vanetza::btp::ports::SPAT;
}

void SpatemApplication::indicate(const DataIndication& indication, UpPacketPtr packet)
{
    vanetzaExtension::asn1::PacketVisitor<vanetzaExtension::asn1::Spatem> visitor;
    //type check of packet
    std::shared_ptr<const vanetzaExtension::asn1::Spatem> spat = boost::apply_visitor(visitor, *packet);

    std::cout << "SPATEM application received a packet with " << (spat ? "decodable" : "broken") << " content" << std::endl;
    if (spat && print_rx_msg_) {
        std::cout << "Received SPATEM contains\n";
        //print_indented(std::cout, *spat, "  ", 1);
    }
}