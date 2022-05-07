#  This file is modified
#  by Tomoya Tanaka <deepsky2221@gmail.com>
#  from <https://github.com/riebl/vanetza/blob/master/tools/socktap/CMakeLists.txt>
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
#  - The target name is changed.
#  - Some source files are added to generate executable target its_apps.
#  - Dependent library Vanetza-extension::vanetza-extension is added.
#  - The name of the target to be installed is changed to its_apps.


if(NOT TARGET Boost::system)
    message(STATUS "Skip build of its_apps because of missing Boost::system dependency")
    return()
endif()

if(NOT TARGET Boost::program_options)
    message(STATUS "Skip build of its_apps because of missing Boost::program_options dependency")
    return()
endif()

add_executable(its_apps_node
    application.cpp
    cam_application.cpp
    denm_application.cpp
    spatem_application.cpp
    mapem_application.cpp
    dcc_passthrough.cpp
    ethernet_device.cpp
    link_layer.cpp
    its_app.cpp
    positioning.cpp
    raw_socket_link.cpp
    router_context.cpp
    security.cpp
    time_trigger.cpp
    udp_link.cpp
)

target_include_directories(its_apps_node PRIVATE
    ${rclcpp_INCLUDE_DIRS}
    ${its_apps_interfaces_INCLUDE_DIRS}
)

target_link_libraries(its_apps_node PRIVATE
    Boost::system
    Boost::program_options 
    Threads::Threads
    Vanetza-extension::vanetza-extension
    Vanetza::vanetza
    ${rclcpp_LIBRARIES}
    ${its_apps_interfaces_LIBRARIES}
)

install(TARGETS its_apps_node DESTINATION lib/${PROJECT_NAME})

option(its_apps_WITH_COHDA_LLC "Use Cohda LLC API for its_apps" ${COHDA_FOUND})
if(its_apps_WITH_COHDA_LLC)
    find_package(Cohda MODULE REQUIRED)
    target_compile_definitions(its_apps_node PUBLIC "its_apps_WITH_COHDA_LLC")
    target_include_directories(its_apps_node PUBLIC ${COHDA_INCLUDE_DIRS})
    target_sources(its_apps_node PRIVATE cohda.cpp cohda_link.cpp)
endif()

find_package(GPS QUIET)
option(ITS_APPS_WITH_GPSD "Enable gpsd positioning for its_apps" ${GPS_FOUND})
if(ITS_APPS_WITH_GPSD)
    find_package(GPS REQUIRED)
    target_compile_definitions(its_apps_node PUBLIC "its_apps_WITH_GPSD")
    target_link_libraries(its_apps_node PUBLIC GPS::GPS)
    target_sources(its_apps_node PRIVATE gps_position_provider.cpp)
endif()
