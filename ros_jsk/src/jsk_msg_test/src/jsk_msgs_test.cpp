#include <geometry_msgs/PolygonStamped.h>
#include <jsk_recognition_msgs/BoundingBox.h>
#include <jsk_recognition_msgs/PolygonArray.h>
#include <ros/ros.h>
#include <tf/tf.h>

#include <iostream>

int main(int argc, char** argv) {
  ros::init(argc, argv, "ros_jsk_msg_test");
  ros::NodeHandle nh;

  ros::Publisher pub =
      nh.advertise<jsk_recognition_msgs::BoundingBox>("jsk_Box", 1, true);

  ros::Publisher pub_poly =
      nh.advertise<jsk_recognition_msgs::PolygonArray>("jsk_poly", 1, true);

  double yaw = 0.0;
  ros::Rate loop_rate(100);

  jsk_recognition_msgs::BoundingBox box;
  box.header.frame_id = "global";

  box.pose.position.x = 10.0;
  box.pose.position.y = 10.0;
  box.pose.position.z = 0.0;

  box.pose.orientation = tf::createQuaternionMsgFromYaw(yaw);

  box.dimensions.x = 10.0;
  box.dimensions.y = 10.0;
  box.dimensions.z = 0.1;

  geometry_msgs::PolygonStamped poly_geo;
  poly_geo.header.frame_id = "global";
  geometry_msgs::Point32 temp;
  temp.x = 0.0;
  temp.y = 0.0;
  temp.z = 0.0;
  poly_geo.polygon.points.push_back(temp);
  temp.x = 50.0;
  temp.y = 0.0;
  temp.z = 0.0;
  poly_geo.polygon.points.push_back(temp);
  temp.x = 50.0;
  temp.y = 50.0;
  temp.z = 0.0;
  poly_geo.polygon.points.push_back(temp);

  jsk_recognition_msgs::PolygonArray poly;
  poly.header.frame_id = "global";
  poly.polygons.push_back(poly_geo);

  while (ros::ok()) {
    yaw += 0.01;
    box.pose.orientation = tf::createQuaternionMsgFromYaw(yaw);

    box.pose.position.x = 10.0 * cos(yaw);
    box.pose.position.y = 10.0 * sin(yaw);

    pub.publish(box);

    pub_poly.publish(poly);

    loop_rate.sleep();
  }

  return 0;
}