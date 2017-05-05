#include "ros/ros.h"
#include "moveit/move_group_interface/move_group.h"
#include "moveit/planning_scene_interface/planning_scene_interface.h"
#include "moveit_msgs/DisplayTrajectory.h"
//#include "moveit_msgs/ExecuteTrajectoryGoal.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "plan_interface");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();
    
  moveit::planning_interface::MoveGroup group("sia5");
  group.setPlannerId("RTTConnectkConfigDefault");
  
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  
  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("move_group/display_planned_path", 1, true);
  moveit_msgs::DisplayTrajectory display_trajectory;
  
  geometry_msgs::Pose target_pose1 = group.getCurrentPose("").pose;
  //target_pose1.orientation.w -= 0.1;
  target_pose1.position.z -= 0.5;
  //target_pose1.position.y -= -0.1;
  //target_pose1.position.z -= 0.1;
  
  group.setPoseTarget(target_pose1);
  
  moveit::planning_interface::MoveGroup::Plan my_plan;
  group.plan(my_plan);
  //group.move();
  sleep(1);
  group.execute(my_plan);
  sleep(3);
  
  //target_pose1 = group.getCurrentPose("").pose;
  //target_pose1.orientation.w -= 0.1;
  target_pose1.position.y += 0.25;
  target_pose1.position.z += 0.25;
  //target_pose1.position.z -= 0.1;
  
  group.setPoseTarget(target_pose1);
  
  //moveit::planning_interface::MoveGroup::Plan my_plan;01
  group.plan(my_plan);
  sleep(1);
  group.execute(my_plan);
  sleep(3);
  //group.move();
  
  //sleep(3);
  
  //target_pose1 = group.getCurrentPose("").pose;
  //target_pose1.orientation.w -= 0.1;
  target_pose1.position.y -= 0.25;
  target_pose1.position.z += 0.25;
  //target_pose1.position.z -= 0.1;
  
  group.setPoseTarget(target_pose1);
  
  //moveit::planning_interface::MoveGroup::Plan my_plan;
  group.plan(my_plan);
  sleep(1);
  group.execute(my_plan);
  
  //group.move();
  //ROS_INFO("Visualizing pose goal %s", success?"":"NOPE!");
  
  ros::shutdown();
  return 0;
}