#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <sstream>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  // Objete que me permite manejar el nodo
  ros::NodeHandle n;
  //creo un objeto publicador y lo enlazo con el nodo
  ros::Publisher pub_cmd_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

  //crear un objeto para controlar la frecuencia de publicación
  ros::Rate loop_rate(10);

  geometry_msgs::Twist msg_cmd_vel;
  msg_cmd_vel.angular.z = 0.5;
  msg_cmd_vel.linear.x = 0.5;
  while (ros::ok())
  {

    pub_cmd_vel.publish(msg_cmd_vel);
    ROS_INFO("Enviando comando de velocidad : x [%.3f]  angular [%.3f]", 
      msg_cmd_vel.linear.x, msg_cmd_vel.angular.z);
    loop_rate.sleep();
  }

  return 0;
}