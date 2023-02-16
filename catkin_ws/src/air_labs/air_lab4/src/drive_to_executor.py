import std_msgs.msg
import time
import rospy
import TstML
import tf
import geometry_msgs.msg 
import nav_msgs.msg
import math

class DriveToExecutor():
    def __init__(self):
        # Create publisher
        self.waypoints_finished_sub = rospy.Subscriber('waypoints_finished', std_msgs.msg.Empty, self.waypoints_finished_callback)
        self.position_reached_sub = rospy.Subscriber('position_reached', std_msgs.msg.Empty, self.position_reached_callback)

        self.destination_pub = rospy.Publisher('destination', geometry_msgs.msg.PoseStamped, queue_size = 1)
        self.velocity_pub =  rospy.Publisher("max_velocity", geometry_msgs.msg.Twist, queue_size = 1)
        self.to_waypoint_ctrl_pub = rospy.Publisher("to_waypoints_control", std_msgs.msg.Empty, queue_size = 1)
        self.to_position_ctrl_pub = rospy.Publisher("to_position_control",std_msgs.msg.Empty,queue_size = 1)
        self.cmd_position_pub = rospy.Publisher("cmd_position", geometry_msgs.msg.PoseStamped, queue_size = 1)
        time.sleep(2.0)

    def waypoints_finished_callback(self, req):
        self.executionFinished(TstML.Executor.ExecutionStatus.Finished())
        self.waypoints_finished_sub.unregister()
        self.position_reached_sub.unregister()

    def position_reached_callback(self, req):
        self.executionFinished(TstML.Executor.ExecutionStatus.Finished())
        self.position_reached_sub.unregister()
        self.waypoints_finished_sub.unregister()
    
    def send_velocity(self, linear, angular):
        vel = geometry_msgs.msg.Twist()
        vel.linear.x = linear
        vel.angular.z = angular
        self.velocity_pub.publish(vel)

    def start(self):

        use_motion_planner = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "use-motion-planner")

        max_speed = 0.5
        if self.node().hasParameter(TstML.TSTNode.ParameterType.Specific, "maximum-speed"):
            max_speed = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "maximum-speed")

        self.send_velocity(linear=max_speed, angular=3.0*max_speed)

        pose = geometry_msgs.msg.PoseStamped()

        p = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "p")
        pose.pose.position.x = p['x']
        pose.pose.position.y = p['y']
        pose.pose.position.z = p['z']

        if use_motion_planner:
            print("[DriveToExecutor] Using motion planner")
            self.to_waypoint_ctrl_pub.publish(std_msgs.msg.Empty())
            time.sleep(1.5)

            if self.node().hasParameter(TstML.TSTNode.ParameterType.Specific, "heading"):
                heading = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "heading")
                quat = tf.transformations.quaternion_from_euler(0, 0, heading)
                pose.pose.orientation.x = quat[0]
                pose.pose.orientation.y = quat[1]
                pose.pose.orientation.z = quat[2]
                pose.pose.orientation.w = quat[3]
            else:
                yaw = 0
                quat = tf.transformations.quaternion_from_euler(0, 0, -math.radians(yaw))
                pose.pose.orientation.x = quat[0]
                pose.pose.orientation.y = quat[1]
                pose.pose.orientation.z = quat[2]
                pose.pose.orientation.w = quat[3]

            self.destination_pub.publish(pose)
            print("[DriveToExecutor] Using motion planner")
        else:
            self.to_position_ctrl_pub.publish(std_msgs.msg.Empty())
            time.sleep(1.5)
            self.cmd_position_pub.publish(pose)
            print("[DriveToExecutor] Not using motion planner")

        return TstML.Executor.ExecutionStatus.Started()

    def pause(self):
        self.paused = True
        return TstML.Executor.ExecutionStatus.Paused()

    def resume(self):
        self.paused = False
        return TstML.Executor.ExecutionStatus.Running()

    def stop(self):
        self.timer.shutdown()
        return TstML.Executor.ExecutionStatus.Finished()

    def abort(self):
        self.timer.shutdown()
        return TstML.Executor.ExecutionStatus.Aborted()

