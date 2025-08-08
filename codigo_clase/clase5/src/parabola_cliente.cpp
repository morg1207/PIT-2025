#include "ros/ros.h"
#include "std_srvs/Trigger.h"
#include "std_srvs/Empty.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "cliente_parabola_reset");
    ros::NodeHandle nh;

    // Crear clientes para ambos servicios
    ros::ServiceClient reset_client = nh.serviceClient<std_srvs::Empty>("/reset");
    ros::ServiceClient parabola_client = nh.serviceClient<std_srvs::Trigger>("/dibujar_parabola");

    ROS_INFO("Esperando a que los servicios estén disponibles...");
    
    // Esperar a que ambos servicios estén disponibles
    if (!reset_client.waitForExistence(ros::Duration(5.0))) {
        ROS_ERROR("Servicio /reset no disponible después de 5 segundos");
        return 1;
    }
    
    if (!parabola_client.waitForExistence(ros::Duration(5.0))) {
        ROS_ERROR("Servicio /dibujar_parabola no disponible después de 5 segundos");
        return 1;
    }

    ROS_INFO("Iniciando secuencia de dibujo de parábola...");

    // 1. Llamar al servicio de reset
    std_srvs::Empty reset_srv;
    if (reset_client.call(reset_srv)) {
        ROS_INFO("Tortuga reseteada exitosamente");
        
        // Esperar 1 segundo para que complete el reset
        ros::Duration(1.0).sleep();
        
        // 2. Llamar al servicio de parábola
        std_srvs::Trigger parabola_srv;
        if (parabola_client.call(parabola_srv)) {
            if (parabola_srv.response.success) {
                ROS_INFO("Parábola dibujada: %s", parabola_srv.response.message.c_str());
            } else {
                ROS_WARN("Problema al dibujar parábola: %s", parabola_srv.response.message.c_str());
            }
        } else {
            ROS_ERROR("Fallo al llamar al servicio /dibujar_parabola");
            return 1;
        }
    } else {
        ROS_ERROR("Fallo al llamar al servicio /reset");
        return 1;
    }

    return 0;
}