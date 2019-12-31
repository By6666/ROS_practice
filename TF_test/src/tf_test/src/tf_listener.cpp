#include <geometry_msgs/PointStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <ros/ros.h>
#include <tf/transform_datatypes.h>
#include <tf/transform_listener.h>

void FrameTF();

void transformPoint(const tf::TransformListener &listener) {
  // we'll create a point in the base_laser frame that we'd like to transform to
  // the base_link frame
  geometry_msgs::PointStamped laser_point;
  laser_point.header.frame_id = "base_laser";

  // we'll just use the most recent transform available for our simple example
  laser_point.header.stamp = ros::Time();

  // just an arbitrary point in space
  laser_point.point.x = 1.0;
  laser_point.point.y = 0.2;
  laser_point.point.z = 0.0;

  try {
    geometry_msgs::PointStamped base_point;
    listener.transformPoint("base_link", laser_point, base_point);

    ROS_INFO(
        "base_laser: (%.2f, %.2f. %.2f) -----> base_link: (%.2f, %.2f, "
        "%.2f) at time %.2f",
        laser_point.point.x, laser_point.point.y, laser_point.point.z,
        base_point.point.x, base_point.point.y, base_point.point.z,
        base_point.header.stamp.toSec());
  } catch (tf::TransformException &ex) {
    ROS_ERROR(
        "Received an exception trying to transform a point from "
        "\"base_laser\" to \"base_link\": %s",
        ex.what());
  }
}

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "tf_listener");
  ros::NodeHandle n;

  // 最大存储保留时间
  tf::TransformListener listener(ros::Duration(10));

  // callback 频率
  ros::Timer timer = n.createTimer(
      ros::Duration(1.0), boost::bind(&transformPoint, boost::ref(listener)));

  while (1) {
    // ros::spinOnce();

    FrameTF();

    ros::Duration(1.5).sleep();
  }

  return 0;
}

void FrameTF() {
  tf::TransformListener listener;
  tf::StampedTransform to_laser;
  tf::StampedTransform laser_to;

  try {
    listener.waitForTransform("/base_link", "/base_laser", ros::Time(0),
                              ros::Duration(1.0));  //等待一秒钟
    listener.lookupTransform("/base_link", "/base_laser", ros::Time(0),
                             laser_to);
    listener.lookupTransform("/base_laser", "/base_link", ros::Time(0),
                             to_laser);
  } catch (tf::TransformException ex) {
    ROS_ERROR("%s", ex.what());
    ros::Duration(0.5).sleep();
  }

  geometry_msgs::PoseStamped laser_point;
  laser_point.header.frame_id = "base_laser";

  // we'll just use the most recent transform available for our simple example
  laser_point.header.stamp = ros::Time();

  static tf::Transform tf_;
  tf_.setOrigin(tf::Vector3(1.0, 0.2, 0.2));

  tf::poseTFToMsg(to_laser * tf_, laser_point.pose);

  ROS_INFO("another way transform:  base_link: (%.2f, %.2f, %.2f) ",
           laser_point.pose.position.x, laser_point.pose.position.y,
           laser_point.pose.position.z);
}