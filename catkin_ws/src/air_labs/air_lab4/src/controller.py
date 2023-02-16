#!/usr/bin/env python3

import rospy
import std_msgs.msg
from geometry_msgs.msg import Twist, Point
from nav_msgs.msg import Odometry, Path
import tf
import nav_msgs.msg 
import geometry_msgs.msg
import nav_msgs.srv
from sensor_msgs.msg import LaserScan
from math import pow, atan2, sqrt, degrees
from geometry_msgs.msg import PoseStamped, PoseArray, Quaternion
from tf.transformations import euler_from_quaternion, quaternion_from_euler
import numpy
import csv


x = 0.0
y = 0.0
theta = 0.0
DATA_PATH = '/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab4/q_table/'

class controller():
    
    def __init__(self):
        self.readQTable(DATA_PATH + '/Qtable.csv')

    
    
    def readQTable(self, fileName):
        qTable = []
        q = {}
        mydict = {y[0]: y[1] for y in [x.split(")") for x in open(fileName).read().split('\n') if x]}
        for key, value in mydict.items():
            val = (key[2:7], key[10:11],  value[1:])
            qTable.append(val)
        #print(qTable)
        #res = map(max(), qTable[2])
        print(qTable)


# def newOdom(msg):
#     global x
#     global y
#     global theta

#     x = msg.pose.pose.position.x
#     y = msg.pose.pose.position.y

#     orientation_q = msg.pose.pose.orientation
#     orientation_list = [ orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
#     (roll, pitch, theta) = euler_from_quaternion(orientation_list)

# rospy.init_node("speed_controller")
# sub = rospy.Subscriber('odometry', Odometry, newOdom)
# pub = rospy.Publisher('cmd_vel', Twist, queue_size = 1)
# to_vel_ctrl_pub = rospy.Publisher("to_vel_control", std_msgs.msg.Empty, queue_size = 1)

# speed = Twist()
# r = rospy.Rate(4)
# goal = Point()
# goal.x= 5
# goal.y= 5

# while not rospy.is_shutdown():

#     inc_x = goal.x - x
#     inc_y = goal.y - y
#     angle_to_goal = atan2(inc_y, inc_x)
#     print(angle_to_goal)
    
#     if abs(angle_to_goal - theta) > 0.1:
#         speed.linear.x = 0.0
#         speed.angular.z = 0.3
#     else:
#         speed.linear.x = 0.5
#         speed.angular.z = 0.0
    
#     to_vel_ctrl_pub.publish(std_msgs.msg.Empty())
#     pub.publish(speed)
#     r.sleep()

if __name__ == '__main__':
    rospy.init_node('controller', anonymous=False)
    ec = controller()
    rospy.spin()