#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <path_planning/rrt.h>
#include <path_planning/obstacles.h>
#include <geometry_msgs/Point.h>

#include <iostream>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>



int main(int argc,char** argv)
{
    //initializing ROS
    ros::init(argc,argv,"env_node");
	ros::NodeHandle n;

	//defining Publisher
	ros::Publisher env_publisher = n.advertise<visualization_msgs::Marker>("path_planner_rrt",1);

	//defining markers
    visualization_msgs::Marker boundary;
    visualization_msgs::Marker obstacle;

    initializeMarkers(boundary, obstacle);

    //initializing rrtTree
    rrt::RRT myRRT(2.0,2.0);
    int goalX, goalY;
    goalX = goalY = 95;

    boundary.points = initializeBoundary();
    obstacle.points = initializeObstacles();

    env_publisher.publish(boundary);
    env_publisher.publish(obstacle);

    while(ros::ok())
    {
        env_publisher.publish(boundary);
        env_publisher.publish(obstacle);
        ros::spinOnce();
        ros::Duration(1).sleep();
    }
	return 1;
}
