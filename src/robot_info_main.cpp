#include "ros/ros.h"
#include "robot_info/robot_info_class.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "robot_info_node");
    ros::NodeHandle nh;

    RobotInfo robot_info(&nh);

    ros::Rate rate(1);
    while (ros::ok())
    {
        robot_info.publish_data();
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}