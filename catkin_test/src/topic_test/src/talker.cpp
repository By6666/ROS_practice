#include <ros/ros.h>
#include <topic_test/gps.h>

int main(int argc,char** argv){
	ros::init(argc,argv,"talker");//解析参数，命名节点
	ros::NodeHandle nh;//创建句柄，实例化node
	topic_test::gps msg;
	msg.x = 1.0;
	msg.y = 1.0;
	msg.state = "working";
	ros::Publisher pub = nh.advertise<topic_test::gps>("gps_info",1);//创建publisher
	ros::Rate loop_rate(100.0);//定义循环发布频率
	while(ros::ok()){
		msg.x = 1.03 * msg.x;
		msg.y = 1.01 * msg.y;
		ROS_INFO("Talker:GPS:x = %f  y = %f", msg.x,msg.y);
		pub.publish(msg);
		loop_rate.sleep();
	}
	return 0;
}
