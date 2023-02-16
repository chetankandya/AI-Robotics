import std_msgs.msg
import time
import rospy
import TstML
import tf
import geometry_msgs.msg 
import nav_msgs.msg
import math

class ExploreExecutor(TstML.Executor.AbstractNodeExecutor):
    def __init__(self, node, context):
        super(TstML.Executor.AbstractNodeExecutor, self).__init__(node, context)
        # Create publisher
        self.waypoints_finished_sub = rospy.Subscriber('waypoints_finished', std_msgs.msg.Empty, self.waypoints_finished_callback)
        self.position_reached_sub = rospy.Subscriber('position_reached', std_msgs.msg.Empty, self.position_reached_callback)

        self.destination_pub = rospy.Publisher('destination', geometry_msgs.msg.PoseStamped, queue_size = 1)
        self.velocity_pub =  rospy.Publisher("max_velocity", geometry_msgs.msg.Twist, queue_size = 1)
        self.to_waypoint_ctrl_pub = rospy.Publisher("to_waypoints_control", std_msgs.msg.Empty, queue_size = 1)
        self.to_position_ctrl_pub = rospy.Publisher("to_position_control",std_msgs.msg.Empty,queue_size = 1)
        self.cmd_position_pub = rospy.Publisher("cmd_position", geometry_msgs.msg.PoseStamped, queue_size = 1)
        self.cmd_waypoints_pub = rospy.Publisher("cmd_waypoints", nav_msgs.msg.Path, queue_size = 1)
        time.sleep(2.0)

        self.executorName = "[ExploreExecutor]"

    def waypoints_finished_callback(self, req):
        self.executionFinished(TstML.Executor.ExecutionStatus.Finished())
        self.waypoints_finished_sub.unregister()
        self.position_reached_sub.unregister()

    def position_reached_callback(self, req):
        self.executionFinished(TstML.Executor.ExecutionStatus.Finished())
        self.position_reached_sub.unregister()
        self.waypoints_finished_sub.unregister()

    def start(self):

        print("{} Sampling archemedian spiral".format(self.executorName))
        vel = geometry_msgs.msg.Twist()
        max_speed = 0.5
        linear = max_speed
        angular = 3.0*max_speed
        vel.linear.x = linear
        vel.angular.z = angular
        self.velocity_pub.publish(vel)

        path = nav_msgs.msg.Path()
        a = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "a")
        b = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "b")
        max_radius = self.node().getParameter(TstML.TSTNode.ParameterType.Specific, "radius")
        increment = math.pi/4
        theta, r = 0, 0
        """These prev values should really be 
        retrieved in some other way..."""
        prev_x, prev_y = 1, 2
        while r <= max_radius:
            pose = geometry_msgs.msg.PoseStamped()
            theta += increment
            r = a + (b * theta)
            """The parameters for the quaternion is (roll, pitch, yaw)
            That's why we pass 0,0,yaw_angle"""
            x = (r * math.cos(theta)) + prev_x
            y = (r * math.sin(theta)) + prev_y
         
            quat = tf.transformations.quaternion_from_euler(0, 0, theta + math.pi/4)
            pose.pose.position.x = x
            pose.pose.position.y = y
            pose.pose.orientation.x = quat[0]
            pose.pose.orientation.y = quat[1]
            pose.pose.orientation.z = quat[2]
            pose.pose.orientation.w = quat[3]
            path.poses.append(pose)
            prev_x = x
            prev_y = y
            
        print("{} Length of path".format(self.executorName), len(path.poses))

        self.to_waypoint_ctrl_pub.publish(std_msgs.msg.Empty())
        time.sleep(1.5)
        path.header.frame_id = "odom"
        self.cmd_waypoints_pub.publish(path)

        return TstML.Executor.ExecutionStatus.Started()

    def pause(self):
        self.paused = True
        return TstML.Executor.ExecutionStatus.Paused()

    def resume(self):
        self.paused = False
        return TstML.Executor.ExecutionStatus.Running()

    def stop(self):
        # self.timer.shutdown()
        return TstML.Executor.ExecutionStatus.Finished()

    def abort(self):
        # self.timer.shutdown()
        return TstML.Executor.ExecutionStatus.Aborted()