#  This file is copied
#  by Tomoya Tanaka <deepsky2221@gmail.com>
#  from <https://github.com/riebl/vanetza/blob/master/tools/cohda_proxy/CMakeLists.txt>
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


find_package(Cohda MODULE REQUIRED)
add_executable(cohda_proxy proxy.cpp proxy_handler.cpp)
target_include_directories(cohda_proxy PUBLIC ${COHDA_INCLUDE_DIRS})
target_link_libraries(cohda_proxy Boost::system Vanetza::access Vanetza::net)
