/* 
 * This file is copied
 * by Tomoya Tanaka <deepsky2221@gmail.com>
 * from <https://github.com/riebl/vanetza/blob/master/tools/socktap/positioning.hpp>
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


#ifndef POSITIONING_HPP_VZRIW7PB
#define POSITIONING_HPP_VZRIW7PB

#include <vanetza/common/position_provider.hpp>
#include <vanetza/common/runtime.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/optional/optional.hpp>
#include <memory>
#include <stdexcept>

class PositioningException : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

struct position_params {
    std::string positioning;
    double latitude;
    double longitude;
    double pos_confidence;
    boost::optional<std::string> gpsd_host;
    boost::optional<std::string> gpsd_port;
};

std::unique_ptr<vanetza::PositionProvider>
create_position_provider(boost::asio::io_service&, const position_params&, const vanetza::Runtime&);


#endif /* POSITIONING_HPP_VZRIW7PB */
