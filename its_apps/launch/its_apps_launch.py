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

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="its_apps",
            executable="its_apps_node",
            name="its_apps_node",
            output="screen",
            emulate_tty=True,
            parameters=[
                {
                    "link-layer": "ethernet",
                    "interface": "vboxnet0",
                    "require-gnss-fix": False,
                    "print-rx": False,
                    #"applications": ("ca", "den", "spat", "map"),
                    "positioning": "static",
                    "latitude": 48.7668616,
                    "longitude": 11.423068,
                    "pos_confidence": 5.0,
                    "security": "dummy",
                    "certificate": "",
                    "certificate-key": "",
                    #"certificate-chain": ()
                }
            ]
        )
    ])
