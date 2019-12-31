#!/usr/bin/env python3

import rospy
from std_msgs.msg import String
from py_topic_test.msg import simple

def talker():
    rospy.init_node('py_talker', anonymous=True)
    pub = rospy.Publisher('chatter', simple, queue_size=10)

    rate = rospy.Rate(10)
    buff = simple()

    while not rospy.is_shutdown():
        # hello_str = "hello world %s" % rospy.get_time()
        buff.a = buff.a + 0.02
        buff.state = "yes"
        pub.publish(buff)
        rospy.loginfo("sending....")
        rate.sleep()

if __name__ == '__main__':

    try:
        talker()
    except rospy.ROSInterruptException:
        pass

