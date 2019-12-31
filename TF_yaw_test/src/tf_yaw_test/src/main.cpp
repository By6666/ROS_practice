#include "geometry_msgs/Pose.h"
#include "ros/ros.h"
#include "tf/tf.h"
#include "tf/tfMessage.h"

#include <iostream>

inline double TranformYawRange(double yaw) {
  while (yaw > M_PI) yaw -= 2.0 * M_PI;
  while (yaw < -M_PI) yaw += 2.0 * M_PI;

  return yaw;
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "tf_yaw_test");

  double yaw = 0.0, delta_yaw = 0.0;

  while (1) {
    std::cout << "Please input a yaw : ";
    std::cin >> yaw;
    delta_yaw = yaw;

    tf::Quaternion qua;
    geometry_msgs::Quaternion qua_g;
    qua = tf::createQuaternionFromYaw(yaw);
    qua_g = tf::createQuaternionMsgFromYaw(yaw);

    std::cout << tf::getYaw(qua) << "  " << tf::getYaw(qua_g) << std::endl;

    std::cout << TranformYawRange(delta_yaw) << std::endl;
  }
}