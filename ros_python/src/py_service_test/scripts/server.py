#!/usr/bin/env python3

import rospy
from py_service_test.srv import simple
from py_service_test.srv import simpleResponse

def handelclient(req):
    print ("receive REQ %f + %f", (req.a, req.b))
    return simpleResponse(req.a + req.b)

def server_func():
    rospy.init_node("sum_server")
    s = rospy.Service("client_c/path_o/sum_service", simple, handelclient)
    print("waiting for req")
    s.spin()


if __name__ == "__main__":
    server_func()

