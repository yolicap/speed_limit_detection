cmake_minimum_required(VERSION 2.8.3)
project(speed_limit_detection)
find_package(catkin REQUIRED COMPONENTS nodelet)
catkin_package(
   INCLUDE_DIRS include
   LIBRARIES ${PROJECT_NAME}
   CATKIN_DEPENDS roscpp nodelet
   DEPENDS eigen opencv)
