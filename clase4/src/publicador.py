import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist


def main():
    rospy.init_node('publicador', anonymous=True)
    

    # Create a publisher for Twist messages
    pub_twist = rospy.Publisher('cmd_vel', Twist, queue_size=10)
    
    rate = rospy.Rate(10)  # 10 Hz
    
    while not rospy.is_shutdown():

        # Publish a Twist message
        twist_msg = Twist()
        twist_msg.linear.x = 1.0
        twist_msg.angular.z = 0.5
        pub_twist.publish(twist_msg)
        
        rate.sleep()