#include <ros/ros.h>
#include <topic_test/gps.h>

void callback(const topic_test::gps& msg) {
  ROS_INFO("Dis= %f   state = %s", (msg.pos.x + msg.pos.y), msg.state.c_str());
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("gps_info", 1, callback);
  ros::spin();
  return 0;
}