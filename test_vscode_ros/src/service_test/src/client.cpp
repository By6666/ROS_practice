#include <ros/ros.h>
#include <service_test/Greeting.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "greet_client");
  ros::NodeHandle nh;

  ros::ServiceClient client =
      nh.serviceClient<service_test::GreetingRequest,
                       service_test::GreetingResponse>("greeting");

  service_test::Greeting cli;
  cli.request.name = "By";
  cli.request.age = 24;

  ros::Rate loop_rate(1);

  while (ros::ok()) {
    if (client.call(cli.request, cli.response)) {
      ROS_INFO("Feedback from server: %s   state: %s",
               cli.response.fadeback.c_str(), cli.response.state.state.c_str());
    } else {
      ROS_INFO("Failed to call service greetings.");
    }
    loop_rate.sleep();
  }

  return 0;
}
