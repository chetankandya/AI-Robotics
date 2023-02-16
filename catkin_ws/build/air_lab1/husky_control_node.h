#include <ros/publisher.h>
#include <ros/subscriber.h>

#include <nodelet/nodelet.h>

#include <thread>

#include <march/state_graph/interpreter.h>

#include "husky_control_machine.h"

namespace tasks_machine
{
  class schedule_thread;
}

class husky_control_node : public nodelet::Nodelet
{
public:
  husky_control_node();
  virtual ~husky_control_node();
public:
  virtual void onInit();
private:
  tasks_machine::schedule_thread* m_schedule_thread;
  march::state_graph::interpreter m_interpreter;
  husky_control_machine* m_machine = nullptr;
  
  ros::Publisher m_wheel_cmd_pub;
  ros::Subscriber m_to_idle_control_sub;
  ros::Subscriber m_wheel_velocities_sub;
  ros::Subscriber m_odometry_sub;
  ros::Subscriber m_cmd_vel_sub;
  ros::Subscriber m_to_vel_control_sub;
  ros::Subscriber m_cmd_position_sub;
  ros::Subscriber m_max_velocity_sub;
  ros::Subscriber m_to_position_control_sub;
  ros::Subscriber m_to_waypoints_control_sub;
  ros::Subscriber m_cmd_waypoints_sub;
  ros::Publisher m_position_reached_pub;
  ros::Publisher m_waypoints_finished_pub;
//   std::vector<ros::Publisher> m_publishers;
//   std::vector<ros::Subscriber> m_subscribers;
};
