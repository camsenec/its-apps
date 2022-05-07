#  This file is modified
#  by Tomoya Tanaka <deepsky2221@gmail.com>
#  from <https://github.com/riebl/vanetza/blob/master/vanetza/facilities/CMakeLists.txt>
#  at 2022-05-06.
#  
#  This file is part of its_apps.
# 
#  its_apps is free software: you can redistribute it and/or modify it 
#  under the terms of the GNU Lesser General Public License as published
#  by the Free Software Foundation, either version 3 of the License, or 
#  any later version.
#  its_apps is distributed in the hope that it will be useful, 
#  but WITHOUT ANY WARRANTY; without even the implied warranty of 
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
#  See the GNU General Public License and 
#  GNU Lesser General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License 
#  and GNU Lesser General Public License along with its_apps. 
#  If not, see <https://www.gnu.org/licenses/>. 

#  State changes
#  - Some source files are added for CXX_SOURCES.
#  - Dependent library asn1 is changed to Vanetza-extension::asn1.


find_package(its_apps_interfaces REQUIRED)

set(CXX_SOURCES
    functions.cpp
    cam_functions.cpp
    denm_functions.cpp
    spatem_functions.cpp
    mapem_functions.cpp
)

add_vanetza_extension_component(facilities ${CXX_SOURCES})

target_include_directories(facilities PRIVATE
    ${its_apps_interfaces_INCLUDE_DIRS}
)

target_link_libraries(facilities PRIVATE
    Boost::date_time 
    Vanetza-extension::asn1 
    ${its_apps_interfaces_LIBRARIES}
    Vanetza::geonet 
    Vanetza::security
)


add_test_subdirectory(tests)

