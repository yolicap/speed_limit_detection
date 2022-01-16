cmake_minimum_required(VERSION 2.8.3)
project(speed_limit_detection)
add_compile_options(--std=c++11 $(pkg-config --libs --cflags opencv4))
find_package(catkin REQUIRED COMPONENTS
  roscpp
  cv_bridge
  std_msgs
  sensor_msgs
  perception_msgs
)

catkin_package(
   LIBRARIES ${PROJECT_NAME}
   CATKIN_DEPENDS roscpp cv_bridge std_msgs sensor_msgs perception_msgs opencv
   DEPENDS opencv)
