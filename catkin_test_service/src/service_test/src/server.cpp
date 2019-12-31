#include <ros/ros.h>
#include <service_test/Greeting.h>


bool handle_func(service_test::Greeting::Request& req, service_test::Greeting::Response& res){
	ROS_INFO("Request from %s with age %d",req.name.c_str(),req.age);
	res.feedback = "Hi, " + req.name + ", I'm server !";
	return true;
}

int main(int argc,char** argv){
	ros::init(argc,argv,"greetings_server");
	ros::NodeHandle nh;
	ros::ServiceServer service = nh.advertiseService("greetings",handle_func);
	ros::spin();
	return 0;
}
