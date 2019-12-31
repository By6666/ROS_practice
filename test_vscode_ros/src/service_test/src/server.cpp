#include <ros/ros.h>
#include <service_test/Greeting.h>

bool handle_func(service_test::GreetingRequest& req,
                 service_test::GreetingResponse& rep) {
  ROS_INFO("Request from %s with age %d", req.name.c_str(), req.age);
  rep.fadeback = "Hi, " + req.name + ", I'm server!";
  rep.state.state = "working";
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "server");
  ros::NodeHandle nh;

  ros::ServiceServer service =
      nh.advertiseService<service_test::GreetingRequest,
                          service_test::GreetingResponse>("greeting",
                                                          handle_func);

  ros::spin();

  return 0;
}