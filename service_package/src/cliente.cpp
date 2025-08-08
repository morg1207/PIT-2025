#include "ros/ros.h"
#include "turtlesim/Spawn.h"


int main(int argc, char** argv) {
    ros::init(argc, argv, "spawn_turtles_client");
    ros::NodeHandle nh;

    ros::ServiceClient spawn_client = nh.serviceClient<turtlesim::Spawn>("spawn");

    turtlesim::Spawn srv_spawn;

    srv_spawn.request.name = "turtle_pit";
    srv_spawn.request.x = 0.8;
    srv_spawn.request.y = 0.8;
    srv_spawn.request.theta = 4.8;
    
    if(spawn_client.call(srv_spawn)){
        ROS_INFO("La llamada al servicio fue exitoso");
        ROS_INFO("La tortuga insertada es [%s] ", srv_spawn.response.name.c_str());
    }
    else{
        ROS_ERROR("La llamada al servicio fue erronea");
    }


    return 0;
}