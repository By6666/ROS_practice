#include <ros/ros.h>
#include <topic_test/gps.h>
#include <iostream>

void ConnectCallback(const ros::SingleSubscriberPublisher& pub) {
  //   ROS_INFO("\n ********** Connect Sucessful *********\n");
  std::cout << "********** Connect Sucessful *********" << std::endl;
}

void DisonnectCallback(const ros::SingleSubscriberPublisher& pub) {
  //   ROS_INFO("\n ********** Connect fail *********\n");
  std::cout << "********** Connect fail *********" << std::endl;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "talker");
  ros::NodeHandle nh;
  ros::NodeHandle n2("~");


  topic_test::gps msg;

  msg.pos.x = 1.0;
  msg.pos.y = 1.0;
  msg.state = "working";

  ros::Publisher pub = nh.advertise<topic_test::gps>(
      "gps_info", 1, ConnectCallback, DisonnectCallback);

  ros::Rate loop_rate(1.0);
  int send_fre = 0;

  while (ros::ok()) {
    msg.pos.x *= 1.0001;
    msg.pos.y *= 1.0001;
    n2.param<int>("send_fre", send_fre, 0);
    ROS_INFO("Talker:GPS:x = %f  y = %f, state = %s, send_fre=%d", msg.pos.x,
             msg.pos.y, msg.state.c_str(), send_fre);

    pub.publish(msg);
    loop_rate.sleep();
  }

  return 0;
}