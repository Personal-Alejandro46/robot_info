#include "robot_info/agv_robot_info_class.h"
#include "robot_info/hydraulic_system_monitor.h"

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *node_handle) : RobotInfo(node_handle) 
{
    robot_description_ = "Mir100";
    serial_number_ = "567A359";
    ip_address_ = "169.254.5.180";
    firmware_version_ = "3.5.8";
    maximum_payload_ = "100";
}

void AGVRobotInfo::publish_data()
{
    robotinfo_msgs::RobotInfo10Fields msg;

    msg.data_field_01 = "robot_description: " + robot_description_;
    msg.data_field_02 = "serial_number: " + serial_number_;
    msg.data_field_03 = "ip_address: " + ip_address_;
    msg.data_field_04 = "firmware_version: " + firmware_version_;
    msg.data_field_05 = "maximum_payload: " + maximum_payload_ + "kg";
    msg.data_field_06 = "hydraulic_oil_temperature: " + hydraulic_monitor_.getHydraulicOilTemperature();
    msg.data_field_07 = "hydraulic_oil_tank_fill_level: " + hydraulic_monitor_.getHydraulicOilTankFillLevel();
    msg.data_field_08 = "hydraulic_oil_pressure: " + hydraulic_monitor_.getHydraulicOilPressure();
    msg.data_field_09 = "";
    msg.data_field_10 = "";
    robot_info_pub_.publish(msg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "agv_robot_info_node");
    ros::NodeHandle nh;

    AGVRobotInfo agv_info = AGVRobotInfo(&nh);

    ros::Rate rate(1);
    while (ros::ok()){
        agv_info.publish_data();
        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}