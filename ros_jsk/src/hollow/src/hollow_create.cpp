#include <jsk_recognition_msgs/BoundingBox.h>
#include <jsk_recognition_msgs/BoundingBoxArray.h>
#include <ros/ros.h>
#include <tf/tf.h>

#include <iostream>

int main(int argc, char** argv) {
  ros::init(argc, argv, "hollow_create");

  ros::NodeHandle nh;
  ros::Publisher pub =
      nh.advertise<jsk_recognition_msgs::BoundingBoxArray>("boxes", 1);

  jsk_recognition_msgs::BoundingBox box_temp;
  jsk_recognition_msgs::BoundingBoxArray boxes;

  box_temp.header.frame_id = "global";

  box_temp.dimensions.x = 10.0;
  box_temp.dimensions.y = 10.0;
  box_temp.dimensions.z = 1.0;

  box_temp.pose.position.x = 15.0;
  box_temp.pose.position.y = 15.0;
  box_temp.pose.position.z = 0.0;

  boxes.header.frame_id = "global";

  for (int i = 0; i < 10; ++i) {
    box_temp.label = i;
    box_temp.pose.orientation = tf::createQuaternionMsgFromYaw(0.2 * i);

    boxes.boxes.push_back(box_temp);
  }

  while (ros::ok()) {
    pub.publish(boxes);
    std::cout << "publish !!" << std::endl;
    ros::Duration(1).sleep();
  }

  return 0;
}