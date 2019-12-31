#!/usr/bin/env python3
import rospy

from path_optimize.srv import PathFitInfo
from path_optimize.srv import PathFitInfoResponse

from pathfit import optimize_path

def handelclient(rq):
    print("**** receive Request !! ****\n")
    return PathFitInfoResponse(
        optimize_path(rq.fit_degree, rq.path_seg_num, rq.prime_path,
                rq.path_resolution))


def server_func():
    rospy.init_node("path_optimize_server")
    s = rospy.Service("path_optimize_service", PathFitInfo, handelclient)
    print("waiting for req ...")
    s.spin()


if __name__ == "__main__":
    server_func()