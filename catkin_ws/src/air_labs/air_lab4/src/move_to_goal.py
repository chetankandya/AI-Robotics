#!/usr/bin/env python3

import rospy
import time
import std_msgs.msg
from geometry_msgs.msg import Twist
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
from fixed_window import fixed_window
 
 
x = 0.0
y = 0.0
theta = 0.0
distance_tolerance = 0.1
goal_x = 0.0
goal_y = 0.0

MAX_LIDAR_DISTANCE = 8.0
COLLISION_DISTANCE = 0.5
NEARBY_DISTANCE = 1

ZONE_0_LENGTH = 0.4
ZONE_1_LENGTH = 0.7

ANGLE_MAX = 181 - 1
ANGLE_MIN = 1 - 1
HORIZON_WIDTH = 90

class move_to_goal():
   
    def __init__(self):
  
        self.destinationSub = rospy.Subscriber('destination', geometry_msgs.msg.PoseStamped, self.updateGoal)
        self.pose_subscriber = rospy.Subscriber('odometry', Odometry, self.update_pose)
        
        self.cmd_velocity_pub =  rospy.Publisher('cmd_vel', geometry_msgs.msg.Twist, queue_size = 1)
        self.to_vel_ctrl_pub = rospy.Publisher("to_vel_control", std_msgs.msg.Empty, queue_size = 1)
 
        self.pose = Odometry()
        self.rate = rospy.Rate(3)

    def getPosition(self, odomMsg):
        x = odomMsg.pose.position.x
        y = odomMsg.pose.position.y
        return ( x , y)

    def getRotation(self, odomMsg):
        orientation_q = odomMsg.pose.orientation
        orientation_list = [ orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
        (roll, pitch, yaw) = euler_from_quaternion(orientation_list)
        return yaw

    def update_pose(self, msg):
        """Callback function which is called when a new message of type Pose is received by the subscriber."""
        global x
        global y
        global theta

        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y

        orientation_q = msg.pose.pose.orientation
        orientation_list = [ orientation_q.x, orientation_q.y, orientation_q.z, orientation_q.w]
        (roll, pitch, theta) = euler_from_quaternion(orientation_list)

  
    def euclidean_distance(self):
        """Euclidean distance between current pose and the goal."""
        return sqrt(pow((goal_x - x), 2) + pow((goal_y - y), 2))
    
    def publishVel(self, linear_x, angular_z):
        self.to_vel_ctrl_pub.publish(std_msgs.msg.Empty())
        m = Twist()
        m.linear.x = linear_x
        m.angular.z = angular_z
        self.cmd_velocity_pub.publish(m)

    def updateGoal(self, goal_pose):
        global goal_x 
        global goal_y 

        goal_x = goal_pose.pose.position.x
        goal_y = goal_pose.pose.position.y
        print(goal_x)
        print(goal_y)
 
        self.move2goal()

    def avoidObstacle(self, lid):
        
        #t_end = time.time() + 30
        #time.time() < t_end:
        print("Found Obstacle")
        obstacle_near = self.checkObstacleNearBy(lid)
        goal_near = self.checkGoalNearBy()
        while (obstacle_near) and (not goal_near):
            print("inside while")
            msg = rospy.wait_for_message('lidar', LaserScan)
            ( lidar, angles ) = fixed_window.lidarScan(self, msg)
            obstacle_near = self.checkObstacleNearBy(lidar)
            goal_near = self.checkGoalNearBy()
            action = fixed_window.discretize(self, lidar)
            self.perform_action(action)
        
        self.publishVel(0, 0)
    
    def avoidDynamicObstacles(self, lid):
        
        #t_end = time.time() + 30
        #time.time() < t_end:
        print("Found Obstacle")
        inc_x = goal_x - x
        inc_y = goal_y - y

        angle_to_goal = degrees(atan2(inc_y, inc_x))
        print(angle_to_goal)
        input()
        obstacle_near = self.checkObstacleNearBy(lid)
        goal_near = self.checkGoalNearBy()
        # while (obstacle_near) and (not goal_near):
        #     print("inside while")
        #     msg = rospy.wait_for_message('lidar', LaserScan)
        #     ( lidar, angles ) = fixed_window.lidarScan(self, msg)
        #     obstacle_near = self.checkObstacleNearBy(lidar)
        #     goal_near = self.checkGoalNearBy()
        #     action = fixed_window.discretize(self, lidar)
        #     self.perform_action(action)
        
        # self.publishVel(0, 0)

    def checkObstacleNearBy(self, lidar):
        if min(lidar) <= NEARBY_DISTANCE:
            return True
        return False

    def checkGoalNearBy(self):
        if self.euclidean_distance() <= 1.0:
            return True
        return False

    def perform_action(self, action):

        linear_x = 0
        angular_z = 0
        state_description = ""
        linear_speed = 1.0
        angular_speed = 0.3
        
        if action == 0:
            state_description = 'case 1 - no obstacle ahead'
            linear_x = linear_speed
            angular_z = 0
        elif action == 1:
            state_description = 'case 2 - Obstacle at stright and right, going left'
            linear_x = 0.06
            angular_z = -angular_speed
        elif action == 2:
            state_description = 'case 3 - Obstacle at stright and left, going right'
            linear_x = 0.09
            angular_z = angular_speed
        elif action == 3:  #removed this action to make the lerning proces faster
            state_description = 'case 4 - Obstacle at stright and left and right, going back'
            linear_x = 0
            angular_z = angular_speed * 2
      
        print("================")
        print(state_description)
        print(action)
        self.to_vel_ctrl_pub.publish(std_msgs.msg.Empty())
        self.publishVel(linear_x, angular_z)



    def move2goal(self):
        """Moves the robot to the goal."""
        print("inside move2goal")
        #goal_pose = odomMsg
        distance = self.euclidean_distance()

        while self.euclidean_distance() >= distance_tolerance:
            
            inc_x = goal_x - x
            inc_y = goal_y - y

            angle_to_goal = atan2(inc_y, inc_x)
            print(abs(angle_to_goal - theta))

            if abs(angle_to_goal - theta) > 0.1:
                linear_x = 0.0
                angular_z = -0.3

            else:
                linear_x = 0.5
                angular_z = 0.0

            self.publishVel(linear_x, angular_z)
            
            msg = rospy.wait_for_message('lidar', LaserScan)
            ( lidar, angles ) = fixed_window.lidarScan(self, msg)

            length = len(lidar)
            index = int(length/3)

            if(min(lidar[index:2*index]) <= COLLISION_DISTANCE):
                self.avoidObstacle(lidar)

            self.rate.sleep()
 
        # Stopping our robot after the movement is over.
        print("Goal position reached")
        self.publishVel(0, 0)
    
if __name__ == '__main__':
     try:
        rospy.init_node('move_to_goal', anonymous=False)
        ec = move_to_goal()
        rospy.spin()
     except rospy.ROSInterruptException:
         pass