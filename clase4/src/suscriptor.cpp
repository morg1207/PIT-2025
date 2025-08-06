#include "iostream"
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <cmath>

void callback(const turtlesim::Pose::ConstPtr& msg) {
    // This callback can be used to process the turtle's pose if needed
    ROS_INFO("Current Pose - x: [%f], y: [%f], theta: [%f]", msg->x, msg->y, msg->theta);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "turtle_mover");
    ros::NodeHandle nh;

    ros::Subscriber pos_sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 10, callback);
    ros::spin();
    return 0;
}