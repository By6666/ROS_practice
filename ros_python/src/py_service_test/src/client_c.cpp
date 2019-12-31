#include <py_service_test/simple.h>
#include <ros/ros.h>

#include <iostream>

int main(int argc, char** argv) {
  ros::init(argc, argv, "client_c");
  ros::NodeHandle n("~path_o");
  ros::ServiceClient client =
      n.serviceClient<py_service_test::simple>("sum_service");

  py_service_test::simple cli;
  cli.request.a = 25;
  cli.request.b = 24;

  ros::Rate loop_rate(1);
  while(!client.waitForExistence());
  while (ros::ok()) {
    if (client.call(cli)) {
      ROS_INFO("Feedback from server: %f", cli.response.sum);
    } else {
      ROS_ERROR("Failed to call service greetings.");
      return 1;
    }
    loop_rate.sleep();
  }
  return 0;

  return 0;
}