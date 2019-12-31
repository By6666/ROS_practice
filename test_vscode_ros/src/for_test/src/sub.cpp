#include <ros/ros.h>
#include <std_msgs/Int64.h>

void callback(const std_msgs::Int64& msg) {
  ROS_INFO("receive %d", msg.data);
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "lis");
  ros::NodeHandle  n1("sub1");

  ros::Subscriber sub = n1.subscribe("sub1_topic", 1, callback);
  ros::spin();
  return 0;
}