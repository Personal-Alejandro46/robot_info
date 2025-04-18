#pragma once
#include "robot_info/robot_info_class.h"
#include <ros/ros.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>

class AGVRobotInfo: public RobotInfo {
public:
    AGVRobotInfo(ros::NodeHandle *node_handle);
    void publish_data() override;
    ~AGVRobotInfo() {}
protected:
    std::string maximum_payload_;
};