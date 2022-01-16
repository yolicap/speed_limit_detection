# speed_limit_detection
ROS which extracts value from speed limit sign. Input: image, speed limit bounding box. Output: Value of sign
Keep in mind that this repository is in package format. Ready to pull into a catkin workspace.

# Current State:
#### Runs: 🏃 Compiles: ✅ Complete: ✔️ Incomplete: ❌ Empty: ❗️
### speed_limit_detection.launch ❗️
TODO
Create main launch instructions with the following argument:
- frame topic
- image only mode

### speed_limit_detection_node.cpp ✔️
Requires Testing!
### speed_limit_detection.cpp ✔️
Requires Testing!
### speed_limit_detection.h ✔️
Requires Testing!
### CMakeLists.txt ❌
Working on it
### package.xml ✔️
### README.md ❌
Working on it

# Dependencies:
TODO
WAITING ON MESSAGE PACKAGE!
- [tesseract](https://github.com/tesseract-ocr/tesseract)
  - sudo apt install tesseract-ocr-eng libtesseract4 libtesseract-dev
- [opencv2](https://github.com/opencv/opencv)
- leptonica
- sensor_msgs
  - sudo apt install ros-sensor-msgs
- cv_bridge

# Installations:
TODO
