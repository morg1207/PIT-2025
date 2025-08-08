cmake_minimum_required(VERSION 3.0.2)
project(service_package)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES service_package
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

add_executable(nodo_cliente_spawn src/cliente.cpp)
target_link_libraries(nodo_cliente_spawn ${catkin_LIBRARIES})

add_executable(nodo_servidor_parabola src/servidor.cpp)
target_link_libraries(nodo_servidor_parabola ${catkin_LIBRARIES})

add_executable(nodo_cliente_parabola src/cliente_parabola.cpp)
target_link_libraries(nodo_cliente_parabola ${catkin_LIBRARIES})

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

