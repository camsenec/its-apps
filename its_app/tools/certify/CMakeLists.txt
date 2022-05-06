#  This file is copied
#  by Tomoya Tanaka <deepsky2221@gmail.com>
#  from <https://github.com/riebl/vanetza/blob/master/tools/certifyCMakeLists.txt>
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

add_executable(certify
    commands/extract-public-key.cpp
    commands/generate-aa.cpp
    commands/generate-key.cpp
    commands/generate-root.cpp
    commands/generate-ticket.cpp
    commands/show-certificate.cpp
    main.cpp
    options.cpp
    utils.cpp
)

set_target_properties(certify PROPERTIES INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(certify Boost::program_options Vanetza::vanetza)
