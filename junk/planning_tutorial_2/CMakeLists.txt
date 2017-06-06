cmake_minimum_required(VERSION 2.8.3)
project(planning_tutorial)

## Add support for C++11, supported in ROS Kinetic and newer
# add_definitions(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  moveit_core
  moveit_ros_planning
  moveit_ros_planning_interface
  geometric_shapes
  moveit_visual_tools
)

catkin_package(
  CATKIN_DEPENDS
  moveit_core
  moveit_ros_planning_interface
  interactive_markers
#  INCLUDE_DIRS include
#  LIBRARIES planning_tutorial
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(group_interface src/plan_interface.cpp)
target_link_libraries(group_interface ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(group_interface ${catkin_EXPORTED_TARGETS})

add_executable(sia_motion src/motoman_motion.cpp)
target_link_libraries(sia_motion ${catkin_LIBRARIES} ${Boost_LIBRARIES})
add_dependencies(sia_motion ${catkin_EXPORTED_TARGETS})