#include "robot_info_class.cpp"
#include "ros/init.h"
#include "ros/rate.h"

RobotInfo::RobotInfo(ros::NodeHandle *node_handle) {
  robot_description_ = "Mir100";
  serial_number_ = "567A359";
  ip_address_ = "169.254.5.180";
  firmware_version_ = "3.5.8";
}

void RobotInfo::publish_data() {
  robotinfo_msgs::RobotInfo10Fields msg;

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
  RobotInfo robot_info = RobotInfo(&nh);

  ros::Rate rate(1.0);
  while (ros::ok()){
    robot_info.publish_data();
    ros::spinOnce();
    rate.sleep(); 
  }
  
  return 0;
}
