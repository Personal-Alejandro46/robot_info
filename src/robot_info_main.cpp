#include "robot_info_class.hpp"

RobotInfo::RobotInfo(ros::NodeHandle *node_handle)
{
  nh_ = node_handle;
  robot_info_pub_ = nh_.advertise<robotinfo_msgs::RobotInfo>("robot_info", 10);
  robot_description_ = "Mir100";
  serial_number_ = "567A359";
  ip_address_ = "169.254.5.180";
  firmware_version_ = "3.5.8";
}

void RobotInfo::publish_data()
{
  robotinfo_msgs::RobotInfo msg;

  msg.data_field_01 = "robot_description: " + robot_description_;
  msg.data_field_02 = "serial_number: " + serial_number_;
  msg.data_field_03 = "ip_address: " + ip_address_;
  msg.data_field_04 = "firmware_version: " + firmware_version_;
  msg.data_field_05 = "";
  msg.data_field_06 = "";
  msg.data_field_07 = "";
  msg.data_field_08 = "";
  msg.data_field_09 = "";
  msg.data_field_10 = "";

  robot_info_pub_.publish(msg);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "robot_info_node");
  ros::NodeHandle nh;
  RobotInfo robot_info = RobotManagerBase(&nh);
  robot_info.publish_data();
  ros::spin();
}
