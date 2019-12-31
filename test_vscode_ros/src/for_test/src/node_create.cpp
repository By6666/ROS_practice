#include <ros/ros.h>
#include <std_msgs/Int64.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "node_create");
  ros::NodeHandle n1("sub1");
  ros::NodeHandle n2("sub2");

  ros::Publisher pub = n1.advertise<std_msgs::Int64>("sub1_topic", 1);

  ros::Rate loop(0.5);

  std_msgs::Int64 cnt;
  cnt.data = 0;
  while (ros::ok()) {
    ROS_INFO("sub1 send %d", cnt);
    pub.publish(cnt);
    ++cnt.data;
    loop.sleep();
  }

  return 0;
}