#!/usr/bin/env python3

from dqn import Agent
import matplotlib.pyplot as plt
import numpy as np
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
from random import randint

MAX_LIDAR_DISTANCE = 8.0
COLLISION_DISTANCE = 0.5 
NEARBY_DISTANCE = 0.45

ZONE_0_LENGTH = 0.4
ZONE_1_LENGTH = 0.7

ANGLE_MAX = 181 - 1
ANGLE_MIN = 1 - 1
HORIZON_WIDTH = 90

DATA_PATH = '/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab4/'

class dqn_learn():

    def __init__(self):
        
        self.destination_pub = rospy.Publisher('destination', geometry_msgs.msg.PoseStamped, queue_size = 1)
        self.set_pose_pub = rospy.Publisher("set_pose", geometry_msgs.msg.Pose, queue_size = 1)
        self.initial_pose_pub = rospy.Publisher("initialpose", geometry_msgs.msg.PoseWithCovarianceStamped, queue_size = 1)
        self.cmd_velocity_pub =  rospy.Publisher('cmd_vel', geometry_msgs.msg.Twist, queue_size = 1)
        self.to_vel_ctrl_pub = rospy.Publisher("to_vel_control", std_msgs.msg.Empty, queue_size = 1)
        
        self.rate = rospy.Rate(10)
        self.execute()

    def execute(self):

        agent = Agent(gamma=0.99, epsilon=1.0, batch_size=64, n_actions=3, eps_end=0.01,
                    input_dims=[5], lr=0.001)
        scores, eps_history = [], []
        episodes = 150
        observation = (0,0,0,0,0)
        reward_total = {}
        epsilon_total = {}
        epsilon_t = []

        for i in range(episodes):
            score = 0
            self.respawn()
            done = False
            #state = (0,0,0,0,0)
            epsilon_total[i] = agent.epsilon
            epsilon_t.append(agent.epsilon)
            while not done:
                print("Current episode", i)
                action = agent.choose_action(observation)
                observation_, reward, done = self.step(action)
                
                #nextState = ''.join(map(str, observation))
                score += reward
                agent.store_transition(observation, action, reward, 
                                        observation_, done)
                agent.learn()
                if not(done):
                    observation = observation_
                else:
                    reward_total[i] = score
                    break
            eps_history.append(agent.epsilon)
            scores.append(score)
            avg_score = np.mean(scores[-100:])
            print("reward_total", reward_total)
            print('episode ', i, 'score %.2f' % score,
                    'average score %.2f' % avg_score,
                    'epsilon %.2f' % agent.epsilon)
                
        self.saveToFile(DATA_PATH + 'reward.csv', reward_total)
        self.saveToFile(DATA_PATH + 'epsilon.csv', epsilon_total)
        x = [i for i in range(episodes)]
        filename = DATA_PATH + 'plot.png'
        self.plotLearning(x, scores, eps_history, filename)

    def step(self, action):
        done = False 
        reward = 0
        msgScan = rospy.wait_for_message('lidar', LaserScan)
       
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
            
        self.perform_action(action)

        observation = self.discretize(msgScan)
        
        return observation, reward, done

    def saveToFile(self, fileName, Q_table):
        with open(fileName, 'w', newline='') as f:
            for key in Q_table.keys():
                f.write("%s,%s\n"%(key,Q_table[key]))

    def respawn(self):

        x = randint(-10,10)
        y = randint(-10,10)

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

        obs = (float(x1), float(x2), float(x3), float(x4), float(x5))
        return obs

    def plotLearning(self, x, scores, epsilons, filename, lines=None):
        fig=plt.figure()
        ax=fig.add_subplot(111, label="1")
        ax2=fig.add_subplot(111, label="2", frame_on=False)

        ax.plot(x, epsilons, color="C0")
        ax.set_xlabel("Simulations", color="C0")
        ax.set_ylabel("Epsilon", color="C0")
        ax.tick_params(axis='x', colors="C0")
        ax.tick_params(axis='y', colors="C0")

        # N = len(scores)
        # running_avg = np.empty(N)
        # for t in range(N):
        #     running_avg[t] = np.mean(scores[max(0, t-20):(t+1)])

        ax2.scatter(x, scores, color="C1")
        #ax2.xaxis.tick_top()
        ax2.axes.get_xaxis().set_visible(False)
        ax2.yaxis.tick_right()
        #ax2.set_xlabel('x label 2', color="C1")
        ax2.set_ylabel('Score', color="C1")
        #ax2.xaxis.set_label_position('top')
        ax2.yaxis.set_label_position('right')
        #ax2.tick_params(axis='x', colors="C1")
        ax2.tick_params(axis='y', colors="C1")

        if lines is not None:
            for line in lines:
                plt.axvline(x=line)

        plt.savefig(filename)

if __name__ == '__main__':
    rospy.init_node('dqn_learn', anonymous=False)
    ec = dqn_learn()
    rospy.spin()


