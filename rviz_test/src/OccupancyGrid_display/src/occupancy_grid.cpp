#include <nav_msgs/OccupancyGrid.h>
#include <ros/ros.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "OccupancyGridDisplay");

  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<nav_msgs::OccupancyGrid>("OGD", 1);

  ros::Rate loop_rate(1);

  nav_msgs::OccupancyGrid map;
  map.header.frame_id = "cost_map";
  map.header.stamp = ros::Time::now();
  map.header.seq = 0;

  map.info.height = 20;
  map.info.width = 70;
  map.info.resolution = 2.0;
  map.info.origin.position.x = 0;
  map.info.origin.position.y = 0;
  map.info.origin.position.z = 0;

    for (int i = 0; i < map.info.height; ++i) {
      for (int j = 0; j < map.info.width; ++j) {
        map.data.push_back(0);
      }
    }
    map.data[2] = 10;
    map.data[2*70 + 1] = 50;

  while (ros::ok()) {
    pub.publish(map);
    loop_rate.sleep();
  }

  ros::shutdown();

  return 0;
}