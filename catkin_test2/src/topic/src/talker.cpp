#include <ros/ros.h>
#include <topic/gps.h>

int main(int argc,char** argv){
	ros::init(argc,argv,"talker");
	ros::NodeHandle nh;

	topic::gps msg;
	msg.data[0] = 1.0;
	msg.data[1] = 1.0;
	msg.state = "working";

	ros::Publisher pub = nh.advertise<topic::gps>("gps_info",1);
	
	ros::Rate loop_rate(1.0);
	while(ros::ok()){
		msg.data[0] = msg.data[0] * 1.02;
		msg.data[1] = msg.data[1] * 1.01;
		ROS_INFO("Talker:GPS_info x = %f  y = %f",msg.data[0],msg.data[1]);
		pub.publish(msg);
		loop_rate.sleep();
	}

	return 0;
}
