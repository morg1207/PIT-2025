#include "iostream"
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>


int main(int argc, char **argv) {
    ros::init(argc, argv, "turtle_mover");
    ros::NodeHandle nh;

    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate rate(10);
    geometry_msgs::Twist vel_msg;

    ROS_INFO("Starting turtle movement...");

    while (ros::ok()) {
        // Set a constant linear velocity
        vel_msg.linear.x = 2.0;  // Adjust speed as needed
        vel_msg.angular.z = 0.0; // No rotation

        vel_pub.publish(vel_msg);
        rate.sleep();
    }

    return 0;
}