#include <geometry_msgs/Point.h>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "rivz_shape");
  ros::NodeHandle nh;
  ros::Rate loop_rate(2);
  ros::Publisher marker_pub =
      nh.advertise<visualization_msgs::Marker>("Marker_msg", 1);

  uint8_t shape = 2;
  double x_step = 0, y_step = 0;

  visualization_msgs::Marker lines;
  lines.header.frame_id = "frame_nm";
  lines.header.stamp = ros::Time::now();
  lines.ns = "rivz_shape";
  lines.id = 2;

  lines.type = 4;
  lines.action = visualization_msgs::Marker::ADD;

  lines.scale.x = 0.1;
  // lines.scale.y = 0.5;
  // lines.scale.z = 1;

  lines.color.r = 1.0;
  lines.color.a = 1.0;

  geometry_msgs::Point point_temp;
  point_temp.x = 0;
  point_temp.y = 0;
  lines.points.push_back(point_temp);

  point_temp.x = 10;
  point_temp.y = 0;
  lines.points.push_back(point_temp);

  point_temp.x = 10;
  point_temp.y = 10;
  lines.points.push_back(point_temp);

  point_temp.x = 0;
  point_temp.y = 10;
  lines.points.push_back(point_temp);

  point_temp.x = 0;
  point_temp.y = 0;
  lines.points.push_back(point_temp);

  while (ros::ok()) {
    marker_pub.publish(lines);
    // visualization_msgs::Marker marker;
    // marker.header.frame_id = "/frame_nm";
    // marker.header.stamp = ros::Time::now();

    // marker.ns = "rivz_shape";
    // marker.id = 1;

    // marker.type = shape;
    // marker.action = visualization_msgs::Marker::ADD;

    // marker.pose.position.x = x_step;
    // marker.pose.position.y = y_step;
    // marker.pose.position.z = 0;
    // marker.pose.orientation.x = 0.0;
    // marker.pose.orientation.y = 0.0;
    // marker.pose.orientation.z = 0.0;
    // marker.pose.orientation.w = 1.0;

    // marker.scale.x = 1.0;
    // marker.scale.y = 1.0;
    // marker.scale.z = 1.0;

    // marker.color.r = 0.0f;
    // marker.color.g = 1.0f;
    // marker.color.b = 0.0f;
    // marker.color.a = 1.0;

    // marker.lifetime = ros::Duration();

    // while (marker_pub.getNumSubscribers() < 1) {
    //   if (!ros::ok()) {
    //     return 0;
    //   }
    //   ROS_WARN_ONCE("Please create a subscriber to the marker");
    //   sleep(1);
    // }
    // marker_pub.publish(marker);
    // x_step += 0.05;
    // y_step += 0.05;

    // shape = shape + 1;
    // if (shape > 3) shape = 0;
    loop_rate.sleep();
  }
  return 0;
}
