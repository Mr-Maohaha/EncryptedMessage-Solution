#include "ros/ros.h"
#include "std_msgs/Int64.h"
#include "prep_pkg/preparationMessage.h"

ros::Publisher pub;

void callback(const std_msgs::Int64::ConstPtr& msg) {
    prep_pkg::preparationMessage pubMsg;
    if (msg->data % 2 == 0) {
        pubMsg.txt = "the number is even";
    } else {
        pubMsg.txt = "the number is odd";
    }
    pubMsg.value = msg->data;
    pub.publish(pubMsg);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "kuihong");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("prep_topic", 1, callback);
    pub = n.advertise<prep_pkg::preparationMessage>("prepMsg", 1);
    ros::spin();
    return 0;
}
