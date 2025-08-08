#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include <string>

int main(int argc, char** argv) {
    ros::init(argc, argv, "nodo_parametros");
    ros::NodeHandle nh;

    std::string topic_name = "turtle";
    float vel_max = 0.2;
    
    if(!nh.getParam("topic_name_param", topic_name)){

        ROS_WARN("El parametro topic_name_param no se encuentra en el servidor, se usara el valor por defecto");
    }

    if(!nh.getParam("vel_max_param", vel_max)){

        ROS_WARN("El parametro vel_max_param no se encuentra en el servidor, se usara el valor por defecto");
    }

    ros::Publisher pub_cmd_vel = nh.advertise<geometry_msgs::Twist>(topic_name, 1);
    
    geometry_msgs::Twist msg_cmd_vel;
    msg_cmd_vel.angular.z = vel_max;
    msg_cmd_vel.linear.x = vel_max;
    
    ros::Rate rate(20);
    while(ros::ok()){

        pub_cmd_vel.publish(msg_cmd_vel);
        ROS_INFO("Enviando comando de velocidad : x [%.3f]  angular [%.3f]", 
        msg_cmd_vel.linear.x, msg_cmd_vel.angular.z);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}


    







