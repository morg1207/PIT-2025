cmake_minimum_required(VERSION 3.0.2)
project(test_package)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  #std_msgs
)


catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_package
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

add_executable(nodo_publicador src/publicador.cpp)
target_link_libraries(nodo_publicador ${catkin_LIBRARIES})

add_executable(nodo_suscriptor src/suscriptor.cpp)
target_link_libraries(nodo_suscriptor ${catkin_LIBRARIES})

add_executable(nodo_parabola src/pub_sub.cpp)
target_link_libraries(nodo_parabola ${catkin_LIBRARIES})

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

