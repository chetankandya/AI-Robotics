#include "husky_control_node.h"

#include <std_msgs/Empty.h>

#include <ros/node_handle.h>

#include <tasks_machine/schedule_thread.h>

#include <march/state_graph/event.h>
#include <march/state_graph/interpreter_context.h>


#include <sensor_msgs/convert_messages.h>
#include <nav_msgs/convert_messages.h>
#include <geometry_msgs/convert_messages.h>


namespace
{
  template<typename _T_>
  inline bool getParam(ros::NodeHandle& _handle, const std::string& key, _T_& s)
  {
    return _handle.getParam(key, s);
  }
  template<>
  inline bool getParam<tinytl::string>(ros::NodeHandle& _handle, const std::string& key, tinytl::string& s)
  {
    std::string tmp = s.c_str();
    bool r = _handle.getParam(key, tmp);
    s = tmp.c_str();
    return r;
  }
 
}

husky_control_node::husky_control_node()
{
}

husky_control_node::~husky_control_node()
{
  delete m_machine;
  delete m_schedule_thread;
}

void husky_control_node::onInit()
{
  husky_control_machine::parameters parameters;
  getParam(getPrivateNodeHandle(), "Kp", parameters.Kp);
  getParam(getPrivateNodeHandle(), "Ki", parameters.Ki);
  getParam(getPrivateNodeHandle(), "Kd", parameters.Kd);
  getParam(getPrivateNodeHandle(), "Krho", parameters.Krho);
  getParam(getPrivateNodeHandle(), "Kalpha", parameters.Kalpha);
  getParam(getPrivateNodeHandle(), "Kbeta", parameters.Kbeta);
  
  m_machine = new husky_control_machine(parameters);
  m_interpreter.setup(m_machine);
  m_schedule_thread = new tasks_machine::schedule_thread(m_interpreter.get_schedule());
  
  
  m_wheel_cmd_pub = getNodeHandle().advertise<sensor_msgs::JointState>("wheel_cmd", 1);
  m_machine->listen_to_wheel_cmd_message([this](const march_ros::sensor_msgs::joint_state& _msg)
  {
    m_wheel_cmd_pub.publish(march_ros::convert<sensor_msgs::JointState, march_ros::sensor_msgs::joint_state>(_msg));

  });
  m_to_idle_control_sub = getNodeHandle().subscribe<::std_msgs::Empty>("to_idle_control", 100, [this](const ::std_msgs::EmptyConstPtr& _ros_msg)
  {
    m_machine->trigger_to_idle_control_event();
  });  // Input connector wheel_velocities
  m_wheel_velocities_sub = getNodeHandle().subscribe<sensor_msgs::JointState>("wheel_velocities", 100, [this](const sensor_msgs::JointStateConstPtr& _ros_msg)
    {
      march_ros::sensor_msgs::joint_state msg = march_ros::convert<march_ros::sensor_msgs::joint_state, sensor_msgs::JointState>(*_ros_msg);
      m_machine->send_wheel_velocities_message(msg);
    });  // Input connector odometry
  m_odometry_sub = getNodeHandle().subscribe<nav_msgs::Odometry>("odometry", 100, [this](const nav_msgs::OdometryConstPtr& _ros_msg)
    {
      march_ros::nav_msgs::odometry msg = march_ros::convert<march_ros::nav_msgs::odometry, nav_msgs::Odometry>(*_ros_msg);
      m_machine->send_odometry_message(msg);
    });  // Input connector cmd_vel
  m_cmd_vel_sub = getNodeHandle().subscribe<geometry_msgs::Twist>("cmd_vel", 100, [this](const geometry_msgs::TwistConstPtr& _ros_msg)
    {
      march_ros::geometry_msgs::twist msg = march_ros::convert<march_ros::geometry_msgs::twist, geometry_msgs::Twist>(*_ros_msg);
      m_machine->send_cmd_vel_message(msg);
    });
  m_to_vel_control_sub = getNodeHandle().subscribe<::std_msgs::Empty>("to_vel_control", 100, [this](const ::std_msgs::EmptyConstPtr& _ros_msg)
  {
    m_machine->trigger_to_vel_control_event();
  });  // Input connector cmd_position
  m_cmd_position_sub = getNodeHandle().subscribe<geometry_msgs::PoseStamped>("cmd_position", 100, [this](const geometry_msgs::PoseStampedConstPtr& _ros_msg)
    {
      march_ros::geometry_msgs::pose_stamped msg = march_ros::convert<march_ros::geometry_msgs::pose_stamped, geometry_msgs::PoseStamped>(*_ros_msg);
      m_machine->send_cmd_position_message(msg);
    });  // Input connector max_velocity
  m_max_velocity_sub = getNodeHandle().subscribe<geometry_msgs::Twist>("max_velocity", 100, [this](const geometry_msgs::TwistConstPtr& _ros_msg)
    {
      march_ros::geometry_msgs::twist msg = march_ros::convert<march_ros::geometry_msgs::twist, geometry_msgs::Twist>(*_ros_msg);
      m_machine->send_max_velocity_message(msg);
    });
  m_to_position_control_sub = getNodeHandle().subscribe<::std_msgs::Empty>("to_position_control", 100, [this](const ::std_msgs::EmptyConstPtr& _ros_msg)
  {
    m_machine->trigger_to_position_control_event();
  });
  m_to_waypoints_control_sub = getNodeHandle().subscribe<::std_msgs::Empty>("to_waypoints_control", 100, [this](const ::std_msgs::EmptyConstPtr& _ros_msg)
  {
    m_machine->trigger_to_waypoints_control_event();
  });  // Input connector cmd_waypoints
  m_cmd_waypoints_sub = getNodeHandle().subscribe<nav_msgs::Path>("cmd_waypoints", 100, [this](const nav_msgs::PathConstPtr& _ros_msg)
    {
      march_ros::nav_msgs::path msg = march_ros::convert<march_ros::nav_msgs::path, nav_msgs::Path>(*_ros_msg);
      m_machine->send_cmd_waypoints_message(msg);
    });
  m_position_reached_pub = getNodeHandle().advertise<::std_msgs::Empty>("position_reached", 1);
  m_machine->listen_to_position_reached_event([this]()
  {
    m_position_reached_pub.publish(::std_msgs::Empty());
  });
  m_waypoints_finished_pub = getNodeHandle().advertise<::std_msgs::Empty>("waypoints_finished", 1);
  m_machine->listen_to_waypoints_finished_event([this]()
  {
    m_waypoints_finished_pub.publish(::std_msgs::Empty());
  });

  m_schedule_thread->start();
}

#include <pluginlib/class_list_macros.h>
PLUGINLIB_EXPORT_CLASS(husky_control_node, nodelet::Nodelet) 
