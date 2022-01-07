// speed_limit_detection_node.cpp
// Zeus Polanco Salgado
// January 2021

#include "speed_limit_detection.h"

#include <ros/ros.h>
#include <std_msgs/>
#include <sensor_msgs/Image.h>
#include <bulldog_msgs/Frame.h>
#include <bulldog_msgs/Object.h>
#include <opencv2/opencv.hpp>

class Node{
public:
  Node(){
    pub = n.advertise<Frame>("/updated_speed_limit_frames", 1);
    sub = n.subscribe("frames", 1000, callback);
  }

  // Input: Frame messages coming from "frames/"
  // Output: No returns. Publishes updated Frame with speed limit sign values
  // Callback function for "frames/". TODO
  void callback(const bulldog_msgs::Frame& msg){
    ROS_INFO("Working on frame: [%d]", msg->id);
    int numOfObjects = msg.objects.size();
    bulldog_msgs::Frame updatedFrame;
    bulldog_msgs::Object objects[numOfObjects];
    int objectBoundingBoxes[][];
    int speedLimitValues[numOfObjects];
    // build Frame with updated speedlimitsigns
    for (int i = 0; i < numOfObjects; i++){
      // set bounding box values
      objectBoundingBoxes = [];
    }
    speedLimitValues =  detectSpeedLimit(frameImage, objectBoundingBoxes);
    updatedFrame.objects = objects;
    // publish updated sign
    pub.publish(updatedFrame);
  }

private:
  ros::NodeHandle n;
  ros::Subscriber sub;
  ros::Publisher pub;
};
// End of node class

int main(int argc, char **argv){
    ros::init(argc, argv, "speed_limit_detection");
    // update speed limit message
    // publish updated speed limit sign objects
    Node nodeObject;
    ros::spin();
    return 0;
}
