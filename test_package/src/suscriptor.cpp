#include "ros/ros.h"
#include "turtlesim/Pose.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void Callback(const turtlesim::Pose::ConstPtr& msg)
{
  ROS_INFO("La posición actual de la tortuga es x [%.3f]  y [%.3f]  ángulo [%.3f]", msg->x,msg->y,msg->theta);
}

int main(int argc, char **argv)
{
  //inicializo el nodo
  ros::init(argc, argv, "node_suscriptor");

  //creo un manejador del nodo
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe<turtlesim::Pose>("/turtle1/pose", 2 , Callback);
  
  ros::spin();

  return 0;
}