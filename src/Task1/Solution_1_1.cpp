#include "ros/ros.h"
#include "std_msgs/Int64.h"

void callback(const std_msgs::Int64::ConstPtr& msg) {
    ROS_INFO("Received: %ld", msg->data);
    std::cout << "cout print: " << msg->data << std::endl;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "kuihong");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("prep_topic", 1, callback);
    ros::spin();
    return 0;
}
