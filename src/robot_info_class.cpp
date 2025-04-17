#pragma once
#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>

class RobotInfo
{
public:
  RobotInfo(){};
  RobotInfo(ros::NodeHandle *node_handle);
  virtual ~RobotInfo() {}
  virtual void publish_data();
protected:
  ros::NodeHandle *nh_;
  ros::Publisher robot_info_pub_;

  std::string robot_description_;
  std::string serial_number_;
  std::string ip_address_;
  std::string firmware_version_;
};
