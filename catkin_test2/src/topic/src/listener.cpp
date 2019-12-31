#include <ros/ros.h>
#include <topic/gps.h>
#include <std_msgs/Float64.h>


void info_deal(const topic::gps::ConstPtr& msg){
	std_msgs::Float64 dis;
	dis.data = sqrt(pow(msg->data[0],2)+pow(msg->data[1],2));
	ROS_INFO("lisenter: the dis = %f, state = %s",dis.data,msg->state.c_str());
}


int main(int argc,char** argv){
	ros::init(argc,argv,"listener");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("gps_info",1,info_deal);
	ros::spin();
	return 0;
}
