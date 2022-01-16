// speed_limit_detection_node.cpp
// Zeus Polanco Salgado
// January 2021

#include "speed_limit_detection.h"

#include <ros/ros.h>
#include <std_msgs/>
#include <sensor_msgs/Image.h>
#include <perception_msgs/Frame.h>
#include <perception_msgs/ObjectList.h>
#include <perception_msgs/Object.h>
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
    ROS_INFO("Working on frame: [%d]", msg.id);
    int numOfObjects = msg.objects.size();
    int boxes[numOfObjects][4];
    Mat frameImage;
    perception_msgs::Frame updatedFrame = msg;
    for (int i = 0; i < numOfObjects; i++){
      boxes[i][0] = msg.objects[i].x; boxes[i][1] = msg.objects[i].y;
      boxes[i][2] = msg.objects[i].h; boxes[i][3] = msg.objects[i].w;
    }

    // convert image to opencv image and send
    frameImage = ROSToCV(msg->image);
    results =  detectSpeedLimit(frameImage, boxes);
    for (int i = 0; i < numOfObjects; i++){
      updatedFrame.objects[i].x = results[0];
      updatedFrame.objects[i].y = results[1];
      updatedFrame.objects[i].h = results[2];
      updatedFrame.objects[i].w = results[3];
    }
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
