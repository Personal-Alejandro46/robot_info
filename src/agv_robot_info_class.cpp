#include "robot_info_class.cpp"
#include "ros/init.h"
#include "ros/rate.h"

class AGVRobotInfo: public RobotInfo {   
    public:
        AGVRobotInfo(ros::NodeHandle *node_handle) : RobotInfo(node_handle) {
            nh_ = node_handle;
            robot_info_pub_ = nh_->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 10);
            robot_description_ = "Mir100";
            serial_number_ = "567A359";
            ip_address_ = "169.254.5.180";
            firmware_version_ = "3.5.8";
            maximum_payload_ = "100";
        }

        void publish_data()
        {
            robotinfo_msgs::RobotInfo10Fields msg;

            msg.data_field_01 = "robot_description: " + robot_description_;
            msg.data_field_02 = "serial_number: " + serial_number_;
            msg.data_field_03 = "ip_address: " + ip_address_;
            msg.data_field_04 = "firmware_version: " + firmware_version_;
            msg.data_field_05 = "maximum_payload: " + maximum_payload_+"kg";
            msg.data_field_06 = "";
            msg.data_field_07 = "";
            msg.data_field_08 = "";
            msg.data_field_09 = "";
            msg.data_field_10 = "";
            robot_info_pub_.publish(msg);
        }
        ~AGVRobotInfo() {}
    protected:
   std::string maximum_payload_;
};

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