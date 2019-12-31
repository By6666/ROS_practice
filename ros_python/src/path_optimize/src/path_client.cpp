#include <path_optimize/PathFitInfo.h>
#include <ros/ros.h>

#include <iostream>
#include <vector>

int main(int argc, char** argv) {
  ros::init(argc, argv, "path_client");
  ros::NodeHandle n;
  ros::ServiceClient client =
      n.serviceClient<path_optimize::PathFitInfo>("path_optimize_service");

  // float path[] = {0,       0,        0,         2.87979, 0,        0,
  //                 5.75959, 0,        0,         8.63116, 0.188213, 0.1309,
  //                 11.4536, 0.749632, 0.261799,  14.2353, 1.49498,  0.261799,
  //                 16.9603, 2.42,     0.392699,  19.6853, 3.34501,  0.261799,
  //                 22.5077, 3.90643,  0.1309,    25.3793, 4.09465,  0,
  //                 28.2509, 3.90643,  -0.1309,   31.0733, 3.34501,  -0.261799,
  //                 33.8958, 2.7836,   -0.1309,   36.7509, 2.40771,  -0.1309,
  //                 39.5734, 1.84629,  -0.261799, 42.3958, 1.28487,  -0.1309,
  //                 45.251,  0.908981, -0.1309,   48.1061, 0.533092, -0.1309,
  //                 50,      0,        0};

  float path[] = {-0.00184402, 0.000210953, 0.52523,   2.57704,   1.27721,
                  0.39433,     5.30055,     2.20667,   0.26343,   8.12207,
                  2.77269,     0.132531,    10.9933,   2.96559,   0.00163087,
                  13.8652,     2.78206,     -0.129269, 16.721,    2.41083,
                  -0.129269,   19.5443,     1.85401,   -0.260169, 22.3677,
                  1.2972,      -0.129269,   25.2235,   0.925965,  -0.129269,
                  28.0792,     0.554733,    -0.129269, 30.9511,   0.371204,
                  0.00163087,  32.1135,     -0.32356,  0.0275739};
  path_optimize::PathFitInfo cli;
  cli.request.fit_degree = 3;
  cli.request.path_seg_num = 6;
  cli.request.path_resolution = 20;
  cli.request.prime_path = std::vector<float>(path, path + 39);

  ros::Rate loop_rate(10);
  while (!client.waitForExistence()) {
  };
  ros::WallTime start = ros::WallTime::now();

  while (ros::ok()) {
    if (client.call(cli)) {
      std::cout << "final_path size : " << cli.response.final_path.size()
                << std::endl;
      for (auto& elem : cli.response.final_path) std::cout << elem << "  ";
      std::cout << std::endl;
      break;
    }
    loop_rate.sleep();
  }
  ros::WallTime end = ros::WallTime::now();

  std::cout << "spend time: " << (end - start).toSec() * 1000 << " ms"
            << std::endl;
  return 0;
}