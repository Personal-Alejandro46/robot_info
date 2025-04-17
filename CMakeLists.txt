cmake_minimum_required(VERSION 3.0.2)
project(robot_info)


find_package(catkin REQUIRED COMPONENTS
  robotinfo_msgs
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS roscpp robotinfo_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_dependencies(robot_info_node robotinfo_msgs_generate_messages_cpp)

## Declare a C++ library
add_library(${PROJECT_NAME}
  src/robot_info_class.cpp
)

add_executable(robot_info_node 
src/robot_info_class.cpp
src/robot_info_main.cpp
)

target_link_libraries(robot_info_node
  ${catkin_LIBRARIES}
)



# target_link_libraries(robot_info_node ${catkin_LIBRARIES} ${PROJECT_NAME})


