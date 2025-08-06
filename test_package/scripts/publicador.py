#!/usr/bin/env python3
# license removed for brevity
import rospy
from geometry_msgs.msg import Twist
def talker():
    pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    rospy.init_node('publicador_python', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    msg_cmd_vel = Twist() 
    msg_cmd_vel.linear.x = 0.5
    msg_cmd_vel.angular.z = 0.5;
    while not rospy.is_shutdown():
        
        pub.publish(msg_cmd_vel)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
