#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "geometry_msgs/Twist.h"
#include "std_srvs/Trigger.h"

#include <cmath>

float pose_x = 0.0;
float pose_y = 0.0;
float pose_theta = 0.0;
ros::Publisher pub_cmd_vel;


bool flag_suscriptor=false;
void poseCallback(const turtlesim::Pose::ConstPtr& msg)
{
  if(!flag_suscriptor){
    return;
  }
  pose_x = msg->x;
  pose_y = msg->y;
  pose_theta = msg->theta;
  ROS_INFO("Posición actual: x=%.2f, y=%.2f, ángulo=%.2f", pose_x, pose_y, pose_theta);
}

bool dibujarParabolaCallback(std_srvs::Trigger::Request &req,
                     std_srvs::Trigger::Response &res)
{ 
  flag_suscriptor = true;
  //llamar al servicio de reinicio de tortuga

  ROS_INFO("Recibida solicitud para dibujar parábola");
  
  // Parámetros de la parábola (y = a*x^2)
  const double x_start = 2.0;
  const double x_end = 8.0;
  const double a = 0.2;
  const double velocidad_lineal = 1.0;
  const double ganancia_angular = 1.5;

  geometry_msgs::Twist msg_cmd_vel;
  msg_cmd_vel.angular.z = 0.0;
  msg_cmd_vel.linear.x = 0.0;

  // Publicar cero primero para detener cualquier movimiento previo
  pub_cmd_vel.publish(msg_cmd_vel);
  //ros::spinOnce();

  ros::Duration(0.5).sleep(); // Pequeña pausa

  ROS_INFO("Iniciando trayectoria parabólica...");
  
  ros::Rate rate(20); // 20 Hz
  bool success = true;

  while(ros::ok() && pose_x <= x_end)
  {
    double pendiente = 2.0 * a * pose_x;
    double angulo_deseado = atan(pendiente);
    double error = angulo_deseado - pose_theta;
    
    msg_cmd_vel.angular.z = ganancia_angular * error;
    msg_cmd_vel.linear.x = velocidad_lineal;

    pub_cmd_vel.publish(msg_cmd_vel);
    
    ROS_INFO("Comando: velocidad=%.2f, angular=%.2f", 
             msg_cmd_vel.linear.x, msg_cmd_vel.angular.z);
    
    ros::spinOnce();
    rate.sleep();
  }

  // Detener la tortuga al finalizar
  msg_cmd_vel.linear.x = 0.0;
  msg_cmd_vel.angular.z = 0.0;
  pub_cmd_vel.publish(msg_cmd_vel);

  // se ha concluido con la tarea del servicio

  res.success = true;
  res.message = "Trayectoria parabólica completada";

  ROS_INFO("Trayectoria parabólica completada");

  

  //reinicio variables
  flag_suscriptor =false;
  pose_x = 0.0;
  pose_y = 0.0;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sevidor_servicio_parabola");
  ros::NodeHandle nh;

  // Publicador cmd_vel
  pub_cmd_vel = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

  ros::Subscriber sub_pose = nh.subscribe("/turtle1/pose", 1, poseCallback);

  // Servicio
  ros::ServiceServer service = nh.advertiseService<std_srvs::Trigger::Request, std_srvs::Trigger::Response>("/dibujar_parabola", dibujarParabolaCallback);
  
  ROS_INFO("Servicio listo para dibujar parabolas.");

  ros::spin();

  return 0;
}