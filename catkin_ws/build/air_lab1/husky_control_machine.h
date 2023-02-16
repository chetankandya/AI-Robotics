#include <march/state_graph/machine.h>
#include <march/state_graph/message_output_connector.h>
#include <march/state_graph/event_output_connector.h>


#include "march_ros/sensor_msgs.h"
#include "march_ros/nav_msgs.h"
#include "march_ros/geometry_msgs.h"

struct husky_control_machine_states;

class husky_control_machine : public march::state_graph::machine
{
public:
  struct parameters
  {
    parameters() {}
    
    double Kp = 0.1;
    double Ki = 0.001;
    double Kd = 0.0001;
    double Krho = 0.5;
    double Kalpha = 0.7;
    double Kbeta = -0.2;
  };
public:
  husky_control_machine(const parameters& _parameters = parameters());
  ~husky_control_machine();
  march::state_graph::states* setup(march::state_graph::interpreter* _interpreter) override;
  tinytl::vector<march::state_graph::machine_meta_information> get_meta_informations() const override;
public:
  void listen_to_wheel_cmd_message(const std::function<march::state_graph::message_output_connector<march_ros::sensor_msgs::joint_state>::callback_type>&);
  void trigger_to_idle_control_event();
  void send_wheel_velocities_message(const march_ros::sensor_msgs::joint_state& _message);
  void send_odometry_message(const march_ros::nav_msgs::odometry& _message);
  void send_cmd_vel_message(const march_ros::geometry_msgs::twist& _message);
  void trigger_to_vel_control_event();
  void send_cmd_position_message(const march_ros::geometry_msgs::pose_stamped& _message);
  void send_max_velocity_message(const march_ros::geometry_msgs::twist& _message);
  void trigger_to_position_control_event();
  void trigger_to_waypoints_control_event();
  void send_cmd_waypoints_message(const march_ros::nav_msgs::path& _message);
  void listen_to_position_reached_event(const std::function<march::state_graph::event_output_connector::callback_type>&);
  void listen_to_waypoints_finished_event(const std::function<march::state_graph::event_output_connector::callback_type>&);
private:
  husky_control_machine_states* m_states;
};
