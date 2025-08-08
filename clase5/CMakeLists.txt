cmake_minimum_required(VERSION 3.0.2)
project(clase5)

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
#  LIBRARIES clase5
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

add_executable(nodo_cliente src/cliente.cpp)
target_link_libraries(nodo_cliente ${catkin_LIBRARIES})

add_executable(nodo_servidor src/servidor.cpp)
target_link_libraries(nodo_servidor ${catkin_LIBRARIES})


add_executable(nodo_parabola_service src/parabola_service.cpp)
target_link_libraries(nodo_parabola_service ${catkin_LIBRARIES})

add_executable(nodo_parabola_cliente src/parabola_cliente.cpp)
target_link_libraries(nodo_parabola_cliente ${catkin_LIBRARIES})

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


