#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Pose.h>
#include <cmath>
#include "iostream"

turtlesim::Pose current_pose;

void poseCallback(const turtlesim::Pose::ConstPtr& msg) {
    current_pose = *msg;
    
}


int main(int argc, char **argv) {

    ros::init(argc, argv, "turtle_parabola");
    ros::NodeHandle nh;

    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Subscriber pose_sub = nh.subscribe("/turtle1/pose", 10, poseCallback);

    ros::Rate rate(10);
    geometry_msgs::Twist vel_msg;

    // Parámetros de la parábola (y = a*x^2)
    double a = 1;  // Ajusta esto para cambiar la "curva" de la parábola
    double x_start = 5.0;
    double x_end = 10.0;

    ROS_INFO("Iniciando trayectoria parabólica...");

    while (ros::ok() && current_pose.x <= x_end) {
        // Calcular la pendiente (derivada de y = a*x² => dy/dx = 2*a*x)
        double slope = 2.0 * a * current_pose.x;

        // Calcular el ángulo deseado (tangente inversa de la pendiente)
        double desired_angle = atan(slope);

        // Error angular (diferencia entre el ángulo deseado y el actual)
        double angle_error = desired_angle - current_pose.theta;

        // Control proporcional para la rotación (ajusta la ganancia 1.5 según necesidad)
        vel_msg.angular.z = 1.5 * angle_error;

        // Velocidad lineal constante (ajusta el valor 1.0 para más rapidez/lentitud)
        vel_msg.linear.x = 1.0;
        ROS_INFO("Posición actual de la tortuga: x = [ %.3f] y= [ %.3f]", current_pose.x, current_pose.theta);
        vel_pub.publish(vel_msg);
        ros::spinOnce();
        rate.sleep();
    }

    ROS_INFO("Trayectoria completada.");
    return 0;
}