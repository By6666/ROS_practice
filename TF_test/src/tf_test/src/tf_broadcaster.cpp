#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "tf_publisher");
  ros::NodeHandle nh;

  ros::Rate r(100);

  tf::TransformBroadcaster broadcaster;
  tf::Quaternion q;
  q.setRPY(0, 0, 0);

  while (ros::ok()) {
    // 父坐标系转换到子坐标系的 位移 和 旋转
    broadcaster.sendTransform(
        tf::StampedTransform(tf::Transform(q, tf::Vector3(0.0, 0.0, 0.2)),
                             ros::Time::now(), "base_link", "base_laser"));
    r.sleep();
  }

  return 0;
}
