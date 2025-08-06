#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
#include <cmath>

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */

float pose_x = 0.0;
float pose_y = 0.0;
float pose_theta = 0.0;

void Callback(const turtlesim::Pose::ConstPtr& msg)
{
  pose_x = msg->x;
  pose_y = msg->y;
  pose_theta = msg->theta;
  ROS_INFO("La posicion actual de la tortuga es x [%.3f]  y [%.3f]  ángulo [%.3f]", msg->x,msg->y,msg->theta);
}

int main(int argc, char **argv)
{
  //inicializo el nodo
  ros::init(argc, argv, "nodo_parabola");

  //creo un manejador del nodo
  ros::NodeHandle n;
  
  ros::Publisher pub_cmd_vel = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
  ros::Subscriber sub_pose = n.subscribe<turtlesim::Pose>("/turtle1/pose", 1 , Callback);


  geometry_msgs::Twist msg_cmd_vel;
  msg_cmd_vel.angular.z = 0.0;
  msg_cmd_vel.linear.x = 0.0;

  //parametros de mi parabola
  double x_start = 5.0;
  double x_end = 8.0;
  double a = 0.2;  
  ROS_INFO("Iniciando trayectoria parabólica...");

  ros::Rate rate(20);

  while(ros::ok() && pose_x <= x_end){
     
    double pendiente = 2.0 * a * pose_x;
    double  angulo_deseado = atan(pendiente);
    double error = angulo_deseado - pose_theta;
    
    msg_cmd_vel.angular.z = 1.5 * error;
    msg_cmd_vel.linear.x = 1.5;

    pub_cmd_vel.publish(msg_cmd_vel);
    ROS_INFO("Enviando comando de velocidad : x [%.3f]  angular [%.3f]", 
      msg_cmd_vel.linear.x, msg_cmd_vel.angular.z);
    ros::spinOnce();
    rate.sleep();
  }

  return 0;
}
