#include <ros/ros.h>
#include <topic_test/gps.h>
#include <std_msgs/Float32.h>

void gpsCallback(const topic_test::gpsConstPtr& msg){
	std_msgs::Float32 distence;
	distence.data = sqrt(pow(msg->x,2) + pow(msg->y,2));
	ROS_INFO("Listener:Distence to orign = %f   state = %s",distence.data,msg->state.c_str());
}


int main(int argc,char** argv){
	ros::init(argc,argv,"listener");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("gps_info",1,gpsCallback);//创建subscriber
	ros::spin();//反复调用回调函数
	return 0;
}
