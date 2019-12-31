#include <ros/ros.h>
#include <service_test/Greeting.h>

int main(int argc,char** argv){
	ros::init(argc,argv,"greetings_client");
	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<service_test::Greeting>("greetings");

	service_test::Greeting cli;
	cli.request.name = "By";
	cli.request.age  = 24;
	
	ros::Rate loop_rate(1);
	while(ros::ok()){
		if(client.call(cli)){
			ROS_INFO("Feedback from server: %s", cli.response.feedback.c_str());
		}
		else{
			ROS_ERROR("Failed to call service greetings.");
			return 1;
		}
		loop_rate.sleep();
	}
	return 0;
}
