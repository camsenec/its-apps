/* 
 * This file is copied
 * by Tomoya Tanaka <deepsky2221@gmail.com>
 * from <https://github.com/riebl/vanetza/blob/master/tools/socktap/positioning.cpp>
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


#include "positioning.hpp"
#include <vanetza/common/stored_position_provider.hpp>
#include <map>

#ifdef ITS_APPS_WITH_GPSD
#   include "gps_position_provider.hpp"
#endif

using namespace vanetza;
namespace po = boost::program_options;

std::unique_ptr<vanetza::PositionProvider>
create_position_provider(boost::asio::io_service& io_service, const PositionParams& params, const Runtime& runtime)
{   
    std::unique_ptr<vanetza::PositionProvider> positioning;
    if (params.positioning == "gpsd") {
#ifdef ITS_APPS_WITH_GPSD
            positioning.reset(new GpsPositionProvider {
            io_service, params.gpsd_host.get(), params.gpsd_port.get()
        });
#endif
    } else if (params.positioning == "static") {

        std::unique_ptr<StoredPositionProvider> stored { new StoredPositionProvider() };
        PositionFix fix;
        fix.timestamp = runtime.now();
        fix.latitude = params.latitude * units::degree; 
        fix.longitude = params.longitude * units::degree;
        fix.confidence.semi_major = params.pos_confidence * units::si::meter;
        fix.confidence.semi_minor = fix.confidence.semi_major;
        stored->position_fix(fix);
        positioning = std::move(stored);
    }

    return positioning;
}
