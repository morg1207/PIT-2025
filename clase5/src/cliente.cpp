#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "spawn_turtles_client");
    ros::NodeHandle nh;

    // Esperar a que el servicio esté disponible
    ros::service::waitForService("spawn");
    
    // Crear un cliente para el servicio de spawn

    ros::ServiceClient spawnClient = nh.serviceClient<turtlesim::Spawn>("spawn");
    // Posiciones donde queremos spawnear las tortugas
    std::vector<std::pair<float, float>> positions = {
        {1.0, 1.0},
        {2.0, 2.0},
        {3.0, 3.0},
        {4.0, 4.0},
        {5.0, 5.0}
    };

    // Spawnear cada tortuga
    for (size_t i = 0; i < positions.size(); ++i) {
        turtlesim::Spawn srv;
        srv.request.x = positions[i].first;
        srv.request.y = positions[i].second;
        srv.request.theta = 0.0;  // Orientación (0 mira hacia la derecha)
        
        // Nombre opcional (turtle1, turtle2, etc. son los nombres por defecto)
        // srv.request.name = "turtle" + std::to_string(i+2);

        if (spawnClient.call(srv)) {
            ROS_INFO("Spawned turtle at (%.1f, %.1f)", positions[i].first, positions[i].second);
        } else {
            ROS_ERROR("Failed to call service spawn for turtle at (%.1f, %.1f)", 
                     positions[i].first, positions[i].second);
        }
    }

    return 0;
}