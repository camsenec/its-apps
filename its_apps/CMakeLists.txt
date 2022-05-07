#  (C) 2022 Tomoya Tanaka <deepsky2221@gmail.com> 
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


cmake_minimum_required(VERSION 3.5)
project(its_apps VERSION 0.0.1)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# Vanetza makes extensive use of C++11
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Look up threading library (usually pthread)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads MODULE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib/static)


include(GNUInstallDirs)
include(UseVanetzaExtension)

# Enable usage of targets' folder property (good for Visual Studio)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Find project dependencies
find_package(Cohda MODULE QUIET)
find_package(OpenSSL QUIET)
find_package(Vanetza 0.8 REQUIRED)

# Find ROS dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(its_apps_interfaces REQUIRED)

set(Boost_COMPONENTS date_time) # used by VanetzaConfig generator
find_package(Boost 1.58 REQUIRED COMPONENTS ${Boost_COMPONENTS})
# query optional Boost components one by one quietly
foreach(component IN ITEMS program_options system)
  find_package(Boost 1.58 QUIET COMPONENTS ${component})
  if (Boost_${component}_FOUND)
    list(APPEND Boost_COMPONENTS ${component})
  endif()
endforeach()

add_subdirectory(src)
add_subdirectory(vanetza-extension/asn1)
add_subdirectory(vanetza-extension/facilities)

set(BUILD_CERTIFY ON)
if(BUILD_CERTIFY)
	add_subdirectory(tools/certify)
endif()

if(TARGET Cohda::headers)
  add_subdirectory(src/cohda_proxy)
endif()

# interface library for convenience
get_property(_components GLOBAL PROPERTY VANETZA_EXTENSION_COMPONENTS)
add_library(vanetza-extension INTERFACE)
add_library(Vanetza-extension::vanetza-extension ALIAS vanetza-extension)
foreach(_component IN LISTS _components)
  target_link_libraries(vanetza-extension INTERFACE ${_component})
endforeach()

ament_package()
