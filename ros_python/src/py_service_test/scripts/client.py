#!/usr/bin/env python3

import sys
import rospy
from py_service_test.srv import simple, simpleRequest


def client_function(x, y):
    rospy.wait_for_service('sum_service')
    cli = rospy.ServiceProxy('sum_service', simple)
    try:
        resp1 = cli.call(simpleRequest(x, y))
        return resp1.sum
    except rospy.ServiceException as exc:
        print("Service did not process request: " + str(exc))


def usage():
    return "%s [x y]"%sys.argv[0]


if __name__ == "__main__":
    x = 4
    y = 5
    while True:
        print("Requesting %f+%f", (x, y))
        print("%f + %f = %f" %(x,y,client_function(x,y)))
        
