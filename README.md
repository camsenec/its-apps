# ITS Applications (its_apps)
ITS applications transform data included in V2X messages and publish to ROS2 topics shared with the autonomous vehicle's core process. 

Supported applications are
- CA (Cooperative Awareness)
- DEN (Decentralized Environment Notification) \[**Under development**\]
- RLT (Road and Lane Topology) \[**Under development**\]
- TLM (Traffic Light Maneuver) \[**Under development**\]

## Prerequisites
- CMake 3.5 or higher
- Vanetza 0.8 (https://www.vanetza.org)
- ROS2 (https://docs.ros.org/)

## Getting started
Supported ROS2 version: Galactic (https://docs.ros.org/en/galactic/index.html)
1. build packages
```bash
source /opt/ros/$ROS_DISTRO/setup.bash
colcon build
```

2. launch its_apps
```bash
ros2 launch its_apps its_apps_launch.py 
```
## Usage
1. Connect to self-driving system through ROS bridge
2. Subscribe to the topics from the self-driving system created by its_apps 

## Parameters
Options of Vanetza (https://www.vanetza.org) are inherited.
Values can be configured through [launch file](https://github.com/camsenec/its_apps/blob/master/its_apps/launch/its_apps_launch.py). 
| parameter | default value | possible values | description|
|:---------:|:-------------:|:---------:|:-------------:|
| link-layer | ethernet | ethernet, cohda, udp | link layer type |
| interface  | vboxnet0 | \<string\> | network interface name to receive messages |
| require-gnss-fix | False | True, False | enable/disable gnss fix |
| print-rx | False | True, False | enable/disable printing of received messages content
| positioning | static | gpsd, static | positioning provider |
| latitude | 48.7668616 | \<double\> (-90-90)  | latitude when the positioning provider is `static` |
| longitude | 11.423068  |\<double\> (-180-180) | longitude when the positioning provider is `static` |
| pos_confidence | 5.0  | \<double\> (0-100) | (100 - x)% circular confidence when the positioning provider is `static` | 
| security | dummy | none, dummy, certs | security provider |
| certificate |""| \<string\> | path to certificate file when the security provider is `certs`
| certificate-key |""| \<string\> | path to private key file when the security provider is `certs`

## Architecture
its_apps is assumed to be deployed at OBU. The IDS/IPS ([mitvane](https://github.com/camsenec/mitvane) is optional. When mitvane is deployed, the source interface should be the destination interface of Mitvane. When mitvane is not deployed, the source interface should be the interface which captures V2X messages. 

<img src=https://mitvane.s3.eu-north-1.amazonaws.com/its_apps.png>

## Output
Other topics such as `/denm_basic`, `/map_basic`, `/spat_basic` would be added.                     
Besides, advanced topics like /traffic_light_state (can be extracted from SPAT message) would be supported.
| topic | description |
|:---------:|:-------------:|
|/cam_basic| include basic information extracted from CAM |

## Sample output
```
$ ros2 topic echo /cam_basic 
station_id: 1
generation_time: 60335
station_type: 5
latitude: 487668620
longitude: 114320680
---
station_id: 1
generation_time: 60335
station_type: 5
latitude: 487668620
longitude: 114320680
---
```

