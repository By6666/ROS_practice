#!/usr/bin/env python3

import rospy
from std_msgs.msg import String
from py_topic_test.msg import simple


def callback(data):
    # rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    rospy.loginfo("state: %s,  sum = %f", data.state, data.a)

def listener():
    rospy.init_node('py_listener', anonymous=True)
    rospy.Subscriber('chatter', simple, callback)

    rospy.spin()


if __name__ == '__main__':
    listener()