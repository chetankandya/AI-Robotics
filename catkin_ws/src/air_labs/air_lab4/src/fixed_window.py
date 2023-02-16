#!/usr/bin/env python3

import nav_msgs.srv
import std_msgs.msg
import time
import rospy
import TstML
import tf
import geometry_msgs.msg 
import nav_msgs.msg
from math import *
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
import sensor_msgs.msg
import numpy as np


MAX_LIDAR_DISTANCE = 5.0
COLLISION_DISTANCE = 0.5 # LaserScan.range_min = 0.1199999
NEARBY_DISTANCE = 2.0

ZONE_0_LENGTH = 0.4
ZONE_1_LENGTH = 0.7

ANGLE_MAX = 181 - 1
ANGLE_MIN = 1 - 1
HORIZON_WIDTH = 90

class fixed_window():
    def __init__(self):
        self.map_request = rospy.ServiceProxy('map_request', nav_msgs.srv.GetMap)
        self.to_waypoint_ctrl_pub = rospy.Publisher("to_waypoints_control", std_msgs.msg.Empty, queue_size = 1)
        self.to_position_ctrl_pub = rospy.Publisher("to_position_control",std_msgs.msg.Empty,queue_size = 1)
        self.cmd_position_pub = rospy.Publisher("cmd_position", geometry_msgs.msg.PoseStamped, queue_size = 1)
        
        self.velocity_pub =  rospy.Publisher("max_velocity", geometry_msgs.msg.Twist, queue_size = 1)
        self.position_reached_sub = rospy.Subscriber('position_reached', std_msgs.msg.Empty, self.position_reached_callback)
        self.destination_pub = rospy.Publisher('destination', geometry_msgs.msg.PoseStamped, queue_size = 1)
        self.cmd_velocity_pub =  rospy.Publisher('cmd_vel', geometry_msgs.msg.Twist, queue_size = 1)
        self.to_vel_ctrl_pub = rospy.Publisher("to_vel_control", std_msgs.msg.Empty, queue_size = 1)
        self.execute()
        
    def execute(self):

        while not rospy.is_shutdown():
            
            rospy.Time(1.0)
            action = 0
            msg = rospy.wait_for_message('lidar', LaserScan)
            print(msg)
        
            ( lidar, angles ) = self.lidarScan(msg)
            action = self.discretize(lidar)
            self.perform_action(action)
    
    def discretize(self, lidar):

        length = len(lidar)
        index = int(length/3)

        left = (lidar[0:index]  == MAX_LIDAR_DISTANCE).sum()
        straight = (lidar[index:2*index] == MAX_LIDAR_DISTANCE).sum()
        right = (lidar[2*index:length] == MAX_LIDAR_DISTANCE).sum()

        if (lidar == MAX_LIDAR_DISTANCE).sum() == length:
            action = 0
        elif (straight > left and straight > right) or (straight > left and straight == right) or (straight == left and straight > right):
            action = 0
        elif (left > straight and left > right) or ( left > straight and straight == right):
            action = 1
        elif right > left and right > straight or ( right > straight and straight == left):
            action = 2
        else:
            action = 3

        print("straight ", straight)
        print("left ", left)
        print("right ", right)
        return action

    # o = front, 1 = left, 2 = right and 3 = reverse
    def perform_action(self, action):
        linear_x = 0
        angular_z = 0
        state_description = ""
        linear_speed = 2.1
        angular_speed = 0.7
        
        if action == 0:
            state_description = 'case 1 - no obstacle ahead'
            linear_x = linear_speed
            angular_z = 0.2
        elif action == 1:
            state_description = 'case 2 - Obstacle at stright and right, going left'
            linear_x = 0.2
            angular_z = -angular_speed
        elif action == 2:
            state_description = 'case 3 - Obstacle at stright and left, going right'
            linear_x = 0
            angular_z = angular_speed
        elif action == 3:  #removed this action to make the lerning proces faster
            state_description = 'case 4 - Obstacle at stright and left and right, going back'
            linear_x = 0
            angular_z = angular_speed
      
        print("================")
        print(state_description)
        print(action)
        self.to_vel_ctrl_pub.publish(std_msgs.msg.Empty())
        self.publishVel(linear_x, angular_z)


    def publishVel(self, linear_x, angular_z):
        m = Twist()
        self.to_vel_ctrl_pub.publish(std_msgs.msg.Empty())
        m.linear.x = linear_x
        m.angular.z = angular_z
        self.cmd_velocity_pub.publish(m)

    
    def lidarScan(self, msgScan):
        distances = np.array([])
        angles = np.array([])

        for i in range(len(msgScan.ranges)):
            angle = degrees(i * msgScan.angle_increment)
            if ( msgScan.ranges[i] > MAX_LIDAR_DISTANCE ) or (np.isnan(msgScan.ranges[i])):
                distance = MAX_LIDAR_DISTANCE
            elif ( msgScan.ranges[i] < msgScan.range_min ):
                distance = msgScan.range_min
                # For real robot - protection
                if msgScan.ranges[i] < 0.01:
                    distance = MAX_LIDAR_DISTANCE
            else:
                distance = msgScan.ranges[i]

            distances = np.append(distances, distance)
            angles = np.append(angles, angle)

        # distances in [m], angles in [degrees]
        return ( distances, angles )
    
    def position_reached_callback(self, req):
        self.executionFinished(TstML.Executor.ExecutionStatus.Finished())
        self.position_reached_sub.unregister()
        self.waypoints_finished_sub.unregister() 

if __name__ == '__main__':
    rospy.init_node('fixed_window', anonymous=False)
    ec = fixed_window()
    rospy.spin()
