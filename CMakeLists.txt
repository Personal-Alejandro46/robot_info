cmake_minimum_required(VERSION 3.0.2)
project(robot_info)


find_package(catkin REQUIRED COMPONENTS
  robotinfo_msgs
  std_msgs
  roscpp
)

catkin_package(
  CATKIN_DEPENDS roscpp robotinfo_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(robot_info_node 
	src/robot_info_class.cpp
	src/robot_info_main.cpp
)

add_executable(agv_robot_info_node 
	src/agv_robot_info_class.cpp
	src/robot_info_class.cpp
)

add_dependencies(robot_info_node 
	${${PROJECT_NAME}_EXPORTED_TARGETS} 
	${catkin_EXPORTED_TARGETS}
)

add_dependencies(agv_robot_info_node 
	${${PROJECT_NAME}_EXPORTED_TARGETS} 
	${catkin_EXPORTED_TARGETS}
)

target_link_libraries(robot_info_node
  ${catkin_LIBRARIES}
)

target_link_libraries(agv_robot_info_node
  ${catkin_LIBRARIES}
)


