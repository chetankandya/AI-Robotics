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
from geometry_msgs.msg import Pose
import sensor_msgs.msg
import numpy as np
from QLearn import QLearn
from random import randint


MAX_LIDAR_DISTANCE = 8.0
COLLISION_DISTANCE = 0.5 
NEARBY_DISTANCE = 0.45

ZONE_0_LENGTH = 0.4
ZONE_1_LENGTH = 0.7

ANGLE_MAX = 181 - 1
ANGLE_MIN = 1 - 1
HORIZON_WIDTH = 90

first_action_taken = False

DATA_PATH = '/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab4/q_table/'

class q_learn():
    def __init__(self):
        self.map_request = rospy.ServiceProxy('map_request', nav_msgs.srv.GetMap)
        self.velocity_pub =  rospy.Publisher("max_velocity", geometry_msgs.msg.Twist, queue_size = 1)
        self.to_waypoint_ctrl_pub = rospy.Publisher("to_waypoints_control", std_msgs.msg.Empty, queue_size = 1)
        self.to_position_ctrl_pub = rospy.Publisher("to_position_control",std_msgs.msg.Empty,queue_size = 1)
        self.cmd_position_pub = rospy.Publisher("cmd_position", geometry_msgs.msg.PoseStamped, queue_size = 1)

        self.destination_pub = rospy.Publisher('destination', geometry_msgs.msg.PoseStamped, queue_size = 1)
        self.set_pose_pub = rospy.Publisher("set_pose", geometry_msgs.msg.Pose, queue_size = 1)
        self.initial_pose_pub = rospy.Publisher("initialpose", geometry_msgs.msg.PoseWithCovarianceStamped, queue_size = 1)
        self.cmd_velocity_pub =  rospy.Publisher('cmd_vel', geometry_msgs.msg.Twist, queue_size = 1)
        self.to_vel_ctrl_pub = rospy.Publisher("to_vel_control", std_msgs.msg.Empty, queue_size = 1)
        #self.to_idle_ctrl_pub = rospy.Publisher("to_idle_control", std_msgs.msg.Empty, queue_size = 1)
        
        self.rate = rospy.Rate(10)
        self.qlearn = QLearn(actions=range(0, 3), alpha=0.2, gamma=0.8, epsilon=0.9)
        self.execute()

    def execute(self):

        initial_epsilon = self.qlearn.epsilon
        total_episodes = 1000
        epsilon_discount = 0.9986
        epsilon_per_episode = []
        start_time = time.time()
        highest_reward = 0
        current_episode = 0
        total_reward = {}
        total_epsilon = {}

        for x in range(total_episodes):
            
            self.respawn()
            cumulated_reward = 0
            done = False
            observation = (0, 0)
            prev_action = 0
            current_episode += 1

            if (current_episode == 150) or (current_episode == 300) or (current_episode == 500):
                self.qlearn.saveQTable(DATA_PATH + '/Qtable.csv', self.qlearn.q)
                self.qlearn.saveQTable(DATA_PATH + '/reards_ql.csv', total_reward)
                self.qlearn.saveQTable(DATA_PATH + '/epsilon_ql.csv', total_epsilon)
            
            if current_episode == 500:
                print(epsilon_per_episode)

            if self.qlearn.epsilon > 0.05:
                self.qlearn.epsilon *= epsilon_discount
            
            epsilon_per_episode.append(self.qlearn.epsilon)
            total_epsilon[current_episode] = self.qlearn.epsilon
            print("current_iteration", current_episode)

            state = ''.join(map(str, observation))

            for i in range(500):
                action, q = self.qlearn.chooseAction(state, return_q=True)
                print(state)
                print("===================")
                print(action, q)
                print("===================")

                reward, nextState, done = self.step(action, prev_action)
                cumulated_reward += reward
                print("current_iteration", current_episode)
                print("cumulated_reward", cumulated_reward)
                print("epsilons", self.qlearn.epsilon)

                if highest_reward < cumulated_reward:
                    highest_reward = cumulated_reward

                self.qlearn.learn(state, action, reward, nextState)
                if not(done):
                    state = nextState
                    prev_action = action
                else:   
                    total_reward[current_episode] = cumulated_reward
                    break 
                
                self.rate

    def respawn(self):

        x = randint(-10,10)
        y = randint(-10,10)

        #init_pos.header.frame_id = "odom"
        pose = geometry_msgs.msg.PoseWithCovarianceStamped()
        pose.header.frame_id = "odom"
        pose.pose.pose.position.x = x
        pose.pose.pose.position.y = y
        pose.pose.pose.position.z = 0
        #init_pos.quaternion.w = 1
        pose.pose.pose.orientation.x = 0
        pose.pose.pose.orientation.y = 0
        pose.pose.pose.orientation.z = 0
        pose.pose.pose.orientation.w = 1
        self.initial_pose_pub.publish(pose)


        pos = geometry_msgs.msg.Pose()
        pos.position.x = x
        pos.position.y = y
        pos.position.z = 0
        #init_pos.quaternion.w = 1
        pos.orientation.x = 0
        pos.orientation.y = 0
        pos.orientation.z = 0
        pos.orientation.w = 1
        self.set_pose_pub.publish(pos)
    # o = front, 1 = left, 2 = right and 3 = reverse
    def step(self, action, prev_action):
        global first_action_taken
        done = False 
        reward = 0
        msgScan = rospy.wait_for_message('lidar', LaserScan)
        #print(msgScan)
        """
        Get initial state
        Take the first action on the basis of the initial state
        Get the observation or next state from the environment 
        set prev_action = action
        calculate the reward
        
        """
        if not first_action_taken:

            self.perform_action(action)
            first_action_taken = True
        else:
            #reward for action
            if self.checkCrash(msgScan):
                reward = -100
                print("Robot Crashed")
                self.publishVel(0, 0)
                done = True
            elif action == 0:
                reward = 0.5
            elif action == 1 or action == 2:
                reward = 0.1
            
            #reward for direction change
            if ( prev_action == 1 and action == 2 ) or ( prev_action == 2 and action == 1 ):
                r_change = -0.5
            else:
                r_change = 0.0

            reward = reward + r_change
            self.perform_action(action)

        observation = self.discretize(msgScan)
        nextState = ''.join(map(str, observation))
        return reward, nextState, done
        
    def perform_action(self, action):
        linear_x = 0
        angular_z = 0
        state_description = ""
        linear_speed = 0.9
        angular_speed = 0.4
        
        if action == 0:
            state_description = 'case 1 - no obstacle ahead'
            linear_x = linear_speed
            angular_z = 0
        elif action == 1:
            state_description = 'case 2 - Obstacle at stright and right, going left'
            linear_x = 0.04
            angular_z = -angular_speed
        elif action == 2:
            state_description = 'case 3 - Obstacle at stright and left, going right'
            linear_x = 0.04
            angular_z = angular_speed
        elif action == 3:  #removed this action to make the lerning proces faster
            state_description = 'case 4 - Obstacle at stright and left and right, going back'
            linear_x = 0
            angular_z = angular_speed
      
        print("================")
        print(state_description)
        print(action)
        self.publishVel(linear_x, angular_z)

    def publishVel(self, linear_x, angular_z):
        m = Twist()
        self.to_vel_ctrl_pub.publish(std_msgs.msg.Empty())
        m.linear.x = linear_x
        m.angular.z = angular_z
        self.cmd_velocity_pub.publish(m)


    def checkCrash(self, lidar):
        length = len(lidar.ranges)
        for i in range(length):
            crash = False
            if (lidar.ranges[i] <= COLLISION_DISTANCE):
                crash = True
        return crash

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

    def discretize(self, msg):
        length = len(msg.ranges)
        index = int(length/5)

        x1 = 0 # No object at far left
        x2 = 0 # No object on left
        x3 = 0 # No object infront
        x4 = 0 # No object on right
        x5 = 0 # No object at far right

        ( lidar, angles ) = self.lidarScan(msg)
        # lidar_left = lidar[(ANGLE_MIN):(ANGLE_MIN + HORIZON_WIDTH)]

        lidar_far_left = min(lidar[0:index])
        lidar_left = min(lidar[index:2*index])
        lidar_front = min(lidar[2*index:3*index])
        lidar_right = min(lidar[3*index:4*index])
        lidar_far_right = min(lidar[4*index:length])

        if MAX_LIDAR_DISTANCE/2 < lidar_far_left < MAX_LIDAR_DISTANCE:
            x1 = 2 # obstacle at far left in sector 2
        elif lidar_far_left < MAX_LIDAR_DISTANCE/2:
            x1 = 1 # obstacle at far left in sector 1

        if MAX_LIDAR_DISTANCE/2 < lidar_left < MAX_LIDAR_DISTANCE:
            x2 = 2 # obstacle at  left in sector 2
        elif lidar_left < MAX_LIDAR_DISTANCE/2:
            x2 = 1 # obstacle at  left in sector 1

        if MAX_LIDAR_DISTANCE/2 < lidar_front < MAX_LIDAR_DISTANCE:
            x3 = 2 # obstacle at  front in sector 2
        elif lidar_front < MAX_LIDAR_DISTANCE/2:
            x3 = 1 # obstacle at front in sector 1

        if MAX_LIDAR_DISTANCE/2 < lidar_right < MAX_LIDAR_DISTANCE:
            x4 = 2 # obstacle at  right in sector 2
        elif lidar_right < MAX_LIDAR_DISTANCE/2:
            x4 = 1 # obstacle at right in sector 1
        
        if MAX_LIDAR_DISTANCE/2 < lidar_far_right < MAX_LIDAR_DISTANCE:
            x5 = 2 # obstacle at far right in sector 2
        elif lidar_far_right < MAX_LIDAR_DISTANCE/2:
            x5 = 1 # obstacle at far right in sector 1

        # print(msg)
        # print("---------------------------")
        # print(far_left)
        # print(left)
        # print("Lidar Horizon")
        # print( lidar_left)
        # input()

        obs = (x1, x2, x3, x4, x5)
        return obs
        
if __name__ == '__main__':
    rospy.init_node('q_learn', anonymous=False)
    ec = q_learn()
    rospy.spin()
