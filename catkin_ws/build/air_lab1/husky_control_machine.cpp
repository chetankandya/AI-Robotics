#include "husky_control_machine.h"

#include <tasks_machine/schedule.h>

#include <cmath>

#include <march/graph_ops/direct_input_adaptor.h>
#include <march/graph_ops/direct_output_adaptor.h>
#include <march/graph_ops/functional_execution_context.h>
#include <march/graph_ops/op_queued_task.h>

#include <march/state_graph/message_input_connector.h>
#include <march/state_graph/op_state_queued_task.h>
#include <march/state_graph/op_state_scheduled_task.h>
#include <march/state_graph/interpreter.h>
#include <march/state_graph/states.h>
#include <march/state_graph/machine_meta_information.h>
#include <march/state_graph/timer.h>
#include <march/state_graph/transition_helper.h>


#include "march_ros/sensor_msgs_tools.h"
#include "march/std_msgs.h"
#include "march_ros/sensor_msgs.h"
#include "march/list.h"
#include "march/std_lib.h"
#include "march/control.h"
#include "march_ros/march_ros.h"
#include "air_lab1_march.h"
#include "march_ros/geometry_msgs_tools.h"
#include "march_ros/geometry_msgs.h"
#include "march_ros/nav_msgs_tools.h"
#include "march_ros/nav_msgs.h"
#include "march/debugger.h"
#include "march/debugger/networking.h"

class husky_control_machine_states;
/**************
 * Declaration of op state 'controller' 
 */

void husky_control_machine_state_2_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_2_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_2_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_2_output_connector_o0
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::sensor_msgs::joint_state& _message) const;
};
  
struct husky_control_machine_state_2_output_connector___shadow_1
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_2_output_connector___shadow_2
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_2_output_connector___shadow_4
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_2_output_connector___shadow_6
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_2_output_connector___shadow_7
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_2_output_connector___shadow_9
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct processing_graph_2;

struct husky_control_machine_state_2
{
  
  typedef processing_graph_2 Op;
  
  husky_control_machine_state_2() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_2_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_2_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_2_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> i0;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> i1;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> i2;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> i3;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> i4;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> i5;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> __shadow_0;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> __shadow_3;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> __shadow_5;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> __shadow_8;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_i0(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.i0.send_message(_value);
    }
    
    inline void receive_message_i1(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.i1.send_message(_value);
    }
    
    inline void receive_message_i2(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.i2.send_message(_value);
    }
    
    inline void receive_message_i3(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.i3.send_message(_value);
    }
    
    inline void receive_message_i4(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.i4.send_message(_value);
    }
    
    inline void receive_message_i5(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.i5.send_message(_value);
    }
    
    inline void receive_message___shadow_0(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.__shadow_0.send_message(_value);
    }
    
    inline void receive_message___shadow_3(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.__shadow_3.send_message(_value);
    }
    
    inline void receive_message___shadow_5(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.__shadow_5.send_message(_value);
    }
    
    inline void receive_message___shadow_8(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.__shadow_8.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_2_output_connector_o0 o0;
    husky_control_machine_state_2_output_connector___shadow_1 __shadow_1;
    husky_control_machine_state_2_output_connector___shadow_2 __shadow_2;
    husky_control_machine_state_2_output_connector___shadow_4 __shadow_4;
    husky_control_machine_state_2_output_connector___shadow_6 __shadow_6;
    husky_control_machine_state_2_output_connector___shadow_7 __shadow_7;
    husky_control_machine_state_2_output_connector___shadow_9 __shadow_9;} outputs;
    struct parameters {
      
      double Kp;
      double Ki;
      double Kd;
    };
    inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
    {
      parameters p;
      p.Kp = _parameters.Kp;
      p.Ki = _parameters.Ki;
      p.Kd = _parameters.Kd;
      return p;
    }
};
/**************
 * Declaration of op state 'initial time'  with activity 'march_ros/current_time' 
 */

void husky_control_machine_state_3_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_3_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_3_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_3_output_connector_t
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_3_output_connector_ns
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::unsigned_integer32& _message) const;
};
  
struct husky_control_machine_state_3_output_connector_s
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::unsigned_integer32& _message) const;
};
  

struct husky_control_machine_state_3
{
  
  typedef march_ros::current_time_op Op;
  
  husky_control_machine_state_3() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_3_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_3_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_3_event_handler;
  }
  
  // Structure containing the input connectors
  struct {} inputs;

  // Helper function to trigger input
  
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_3_output_connector_t t;
    husky_control_machine_state_3_output_connector_ns ns;
    husky_control_machine_state_3_output_connector_s s;} outputs;
  typedef march_ros::current_time_op::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    return p;
  }
  
};
/**************
 * Declaration of op state 'idle'  with activity 'march_std_lib/output_float64' 
 */

void husky_control_machine_state_5_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_5_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_5_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_5_output_connector_value
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  

struct husky_control_machine_state_5
{
  
  typedef march::std_lib::output_float64_op Op;
  
  husky_control_machine_state_5() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_5_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_5_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_5_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march::std_msgs::float64, 1> value;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_value(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.value.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_5_output_connector_value value;} outputs;
  typedef march::std_lib::output_float64_op::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    p.value = 0;
    return p;
  }
  
};
/**************
 * Declaration of op state 'decompose velocity' 
 */

void husky_control_machine_state_8_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_8_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_8_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_8_output_connector_o0
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_8_output_connector_o1
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct processing_graph_8;

struct husky_control_machine_state_8
{
  
  typedef processing_graph_8 Op;
  
  husky_control_machine_state_8() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_8_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_8_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_8_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::graph_ops::direct_output_adaptor<march_ros::geometry_msgs::twist> i0;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_i0(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _value)
    {
      inputs.i0.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_8_output_connector_o0 o0;
    husky_control_machine_state_8_output_connector_o1 o1;} outputs;
    struct parameters {
      
    };
    inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
    {
      parameters p;
      return p;
    }
};
/**************
 * Declaration of super state 'untitled'
 */

void husky_control_machine_state_7_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_7_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_7_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_7
{
  husky_control_machine_state_7() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_7_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_7_deactivate(_interpreter, _states);
  }
  // Deactivators
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_1_deactivator;
};
/**************
 * Declaration of activity state 'velocity mode' with component 'velocity_controller'
 */

void husky_control_machine_state_6_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_6_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_6_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_6
{
  husky_control_machine_state_6();
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_6_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_6_deactivate(_interpreter, _states);
  }

  
    void receive_message_cmd_vel(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _value);
    
  void forward_message_linear(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message);
  void forward_message_angular(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message);
  void forward_event_timeout(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
  void forward_event_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
};

/**************
 * Declaration of op state 'reach point'  with activity 'air_lab1_march/reach_point' 
 */

void husky_control_machine_state_11_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_11_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_11_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_11_output_connector_linear
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_11_output_connector_angular
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  

struct husky_control_machine_state_11
{
  
  typedef air_lab1_march::reach_point_op Op;
  
  husky_control_machine_state_11() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_11_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_11_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_11_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march_ros::geometry_msgs::pose_stamped, 1> cmd_position;
    ::march::state_graph::message_input_connector<march_ros::geometry_msgs::twist, 1> cmd_max_vel;
    ::march::state_graph::message_input_connector<march_ros::geometry_msgs::pose, 1> current_position;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_cmd_position(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose_stamped& _value)
    {
      inputs.cmd_position.send_message(_value);
    }
    
    inline void receive_message_cmd_max_vel(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _value)
    {
      inputs.cmd_max_vel.send_message(_value);
    }
    
    inline void receive_message_current_position(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose& _value)
    {
      inputs.current_position.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_11_output_connector_linear linear;
    husky_control_machine_state_11_output_connector_angular angular;} outputs;
  typedef air_lab1_march::reach_point_op::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    p.krho = 0.5;
    p.kalpha = 0.6;
    p.kbeta = -0.5;
    return p;
  }
  
};
/**************
 * Declaration of op state 'idle'  with activity 'march_std_lib/output_float64' 
 */

void husky_control_machine_state_12_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_12_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_12_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_12_output_connector_value
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  

struct husky_control_machine_state_12
{
  
  typedef march::std_lib::output_float64_op Op;
  
  husky_control_machine_state_12() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_12_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_12_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_12_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march::std_msgs::float64, 1> value;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_value(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.value.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_12_output_connector_value value;} outputs;
  typedef march::std_lib::output_float64_op::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    p.value = 0;
    return p;
  }
  
};
/**************
 * Declaration of op state 'point_reached' 
 */

void husky_control_machine_state_13_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_13_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_13_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);



struct husky_control_machine_state_13
{
  
  
  husky_control_machine_state_13() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_13_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_13_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_13_event_handler;
  }
  
  // Structure containing the input connectors
  struct {} inputs;

  // Helper function to trigger input
  
  // Structure containing the output connectors
  struct {} outputs;
};
/**************
 * Declaration of super state 'reach_point_controller'
 */

void husky_control_machine_state_10_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_10_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_10_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_10
{
  husky_control_machine_state_10() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_10_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_10_deactivate(_interpreter, _states);
  }
  // Deactivators
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_1_deactivator;
};
/**************
 * Declaration of activity state 'reach_point_controller' with component 'reach_point_controller'
 */

void husky_control_machine_state_9_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_9_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_9_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_9
{
  husky_control_machine_state_9();
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_9_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_9_deactivate(_interpreter, _states);
  }

  
    void receive_message_cmd_pose(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose_stamped& _value);
    
    void receive_message_max_velocity(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _value);
    
    void receive_message_current_pose(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose& _value);
    
  void forward_message_vel_linear(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message);
  void forward_message_vel_angular(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message);
  void forward_event_timeout(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
  void forward_event_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
  void forward_event_point_reached(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
};

struct husky_control_machine_guard_14
{
      
  // Guard expression
  static bool is_guarded(husky_control_machine_states * _states);
  
  // Values used to evaluate the expression
  
  march_ros::geometry_msgs::pose position;
  void receive_message_position(const march_ros::geometry_msgs::pose& _position)
  {
    position = _position;
  }
  march_ros::geometry_msgs::pose_stamped target;
  void receive_message_target(const march_ros::geometry_msgs::pose_stamped& _target)
  {
    target = _target;
  }
};
/**************
 * Declaration of op state 'idle'  with activity 'march_std_lib/output_float64' 
 */

void husky_control_machine_state_17_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_17_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_17_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_17_output_connector_value
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  

struct husky_control_machine_state_17
{
  
  typedef march::std_lib::output_float64_op Op;
  
  husky_control_machine_state_17() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_17_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_17_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_17_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march::std_msgs::float64, 1> value;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_value(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.value.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_17_output_connector_value value;} outputs;
  typedef march::std_lib::output_float64_op::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    p.value = 0;
    return p;
  }
  
};
/**************
 * Declaration of op state 'decompose'  with activity 'ros_nav_msgs_tools/path_dissassemble' 
 */

void husky_control_machine_state_18_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_18_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_18_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_18_output_connector_header
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::header& _message) const;
};
  
struct husky_control_machine_state_18_output_connector_poses
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::geometry_msgs::pose_stamped_list& _message) const;
};
  

struct husky_control_machine_state_18
{
  
  typedef march_ros::nav_msgs::tools::path_dissassemble_op Op;
  
  husky_control_machine_state_18() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_18_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_18_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_18_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march_ros::nav_msgs::path, 1> message;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_message(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::nav_msgs::path& _value)
    {
      inputs.message.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_18_output_connector_header header;
    husky_control_machine_state_18_output_connector_poses poses;} outputs;
  typedef march_ros::nav_msgs::tools::path_dissassemble_op::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    return p;
  }
  
};
/**************
 * Declaration of op state 'pop'  with activity 'march_list/list_pop' 
 */

void husky_control_machine_state_19_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_19_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_19_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_19_output_connector_list
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::geometry_msgs::pose_stamped_list& _message) const;
};
  
struct husky_control_machine_state_19_output_connector_value
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::geometry_msgs::pose_stamped& _message) const;
};
  

struct husky_control_machine_state_19
{
  
  typedef march::list::list_pop_op<march_ros::geometry_msgs::pose_stamped_list, march_ros::geometry_msgs::pose_stamped_list, march_ros::geometry_msgs::pose_stamped> Op;
  
  husky_control_machine_state_19() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_19_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_19_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_19_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march_ros::geometry_msgs::pose_stamped_list, 1> list;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_list(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose_stamped_list& _value)
    {
      inputs.list.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_19_output_connector_list list;
    husky_control_machine_state_19_output_connector_value value;} outputs;
  typedef march::list::list_pop_op<march_ros::geometry_msgs::pose_stamped_list, march_ros::geometry_msgs::pose_stamped_list, march_ros::geometry_msgs::pose_stamped>::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    return p;
  }
  
};
/**************
 * Declaration of op state 'reach point controller'  with activity 'air_lab1_march/reach_point' 
 */

void husky_control_machine_state_20_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_20_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_20_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_20_output_connector_linear
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_20_output_connector_angular
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  

struct husky_control_machine_state_20
{
  
  typedef air_lab1_march::reach_point_op Op;
  
  husky_control_machine_state_20() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_20_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_20_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_20_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march_ros::geometry_msgs::pose_stamped, 1> cmd_position;
    ::march::state_graph::message_input_connector<march_ros::geometry_msgs::twist, 1> cmd_max_vel;
    ::march::state_graph::message_input_connector<march_ros::geometry_msgs::pose, 1> current_position;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_cmd_position(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose_stamped& _value)
    {
      inputs.cmd_position.send_message(_value);
    }
    
    inline void receive_message_cmd_max_vel(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _value)
    {
      inputs.cmd_max_vel.send_message(_value);
    }
    
    inline void receive_message_current_position(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose& _value)
    {
      inputs.current_position.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_20_output_connector_linear linear;
    husky_control_machine_state_20_output_connector_angular angular;} outputs;
  typedef air_lab1_march::reach_point_op::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    p.krho = 1;
    p.kalpha = 2;
    p.kbeta = -3;
    return p;
  }
  
};
/**************
 * Declaration of super state 'untitled'
 */

void husky_control_machine_state_16_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_16_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_16_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_16
{
  husky_control_machine_state_16() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_16_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_16_deactivate(_interpreter, _states);
  }
  // Deactivators
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_1_deactivator;
};
/**************
 * Declaration of activity state 'waypoint_controller' with component 'waypoints_controller'
 */

void husky_control_machine_state_15_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_15_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_15_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_15
{
  husky_control_machine_state_15();
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_15_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_15_deactivate(_interpreter, _states);
  }

  
    void receive_message_waypoints(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::nav_msgs::path& _value);
    
    void receive_message_max_velocity(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _value);
    
    void receive_message_current_pose(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose& _value);
    
  void forward_message_linear(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message);
  void forward_message_angular(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message);
  void forward_event_timeout(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
  void forward_event_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
  void forward_event_waypoints_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
};

struct husky_control_machine_guard_21
{
      
  // Guard expression
  static bool is_guarded(husky_control_machine_states * _states);
  
  // Values used to evaluate the expression
  
  march_ros::geometry_msgs::pose position;
  void receive_message_position(const march_ros::geometry_msgs::pose& _position)
  {
    position = _position;
  }
  march_ros::geometry_msgs::pose_stamped target;
  void receive_message_target(const march_ros::geometry_msgs::pose_stamped& _target)
  {
    target = _target;
  }
};
/**************
 * Declaration of super state 'control mode'
 */

void husky_control_machine_state_4_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_4_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_4_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_4
{
  husky_control_machine_state_4() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_4_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_4_deactivate(_interpreter, _states);
  }
  // Deactivators
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_151_deactivator;
};
/**************
 * Declaration of op state 'extract wheel velocities' 
 */

void husky_control_machine_state_22_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_22_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_22_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_22_output_connector_o0
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct husky_control_machine_state_22_output_connector_o1
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const;
};
  
struct processing_graph_22;

struct husky_control_machine_state_22
{
  
  typedef processing_graph_22 Op;
  
  husky_control_machine_state_22() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_22_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_22_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_22_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::graph_ops::direct_output_adaptor<march_ros::sensor_msgs::joint_state> i0;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_i0(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::sensor_msgs::joint_state& _value)
    {
      inputs.i0.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_22_output_connector_o0 o0;
    husky_control_machine_state_22_output_connector_o1 o1;} outputs;
    struct parameters {
      
    };
    inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
    {
      parameters p;
      return p;
    }
};
/**************
 * Declaration of op state 'dissassemble odometry message' 
 */

void husky_control_machine_state_23_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_23_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_23_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_23_output_connector_o0
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::geometry_msgs::pose& _message) const;
};
  
struct processing_graph_23;

struct husky_control_machine_state_23
{
  
  typedef processing_graph_23 Op;
  
  husky_control_machine_state_23() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_23_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_23_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_23_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::graph_ops::direct_output_adaptor<march_ros::nav_msgs::odometry> i0;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_i0(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::nav_msgs::odometry& _value)
    {
      inputs.i0.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_23_output_connector_o0 o0;} outputs;
    struct parameters {
      
    };
    inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
    {
      parameters p;
      return p;
    }
};
/**************
 * Declaration of op state 'start monitor' 
 */

void husky_control_machine_state_26_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_26_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_26_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);


struct husky_control_machine_state_26_output_connector_o0
{
  void send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::debugger::msgs::monitor& _message) const;
};
  
struct processing_graph_26;

struct husky_control_machine_state_26
{
  
  typedef processing_graph_26 Op;
  
  husky_control_machine_state_26() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_26_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_26_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_26_event_handler;
  }
  
  // Structure containing the input connectors
  struct {} inputs;

  // Helper function to trigger input
  
  // Structure containing the output connectors
  struct {
    husky_control_machine_state_26_output_connector_o0 o0;} outputs;
    struct parameters {
      
      uint32_t port;
    };
    inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
    {
      parameters p;
      p.port = 2001;
      return p;
    }
};
/**************
 * Declaration of op state 'process'  with activity 'march_debugger/monitor_process' 
 */

void husky_control_machine_state_27_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_27_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_27_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);



struct husky_control_machine_state_27
{
  
  typedef march::debugger::monitor_process_op Op;
  
  husky_control_machine_state_27() : rt_task(this)
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_27_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_27_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_27_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march::debugger::msgs::monitor, 1> monitor;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_monitor(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::debugger::msgs::monitor& _value)
    {
      inputs.monitor.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {} outputs;
  typedef march::debugger::monitor_process_op::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    return p;
  }
  
  march::state_graph::op_state_scheduled_task<husky_control_machine_state_27, husky_control_machine_states> rt_task;
};
/**************
 * Declaration of super state 'networking_debugger'
 */

void husky_control_machine_state_25_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_25_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_25_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_25
{
  husky_control_machine_state_25() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_25_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_25_deactivate(_interpreter, _states);
  }
  // Deactivators
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_1_deactivator;
};
/**************
 * Declaration of activity state 'debugger' with component 'debugger'
 */

void husky_control_machine_state_24_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_24_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_24_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_24
{
  husky_control_machine_state_24();
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_24_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_24_deactivate(_interpreter, _states);
  }

  
  void forward_message_monitor(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::debugger::msgs::monitor& _message);
  void forward_event_timeout(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
  void forward_event_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
};

/**************
 * Declaration of op state 'send'  with activity 'march_debugger/send_message' 
 */

void husky_control_machine_state_28_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_28_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_28_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);



struct husky_control_machine_state_28
{
  
  typedef march::debugger::send_message_op<march::std_msgs::float64> Op;
  
  husky_control_machine_state_28() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_28_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_28_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_28_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march::debugger::msgs::monitor, 1> monitor;
    ::march::state_graph::message_input_connector<march::std_msgs::float64, 1> value;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_monitor(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::debugger::msgs::monitor& _value)
    {
      inputs.monitor.send_message(_value);
    }
    
    inline void receive_message_value(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.value.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {} outputs;
  typedef march::debugger::send_message_op<march::std_msgs::float64>::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    p.name = "a";
    return p;
  }
  
};
/**************
 * Declaration of op state 'send'  with activity 'march_debugger/send_message' 
 */

void husky_control_machine_state_29_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_29_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_29_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);



struct husky_control_machine_state_29
{
  
  typedef march::debugger::send_message_op<march::std_msgs::float64> Op;
  
  husky_control_machine_state_29() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_29_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_29_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_29_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march::debugger::msgs::monitor, 1> monitor;
    ::march::state_graph::message_input_connector<march::std_msgs::float64, 1> value;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_monitor(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::debugger::msgs::monitor& _value)
    {
      inputs.monitor.send_message(_value);
    }
    
    inline void receive_message_value(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _value)
    {
      inputs.value.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {} outputs;
  typedef march::debugger::send_message_op<march::std_msgs::float64>::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    p.name = "";
    return p;
  }
  
};
/**************
 * Declaration of op state 'send'  with activity 'march_debugger/send_message' 
 */

void husky_control_machine_state_30_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_30_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_30_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);



struct husky_control_machine_state_30
{
  
  typedef march::debugger::send_message_op<march::std_msgs::empty> Op;
  
  husky_control_machine_state_30() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_30_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_30_deactivate(_interpreter, _states);
  }
  
  static inline march::state_graph::event::callback_type* get_event_handler()
  {
    return &husky_control_machine_state_30_event_handler;
  }
  
  // Structure containing the input connectors
  struct {
    ::march::state_graph::message_input_connector<march::debugger::msgs::monitor, 1> monitor;
    ::march::state_graph::message_input_connector<march::std_msgs::empty, 1> value;} inputs;

  // Helper function to trigger input
  
    inline void receive_message_monitor(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::debugger::msgs::monitor& _value)
    {
      inputs.monitor.send_message(_value);
    }
    
    inline void receive_message_value(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::empty& _value)
    {
      inputs.value.send_message(_value);
    }
    
  // Structure containing the output connectors
  struct {} outputs;
  typedef march::debugger::send_message_op<march::std_msgs::empty>::parameters parameters;
  inline static parameters get_parameters(const husky_control_machine::parameters& _parameters)
  {
    parameters p;
    p.name = "";
    return p;
  }
  
};
/**************
 * Declaration of super state 'husky_control'
 */

void husky_control_machine_state_1_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_1_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states);
void husky_control_machine_state_1_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event);

struct husky_control_machine_state_1
{
  husky_control_machine_state_1() 
  {
  }
  
  inline bool is_active(husky_control_machine_states * _states);
  inline void activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_1_activate(_interpreter, _states);
  }
  inline void deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
  {
    husky_control_machine_state_1_deactivate(_interpreter, _states);
  }
  // Deactivators
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_1_deactivator;
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_59_deactivator;
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_697_deactivator;
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_766_deactivator;
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_879_deactivator;
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_881_deactivator;
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_898_deactivator;
    std::function<void(march::state_graph::interpreter_context*, husky_control_machine_states *)> group_899_deactivator;
};

struct husky_control_machine_states : public march::state_graph::states
{
  husky_control_machine_states(const husky_control_machine::parameters& _parameters) :
    parameters(_parameters),
    state_1_active(false),
    state_2_active(false),
    state_3_active(false),
    state_4_active(false),
    state_5_active(false),
    state_6_active(false),
    state_7_active(false),
    state_8_active(false),
    state_9_active(false),
    state_10_active(false),
    state_11_active(false),
    state_12_active(false),
    state_13_active(false),
    state_15_active(false),
    state_16_active(false),
    state_17_active(false),
    state_18_active(false),
    state_19_active(false),
    state_20_active(false),
    state_22_active(false),
    state_23_active(false),
    state_24_active(false),
    state_25_active(false),
    state_26_active(false),
    state_27_active(false),
    state_28_active(false),
    state_29_active(false),
    state_30_active(false)
  {
  }
  husky_control_machine::parameters parameters;
  inline husky_control_machine::parameters get_parameters() const { return parameters; }

  husky_control_machine_state_1 state_1;
  husky_control_machine_state_2 state_2;
  husky_control_machine_state_3 state_3;
  husky_control_machine_state_4 state_4;
  husky_control_machine_state_5 state_5;
  husky_control_machine_state_6 state_6;
  husky_control_machine_state_7 state_7;
  husky_control_machine_state_8 state_8;
  husky_control_machine_state_9 state_9;
  husky_control_machine_state_10 state_10;
  husky_control_machine_state_11 state_11;
  husky_control_machine_state_12 state_12;
  husky_control_machine_state_13 state_13;
  husky_control_machine_state_15 state_15;
  husky_control_machine_state_16 state_16;
  husky_control_machine_state_17 state_17;
  husky_control_machine_state_18 state_18;
  husky_control_machine_state_19 state_19;
  husky_control_machine_state_20 state_20;
  husky_control_machine_state_22 state_22;
  husky_control_machine_state_23 state_23;
  husky_control_machine_state_24 state_24;
  husky_control_machine_state_25 state_25;
  husky_control_machine_state_26 state_26;
  husky_control_machine_state_27 state_27;
  husky_control_machine_state_28 state_28;
  husky_control_machine_state_29 state_29;
  husky_control_machine_state_30 state_30;
  bool state_1_active:1;
  bool state_2_active:1;
  bool state_3_active:1;
  bool state_4_active:1;
  bool state_5_active:1;
  bool state_6_active:1;
  bool state_7_active:1;
  bool state_8_active:1;
  bool state_9_active:1;
  bool state_10_active:1;
  bool state_11_active:1;
  bool state_12_active:1;
  bool state_13_active:1;
  bool state_15_active:1;
  bool state_16_active:1;
  bool state_17_active:1;
  bool state_18_active:1;
  bool state_19_active:1;
  bool state_20_active:1;
  bool state_22_active:1;
  bool state_23_active:1;
  bool state_24_active:1;
  bool state_25_active:1;
  bool state_26_active:1;
  bool state_27_active:1;
  bool state_28_active:1;
  bool state_29_active:1;
  bool state_30_active:1;
  husky_control_machine_guard_14 guard_14;
  husky_control_machine_guard_21 guard_21;
  march::state_graph::message_output_connector<march_ros::sensor_msgs::joint_state> wheel_cmd_output_connector;
  inline void forward_message_wheel_cmd(march::state_graph::interpreter_context* /*_interpreter*/, husky_control_machine_states * /*_states*/, const march_ros::sensor_msgs::joint_state& _msg) { wheel_cmd_output_connector.send_message(_msg); }
  
  march::state_graph::event_output_connector position_reached_output_connector;
  inline void forward_event_position_reached(march::state_graph::interpreter_context* /*_interpreter*/, husky_control_machine_states * /*_states*/) { position_reached_output_connector.trigger_event(); }
  
  march::state_graph::event_output_connector waypoints_finished_output_connector;
  inline void forward_event_waypoints_finished(march::state_graph::interpreter_context* /*_interpreter*/, husky_control_machine_states * /*_states*/) { waypoints_finished_output_connector.trigger_event(); }
  
};


inline bool husky_control_machine_state_1::is_active(husky_control_machine_states* _states)
{
  return _states->state_1_active;
}
inline bool husky_control_machine_state_2::is_active(husky_control_machine_states* _states)
{
  return _states->state_2_active;
}
inline bool husky_control_machine_state_3::is_active(husky_control_machine_states* _states)
{
  return _states->state_3_active;
}
inline bool husky_control_machine_state_4::is_active(husky_control_machine_states* _states)
{
  return _states->state_4_active;
}
inline bool husky_control_machine_state_5::is_active(husky_control_machine_states* _states)
{
  return _states->state_5_active;
}
inline bool husky_control_machine_state_6::is_active(husky_control_machine_states* _states)
{
  return _states->state_6_active;
}
inline bool husky_control_machine_state_7::is_active(husky_control_machine_states* _states)
{
  return _states->state_7_active;
}
inline bool husky_control_machine_state_8::is_active(husky_control_machine_states* _states)
{
  return _states->state_8_active;
}
inline bool husky_control_machine_state_9::is_active(husky_control_machine_states* _states)
{
  return _states->state_9_active;
}
inline bool husky_control_machine_state_10::is_active(husky_control_machine_states* _states)
{
  return _states->state_10_active;
}
inline bool husky_control_machine_state_11::is_active(husky_control_machine_states* _states)
{
  return _states->state_11_active;
}
inline bool husky_control_machine_state_12::is_active(husky_control_machine_states* _states)
{
  return _states->state_12_active;
}
inline bool husky_control_machine_state_13::is_active(husky_control_machine_states* _states)
{
  return _states->state_13_active;
}
inline bool husky_control_machine_state_15::is_active(husky_control_machine_states* _states)
{
  return _states->state_15_active;
}
inline bool husky_control_machine_state_16::is_active(husky_control_machine_states* _states)
{
  return _states->state_16_active;
}
inline bool husky_control_machine_state_17::is_active(husky_control_machine_states* _states)
{
  return _states->state_17_active;
}
inline bool husky_control_machine_state_18::is_active(husky_control_machine_states* _states)
{
  return _states->state_18_active;
}
inline bool husky_control_machine_state_19::is_active(husky_control_machine_states* _states)
{
  return _states->state_19_active;
}
inline bool husky_control_machine_state_20::is_active(husky_control_machine_states* _states)
{
  return _states->state_20_active;
}
inline bool husky_control_machine_state_22::is_active(husky_control_machine_states* _states)
{
  return _states->state_22_active;
}
inline bool husky_control_machine_state_23::is_active(husky_control_machine_states* _states)
{
  return _states->state_23_active;
}
inline bool husky_control_machine_state_24::is_active(husky_control_machine_states* _states)
{
  return _states->state_24_active;
}
inline bool husky_control_machine_state_25::is_active(husky_control_machine_states* _states)
{
  return _states->state_25_active;
}
inline bool husky_control_machine_state_26::is_active(husky_control_machine_states* _states)
{
  return _states->state_26_active;
}
inline bool husky_control_machine_state_27::is_active(husky_control_machine_states* _states)
{
  return _states->state_27_active;
}
inline bool husky_control_machine_state_28::is_active(husky_control_machine_states* _states)
{
  return _states->state_28_active;
}
inline bool husky_control_machine_state_29::is_active(husky_control_machine_states* _states)
{
  return _states->state_29_active;
}
inline bool husky_control_machine_state_30::is_active(husky_control_machine_states* _states)
{
  return _states->state_30_active;
}
struct processing_graph_2
{
  template<typename _inputs_, typename _outputs_>
  inline static void apply(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _execution_context,
                    const husky_control_machine_state_2::parameters& _parameters,
                    const _inputs_& _inputs,
                    const _outputs_& _outputs,
                    uint64_t _time_length = std::numeric_limits<uint64_t>::max() )
  {

    ::march::std_lib::output_string_op::parameters parameters684;
    parameters684.value = "left";
    ::march::std_lib::output_string_op::inputs<::march::graph_ops::direct_input_adaptor> inputs684;
    ::march::std_lib::output_string_op::outputs<::march::graph_ops::direct_output_adaptor> outputs684;
    ::march::std_lib::output_string_op::apply(_execution_context,
        parameters684, inputs684, outputs684);
    ::march::std_lib::output_string_op::parameters parameters688;
    parameters688.value = "right";
    ::march::std_lib::output_string_op::inputs<::march::graph_ops::direct_input_adaptor> inputs688;
    ::march::std_lib::output_string_op::outputs<::march::graph_ops::direct_output_adaptor> outputs688;
    ::march::std_lib::output_string_op::apply(_execution_context,
        parameters688, inputs688, outputs688);
    ::march_ros::current_time_op::parameters parameters942;
    ::march_ros::current_time_op::inputs<::march::graph_ops::direct_input_adaptor> inputs942;
    ::march_ros::current_time_op::outputs<::march::graph_ops::direct_output_adaptor> outputs942;
    ::march_ros::current_time_op::apply(_execution_context,
        parameters942, inputs942, outputs942);
    ::air_lab1_march::linear_angular_to_left_right_velocities_op::parameters parameters943;
    parameters943.wheel_radius = 0.16;
    parameters943.left_right_distance = 0.55;
    ::air_lab1_march::linear_angular_to_left_right_velocities_op::inputs<::march::graph_ops::direct_input_adaptor> inputs943;
    inputs943.linear_velocity.set_adaptor(&_inputs.i4);
    inputs943.angular_velocity.set_adaptor(&_inputs.i5);
    ::air_lab1_march::linear_angular_to_left_right_velocities_op::outputs<::march::graph_ops::direct_output_adaptor> outputs943;
    ::air_lab1_march::linear_angular_to_left_right_velocities_op::apply(_execution_context,
        parameters943, inputs943, outputs943);
    ::march::list::list_append_op<march::std_msgs::stringlist, march::std_msgs::string, march::std_msgs::stringlist>::parameters parameters681;
    ::march::list::list_append_op<march::std_msgs::stringlist, march::std_msgs::string, march::std_msgs::stringlist>::inputs<::march::graph_ops::direct_input_adaptor> inputs681;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::stringlist> doa_fake_681_list;
    inputs681.list.set_adaptor(&doa_fake_681_list);
    inputs681.value.set_adaptor(&outputs684.value);
    ::march::list::list_append_op<march::std_msgs::stringlist, march::std_msgs::string, march::std_msgs::stringlist>::outputs<::march::graph_ops::direct_output_adaptor> outputs681;
    ::march::list::list_append_op<march::std_msgs::stringlist, march::std_msgs::string, march::std_msgs::stringlist>::apply(_execution_context,
        parameters681, inputs681, outputs681);
    ::march::control::pid_op::parameters parameters940;
    parameters940.Kp = _parameters.Kp;
    parameters940.Ki = _parameters.Ki;
    parameters940.Kd = _parameters.Kd;
    parameters940.i_min = -1;
    parameters940.i_max = 1;
    ::march::control::pid_op::inputs<::march::graph_ops::direct_input_adaptor> inputs940;
    inputs940.control.set_adaptor(&outputs943.right_velocity);
    inputs940.observation.set_adaptor(&_inputs.i0);
    inputs940.current_time.set_adaptor(&outputs942.t);
    inputs940.initial_previous_time.set_adaptor(&_inputs.i1);
    inputs940.__shadow_input_4.set_adaptor(&_inputs.__shadow_0);
    inputs940.__shadow_input_5.set_adaptor(&_inputs.__shadow_3);
    ::march::control::pid_op::outputs<::march::graph_ops::direct_output_adaptor> outputs940;
    ::march::control::pid_op::apply(_execution_context,
        parameters940, inputs940, outputs940);
    ::march::control::pid_op::parameters parameters941;
    parameters941.Kp = _parameters.Kp;
    parameters941.Ki = _parameters.Ki;
    parameters941.Kd = _parameters.Kd;
    parameters941.i_min = -1;
    parameters941.i_max = 1;
    ::march::control::pid_op::inputs<::march::graph_ops::direct_input_adaptor> inputs941;
    inputs941.control.set_adaptor(&outputs943.left_velocity);
    inputs941.observation.set_adaptor(&_inputs.i2);
    inputs941.current_time.set_adaptor(&outputs942.t);
    inputs941.initial_previous_time.set_adaptor(&_inputs.i3);
    inputs941.__shadow_input_4.set_adaptor(&_inputs.__shadow_5);
    inputs941.__shadow_input_5.set_adaptor(&_inputs.__shadow_8);
    ::march::control::pid_op::outputs<::march::graph_ops::direct_output_adaptor> outputs941;
    ::march::control::pid_op::apply(_execution_context,
        parameters941, inputs941, outputs941);
    ::march::list::list_append_op<march::std_msgs::stringlist, march::std_msgs::string, march::std_msgs::stringlist>::parameters parameters680;
    ::march::list::list_append_op<march::std_msgs::stringlist, march::std_msgs::string, march::std_msgs::stringlist>::inputs<::march::graph_ops::direct_input_adaptor> inputs680;
    inputs680.list.set_adaptor(&outputs681.list);
    inputs680.value.set_adaptor(&outputs688.value);
    ::march::list::list_append_op<march::std_msgs::stringlist, march::std_msgs::string, march::std_msgs::stringlist>::outputs<::march::graph_ops::direct_output_adaptor> outputs680;
    ::march::list::list_append_op<march::std_msgs::stringlist, march::std_msgs::string, march::std_msgs::stringlist>::apply(_execution_context,
        parameters680, inputs680, outputs680);
    ::march::list::list_append_op<march::std_msgs::float64list, march::std_msgs::float64, march::std_msgs::float64list>::parameters parameters690;
    ::march::list::list_append_op<march::std_msgs::float64list, march::std_msgs::float64, march::std_msgs::float64list>::inputs<::march::graph_ops::direct_input_adaptor> inputs690;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64list> doa_fake_690_list;
    inputs690.list.set_adaptor(&doa_fake_690_list);
    inputs690.value.set_adaptor(&outputs941.output);
    ::march::list::list_append_op<march::std_msgs::float64list, march::std_msgs::float64, march::std_msgs::float64list>::outputs<::march::graph_ops::direct_output_adaptor> outputs690;
    ::march::list::list_append_op<march::std_msgs::float64list, march::std_msgs::float64, march::std_msgs::float64list>::apply(_execution_context,
        parameters690, inputs690, outputs690);
    ::march::list::list_append_op<march::std_msgs::float64list, march::std_msgs::float64, march::std_msgs::float64list>::parameters parameters691;
    ::march::list::list_append_op<march::std_msgs::float64list, march::std_msgs::float64, march::std_msgs::float64list>::inputs<::march::graph_ops::direct_input_adaptor> inputs691;
    inputs691.list.set_adaptor(&outputs690.list);
    inputs691.value.set_adaptor(&outputs940.output);
    ::march::list::list_append_op<march::std_msgs::float64list, march::std_msgs::float64, march::std_msgs::float64list>::outputs<::march::graph_ops::direct_output_adaptor> outputs691;
    ::march::list::list_append_op<march::std_msgs::float64list, march::std_msgs::float64, march::std_msgs::float64list>::apply(_execution_context,
        parameters691, inputs691, outputs691);
    ::march_ros::sensor_msgs::tools::joint_state_assemble_op::parameters parameters408;
    ::march_ros::sensor_msgs::tools::joint_state_assemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs408;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::header> doa_fake_408_header;
    inputs408.header.set_adaptor(&doa_fake_408_header);
    inputs408.name.set_adaptor(&outputs680.list);
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64list> doa_fake_408_position;
    inputs408.position.set_adaptor(&doa_fake_408_position);
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64list> doa_fake_408_velocity;
    inputs408.velocity.set_adaptor(&doa_fake_408_velocity);
    inputs408.effort.set_adaptor(&outputs691.list);
    ::march_ros::sensor_msgs::tools::joint_state_assemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs408;
    ::march_ros::sensor_msgs::tools::joint_state_assemble_op::apply(_execution_context,
        parameters408, inputs408, outputs408);

  if(outputs408.message.has_received_value())
  {
    _outputs.o0.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march_ros::sensor_msgs::joint_state>(&outputs408.message ).get_last_value());
  }
  if(outputs940.__shadow_output_1.has_received_value())
  {
    _outputs.__shadow_1.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs940.__shadow_output_1 ).get_last_value());
  }
  if(outputs940.__shadow_output_2.has_received_value())
  {
    _outputs.__shadow_2.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs940.__shadow_output_2 ).get_last_value());
  }
  if(outputs940.__shadow_output_3.has_received_value())
  {
    _outputs.__shadow_4.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs940.__shadow_output_3 ).get_last_value());
  }
  if(outputs941.__shadow_output_1.has_received_value())
  {
    _outputs.__shadow_6.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs941.__shadow_output_1 ).get_last_value());
  }
  if(outputs941.__shadow_output_2.has_received_value())
  {
    _outputs.__shadow_7.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs941.__shadow_output_2 ).get_last_value());
  }
  if(outputs941.__shadow_output_3.has_received_value())
  {
    _outputs.__shadow_9.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs941.__shadow_output_3 ).get_last_value());
  }
  }
};
/**************
 * Definition of op state 'controller' 
 */


void husky_control_machine_state_2_output_connector_o0::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::sensor_msgs::joint_state& _message) const
{
  
  _context.get_states()->forward_message_wheel_cmd(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_2_output_connector___shadow_1::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_2.receive_message___shadow_0(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_2_output_connector___shadow_2::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_2.receive_message_i1(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_2_output_connector___shadow_4::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_2.receive_message___shadow_3(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_2_output_connector___shadow_6::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_2.receive_message___shadow_5(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_2_output_connector___shadow_7::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_2.receive_message_i3(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_2_output_connector___shadow_9::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_2.receive_message___shadow_8(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_2_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 2));
#endif
  _states->state_2_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_1.group_1_deactivator = &husky_control_machine_state_2_deactivate;

  // Then call the activity
  husky_control_machine_state_2::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_2_event_handler), husky_control_machine_state_2::get_parameters(_states->get_parameters()), _states->state_2.inputs, _states->state_2.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_2_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_2_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 2));
#endif
  _states->state_2_active = false;
  
}


void husky_control_machine_state_2_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of op state 'initial time'  with activity 'march_ros/current_time' 
 */


void husky_control_machine_state_3_output_connector_t::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_2.receive_message_i1(_context.get_interpreter(), _context.get_states(), _message);
  _context.get_states()->state_2.receive_message_i3(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_3_output_connector_ns::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::unsigned_integer32& _message) const
{
  
}
  
void husky_control_machine_state_3_output_connector_s::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::unsigned_integer32& _message) const
{
  
}
  

void husky_control_machine_state_3_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 3));
#endif
  _states->state_3_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_1.group_1_deactivator = &husky_control_machine_state_3_deactivate;

  // Then call the activity
  husky_control_machine_state_3::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_3_event_handler), husky_control_machine_state_3::get_parameters(_states->get_parameters()), _states->state_3.inputs, _states->state_3.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_3_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_3_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 3));
#endif
  _states->state_3_active = false;
  
}


void husky_control_machine_state_3_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
  husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 1:
        march::state_graph::transition_helper(&states->state_3, 3, &states->state_2, 2, _interpreter, states);
      break;
    default:
      break;
  }
}

/**************
 * Definition of op state 'idle'  with activity 'march_std_lib/output_float64' 
 */


void husky_control_machine_state_5_output_connector_value::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_2.receive_message_i4(_context.get_interpreter(), _context.get_states(), _message);
  _context.get_states()->state_28.receive_message_value(_context.get_interpreter(), _context.get_states(), _message);
    _context.get_interpreter()->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_28, 28, &states->state_28, 28, _context, states );
  }, tasks_machine::system_time::now()));
  _context.get_states()->state_2.receive_message_i5(_context.get_interpreter(), _context.get_states(), _message);
  _context.get_states()->state_29.receive_message_value(_context.get_interpreter(), _context.get_states(), _message);
    _context.get_interpreter()->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_29, 29, &states->state_29, 29, _context, states );
  }, tasks_machine::system_time::now()));
}
  

void husky_control_machine_state_5_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 5));
#endif
  _states->state_5_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_4.group_151_deactivator = &husky_control_machine_state_5_deactivate;

  // Then call the activity
  husky_control_machine_state_5::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_5_event_handler), husky_control_machine_state_5::get_parameters(_states->get_parameters()), _states->state_5.inputs, _states->state_5.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_5_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_5_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 5));
#endif
  _states->state_5_active = false;
  
}


void husky_control_machine_state_5_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

struct processing_graph_8
{
  template<typename _inputs_, typename _outputs_>
  inline static void apply(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _execution_context,
                    const husky_control_machine_state_8::parameters& _parameters,
                    const _inputs_& _inputs,
                    const _outputs_& _outputs,
                    uint64_t _time_length = std::numeric_limits<uint64_t>::max() )
  {

    ::march_ros::geometry_msgs::tools::twist_dissassemble_op::parameters parameters17;
    ::march_ros::geometry_msgs::tools::twist_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs17;
    inputs17.message.set_adaptor(&_inputs.i0);
    ::march_ros::geometry_msgs::tools::twist_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs17;
    ::march_ros::geometry_msgs::tools::twist_dissassemble_op::apply(_execution_context,
        parameters17, inputs17, outputs17);
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::parameters parameters24;
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs24;
    inputs24.message.set_adaptor(&outputs17.linear);
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs24;
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::apply(_execution_context,
        parameters24, inputs24, outputs24);
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::parameters parameters25;
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs25;
    inputs25.message.set_adaptor(&outputs17.angular);
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs25;
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::apply(_execution_context,
        parameters25, inputs25, outputs25);

  if(outputs24.x.has_received_value())
  {
    _outputs.o0.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs24.x ).get_last_value());
  }
  if(outputs25.z.has_received_value())
  {
    _outputs.o1.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs25.z ).get_last_value());
  }
  }
};
/**************
 * Definition of op state 'decompose velocity' 
 */


void husky_control_machine_state_8_output_connector_o0::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_6.forward_message_linear(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_8_output_connector_o1::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_6.forward_message_angular(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_8_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 8));
#endif
  _states->state_8_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_7.group_1_deactivator = &husky_control_machine_state_8_deactivate;

  // Then call the activity
  _interpreter->enqueue_task(new march::state_graph::op_state_queued_task<husky_control_machine_state_8, husky_control_machine_states>(_interpreter, _states, &_states->state_8, "{65faa39b-6ebb-4752-bd8c-52bc4dac3d19}"), tasks_machine::priority::medium);
}
void husky_control_machine_state_8_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 8));
#endif
  _states->state_8_active = false;
  
}


void husky_control_machine_state_8_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of super state 'untitled'
 */

void husky_control_machine_state_7_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 7));
#endif
  _states->state_7_active = true;
  
    husky_control_machine_state_8_activate(_interpreter, _states);
}
void husky_control_machine_state_7_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 7));
#endif
  _states->state_7_active = false;
  
    _states->state_7.group_1_deactivator(_interpreter, _states);
}


void husky_control_machine_state_7_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of activity state 'velocity mode' with component 'velocity_controller'
 */



void husky_control_machine_state_6::forward_message_linear(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message)
{
  
  _states->state_2.receive_message_i4(_interpreter, _states, _message);
  _states->state_28.receive_message_value(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_28, 28, &states->state_28, 28, _context, states );
  }, tasks_machine::system_time::now()));
}

void husky_control_machine_state_6::forward_message_angular(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message)
{
  
  _states->state_2.receive_message_i5(_interpreter, _states, _message);
  _states->state_29.receive_message_value(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_29, 29, &states->state_29, 29, _context, states );
  }, tasks_machine::system_time::now()));
}

void husky_control_machine_state_6::forward_event_timeout(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
}

void husky_control_machine_state_6::forward_event_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
}


// State class definition

husky_control_machine_state_6::husky_control_machine_state_6()
  
{
}

void husky_control_machine_state_6_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 6));
#endif
  _states->state_6_active = true;
  
  
  _states->state_4.group_151_deactivator = &husky_control_machine_state_6_deactivate;
  
  husky_control_machine_state_7_activate(_interpreter, _states);
}

void husky_control_machine_state_6_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 6));
#endif
  _states->state_6_active = true;

  
  
  husky_control_machine_state_7_deactivate(_interpreter, _states);
}

void husky_control_machine_state_6_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{
  husky_control_machine_states * states = reinterpret_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 0:
      states->state_6.forward_event_timeout(_interpreter, states);
      break;
    case 1:
      states->state_6.forward_event_finished(_interpreter, states);
      break;
    default:
      break;
  }
}


void husky_control_machine_state_6::receive_message_cmd_vel(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _message)
{
  
  _states->state_8.receive_message_i0(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_7, 7, &states->state_7, 7, _context, states );
  }, tasks_machine::system_time::now()));
}
  
// Guards' is_guarded

/**************
 * Definition of op state 'reach point'  with activity 'air_lab1_march/reach_point' 
 */


void husky_control_machine_state_11_output_connector_linear::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_9.forward_message_vel_linear(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_11_output_connector_angular::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_9.forward_message_vel_angular(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_11_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 11));
#endif
  _states->state_11_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_10.group_1_deactivator = &husky_control_machine_state_11_deactivate;

  // Then call the activity
  husky_control_machine_state_11::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_11_event_handler), husky_control_machine_state_11::get_parameters(_states->get_parameters()), _states->state_11.inputs, _states->state_11.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_11_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_11_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 11));
#endif
  _states->state_11_active = false;
  
}


void husky_control_machine_state_11_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
  husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 1:
        march::state_graph::transition_helper(&states->state_11, 11, &states->state_13, 13, _interpreter, states, &states->guard_14);
      break;
    default:
      break;
  }
}

/**************
 * Definition of op state 'idle'  with activity 'march_std_lib/output_float64' 
 */


void husky_control_machine_state_12_output_connector_value::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_9.forward_message_vel_linear(_context.get_interpreter(), _context.get_states(), _message);
  _context.get_states()->state_9.forward_message_vel_angular(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_12_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 12));
#endif
  _states->state_12_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_10.group_1_deactivator = &husky_control_machine_state_12_deactivate;

  // Then call the activity
  husky_control_machine_state_12::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_12_event_handler), husky_control_machine_state_12::get_parameters(_states->get_parameters()), _states->state_12.inputs, _states->state_12.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_12_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_12_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 12));
#endif
  _states->state_12_active = false;
  
}


void husky_control_machine_state_12_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of op state 'point_reached' 
 */



void husky_control_machine_state_13_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 13));
#endif
  _states->state_13_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_10.group_1_deactivator = &husky_control_machine_state_13_deactivate;

  // Then call the activity
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_13_event_handler, tasks_machine::system_time::now()));
}
void husky_control_machine_state_13_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 13));
#endif
  _states->state_13_active = false;
  
}


void husky_control_machine_state_13_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
  husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 1:
        march::state_graph::transition_helper(&states->state_13, 13, &states->state_12, 12, _interpreter, states);
        states->state_9.forward_event_point_reached(_interpreter, states);
      break;
    default:
      break;
  }
}

/**************
 * Definition of super state 'reach_point_controller'
 */

void husky_control_machine_state_10_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 10));
#endif
  _states->state_10_active = true;
  
    husky_control_machine_state_12_activate(_interpreter, _states);
}
void husky_control_machine_state_10_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 10));
#endif
  _states->state_10_active = false;
  
    _states->state_10.group_1_deactivator(_interpreter, _states);
}


void husky_control_machine_state_10_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of activity state 'reach_point_controller' with component 'reach_point_controller'
 */



void husky_control_machine_state_9::forward_message_vel_linear(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message)
{
  
  _states->state_2.receive_message_i4(_interpreter, _states, _message);
  _states->state_28.receive_message_value(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_28, 28, &states->state_28, 28, _context, states );
  }, tasks_machine::system_time::now()));
}

void husky_control_machine_state_9::forward_message_vel_angular(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message)
{
  
  _states->state_2.receive_message_i5(_interpreter, _states, _message);
  _states->state_29.receive_message_value(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_29, 29, &states->state_29, 29, _context, states );
  }, tasks_machine::system_time::now()));
}

void husky_control_machine_state_9::forward_event_timeout(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
}

void husky_control_machine_state_9::forward_event_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
}

void husky_control_machine_state_9::forward_event_point_reached(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
  _states->forward_event_position_reached(_interpreter, _states);
}


// State class definition

husky_control_machine_state_9::husky_control_machine_state_9()
  
{
}

void husky_control_machine_state_9_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 9));
#endif
  _states->state_9_active = true;
  
  
  _states->state_4.group_151_deactivator = &husky_control_machine_state_9_deactivate;
  
  husky_control_machine_state_10_activate(_interpreter, _states);
}

void husky_control_machine_state_9_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 9));
#endif
  _states->state_9_active = true;

  
  
  husky_control_machine_state_10_deactivate(_interpreter, _states);
}

void husky_control_machine_state_9_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{
  husky_control_machine_states * states = reinterpret_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 0:
      states->state_9.forward_event_timeout(_interpreter, states);
      break;
    case 1:
      states->state_9.forward_event_finished(_interpreter, states);
      break;
    default:
      break;
  }
}


void husky_control_machine_state_9::receive_message_cmd_pose(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose_stamped& _message)
{
  
  _states->state_11.receive_message_cmd_position(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_12, 12, &states->state_11, 11, _context, states );
  }, tasks_machine::system_time::now()));
  _states->guard_14.receive_message_target(_message);
}
  
void husky_control_machine_state_9::receive_message_max_velocity(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _message)
{
  
  _states->state_11.receive_message_cmd_max_vel(_interpreter, _states, _message);
}
  
void husky_control_machine_state_9::receive_message_current_pose(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose& _message)
{
  
  _states->state_11.receive_message_current_position(_interpreter, _states, _message);
  _states->guard_14.receive_message_position(_message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_11, 11, &states->state_11, 11, _context, states );
  }, tasks_machine::system_time::now()));
}
  
// Guards' is_guarded

bool husky_control_machine_guard_14::is_guarded(husky_control_machine_states * _states)
{
  return not(std::abs(_states->guard_14.position.position.x-_states->guard_14.target.pose.position.x)<0.1&&std::abs(_states->guard_14.position.position.y-_states->guard_14.target.pose.position.y)<0.1);
}

/**************
 * Definition of op state 'idle'  with activity 'march_std_lib/output_float64' 
 */


void husky_control_machine_state_17_output_connector_value::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_15.forward_message_linear(_context.get_interpreter(), _context.get_states(), _message);
  _context.get_states()->state_15.forward_message_angular(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_17_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 17));
#endif
  _states->state_17_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_16.group_1_deactivator = &husky_control_machine_state_17_deactivate;

  // Then call the activity
  husky_control_machine_state_17::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_17_event_handler), husky_control_machine_state_17::get_parameters(_states->get_parameters()), _states->state_17.inputs, _states->state_17.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_17_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_17_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 17));
#endif
  _states->state_17_active = false;
  
}


void husky_control_machine_state_17_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of op state 'decompose'  with activity 'ros_nav_msgs_tools/path_dissassemble' 
 */


void husky_control_machine_state_18_output_connector_header::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::header& _message) const
{
  
}
  
void husky_control_machine_state_18_output_connector_poses::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::geometry_msgs::pose_stamped_list& _message) const
{
  
  _context.get_states()->state_19.receive_message_list(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_18_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 18));
#endif
  _states->state_18_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_16.group_1_deactivator = &husky_control_machine_state_18_deactivate;

  // Then call the activity
  husky_control_machine_state_18::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_18_event_handler), husky_control_machine_state_18::get_parameters(_states->get_parameters()), _states->state_18.inputs, _states->state_18.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_18_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_18_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 18));
#endif
  _states->state_18_active = false;
  
}


void husky_control_machine_state_18_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
  husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 1:
        march::state_graph::transition_helper(&states->state_18, 18, &states->state_19, 19, _interpreter, states);
      break;
    default:
      break;
  }
}

/**************
 * Definition of op state 'pop'  with activity 'march_list/list_pop' 
 */


void husky_control_machine_state_19_output_connector_list::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::geometry_msgs::pose_stamped_list& _message) const
{
  
  _context.get_states()->state_19.receive_message_list(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_19_output_connector_value::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::geometry_msgs::pose_stamped& _message) const
{
  
    _context.get_interpreter()->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_19, 19, &states->state_20, 20, _context, states );
  }, tasks_machine::system_time::now()));
  _context.get_states()->guard_21.receive_message_target(_message);
  _context.get_states()->state_20.receive_message_cmd_position(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_19_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 19));
#endif
  _states->state_19_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_16.group_1_deactivator = &husky_control_machine_state_19_deactivate;

  // Then call the activity
  husky_control_machine_state_19::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_19_event_handler), husky_control_machine_state_19::get_parameters(_states->get_parameters()), _states->state_19.inputs, _states->state_19.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_19_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_19_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 19));
#endif
  _states->state_19_active = false;
  
}


void husky_control_machine_state_19_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
  husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 2:
        march::state_graph::transition_helper(&states->state_16, 16, &states->state_16, 16, _interpreter, states);
        states->state_15.forward_event_waypoints_finished(_interpreter, states);
      break;
    default:
      break;
  }
}

/**************
 * Definition of op state 'reach point controller'  with activity 'air_lab1_march/reach_point' 
 */


void husky_control_machine_state_20_output_connector_linear::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_15.forward_message_linear(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_20_output_connector_angular::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
  _context.get_states()->state_15.forward_message_angular(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_20_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 20));
#endif
  _states->state_20_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_16.group_1_deactivator = &husky_control_machine_state_20_deactivate;

  // Then call the activity
  husky_control_machine_state_20::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_20_event_handler), husky_control_machine_state_20::get_parameters(_states->get_parameters()), _states->state_20.inputs, _states->state_20.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_20_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_20_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 20));
#endif
  _states->state_20_active = false;
  
}


void husky_control_machine_state_20_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
  husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 1:
        march::state_graph::transition_helper(&states->state_20, 20, &states->state_19, 19, _interpreter, states, &states->guard_21);
      break;
    case -1:
        march::state_graph::transition_helper(&states->state_20, 20, &states->state_19, 19, _interpreter, states, &states->guard_21);
      break;
    default:
      break;
  }
}

/**************
 * Definition of super state 'untitled'
 */

void husky_control_machine_state_16_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 16));
#endif
  _states->state_16_active = true;
  
    husky_control_machine_state_17_activate(_interpreter, _states);
}
void husky_control_machine_state_16_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 16));
#endif
  _states->state_16_active = false;
  
    _states->state_16.group_1_deactivator(_interpreter, _states);
}


void husky_control_machine_state_16_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of activity state 'waypoint_controller' with component 'waypoints_controller'
 */



void husky_control_machine_state_15::forward_message_linear(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message)
{
  
  _states->state_2.receive_message_i4(_interpreter, _states, _message);
  _states->state_28.receive_message_value(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_28, 28, &states->state_28, 28, _context, states );
  }, tasks_machine::system_time::now()));
}

void husky_control_machine_state_15::forward_message_angular(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::std_msgs::float64& _message)
{
  
  _states->state_2.receive_message_i5(_interpreter, _states, _message);
  _states->state_29.receive_message_value(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_29, 29, &states->state_29, 29, _context, states );
  }, tasks_machine::system_time::now()));
}

void husky_control_machine_state_15::forward_event_timeout(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
}

void husky_control_machine_state_15::forward_event_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
}

void husky_control_machine_state_15::forward_event_waypoints_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
  _states->forward_event_waypoints_finished(_interpreter, _states);
}


// State class definition

husky_control_machine_state_15::husky_control_machine_state_15()
  
{
}

void husky_control_machine_state_15_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 15));
#endif
  _states->state_15_active = true;
  
  
  _states->state_4.group_151_deactivator = &husky_control_machine_state_15_deactivate;
  
  husky_control_machine_state_16_activate(_interpreter, _states);
}

void husky_control_machine_state_15_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 15));
#endif
  _states->state_15_active = true;

  
  
  husky_control_machine_state_16_deactivate(_interpreter, _states);
}

void husky_control_machine_state_15_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{
  husky_control_machine_states * states = reinterpret_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 0:
      states->state_15.forward_event_timeout(_interpreter, states);
      break;
    case 1:
      states->state_15.forward_event_finished(_interpreter, states);
      break;
    default:
      break;
  }
}


void husky_control_machine_state_15::receive_message_waypoints(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::nav_msgs::path& _message)
{
  
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_16, 16, &states->state_16, 16, _context, states );
  }, tasks_machine::system_time::now()));
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_17, 17, &states->state_18, 18, _context, states );
  }, tasks_machine::system_time::now()));
  _states->state_18.receive_message_message(_interpreter, _states, _message);
}
  
void husky_control_machine_state_15::receive_message_max_velocity(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::twist& _message)
{
  
  _states->state_20.receive_message_cmd_max_vel(_interpreter, _states, _message);
}
  
void husky_control_machine_state_15::receive_message_current_pose(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march_ros::geometry_msgs::pose& _message)
{
  
  _states->guard_21.receive_message_position(_message);
  _states->state_20.receive_message_current_position(_interpreter, _states, _message);
    _interpreter->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_20, 20, &states->state_20, 20, _context, states );
  }, tasks_machine::system_time::now()));
}
  
// Guards' is_guarded

bool husky_control_machine_guard_21::is_guarded(husky_control_machine_states * _states)
{
  return not(std::abs(_states->guard_21.position.position.x-_states->guard_21.target.pose.position.x)<0.1&&std::abs(_states->guard_21.position.position.y-_states->guard_21.target.pose.position.y)<0.1);
}

/**************
 * Definition of super state 'control mode'
 */

void husky_control_machine_state_4_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 4));
#endif
  _states->state_4_active = true;
  
  _states->state_1.group_59_deactivator = &husky_control_machine_state_4_deactivate;
    husky_control_machine_state_5_activate(_interpreter, _states);
}
void husky_control_machine_state_4_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 4));
#endif
  _states->state_4_active = false;
  
    _states->state_4.group_151_deactivator(_interpreter, _states);
}


void husky_control_machine_state_4_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

struct processing_graph_22
{
  template<typename _inputs_, typename _outputs_>
  inline static void apply(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _execution_context,
                    const husky_control_machine_state_22::parameters& _parameters,
                    const _inputs_& _inputs,
                    const _outputs_& _outputs,
                    uint64_t _time_length = std::numeric_limits<uint64_t>::max() )
  {

    ::march_ros::sensor_msgs::tools::joint_state_dissassemble_op::parameters parameters702;
    ::march_ros::sensor_msgs::tools::joint_state_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs702;
    inputs702.message.set_adaptor(&_inputs.i0);
    ::march_ros::sensor_msgs::tools::joint_state_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs702;
    ::march_ros::sensor_msgs::tools::joint_state_dissassemble_op::apply(_execution_context,
        parameters702, inputs702, outputs702);
    ::march::list::list_at_op<march::std_msgs::float64list, march::std_msgs::float64>::parameters parameters700;
    ::march::list::list_at_op<march::std_msgs::float64list, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs700;
    inputs700.list.set_adaptor(&outputs702.velocity);
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::unsigned_integer64> doa_fake_700_index(march::std_msgs::unsigned_integer64(0));
    inputs700.index.set_adaptor(&doa_fake_700_index);
    ::march::list::list_at_op<march::std_msgs::float64list, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs700;
    ::march::graph_ops::functional_execution_context functional_execution_context_700([_execution_context](uint32_t _event){
      switch(_event)
      {
        default:
          break;
      }
    }, [_execution_context](tasks_machine::abstract_queued_task* _job, tasks_machine::priority _priority) -> tasks_machine::queued_task_status
    {
      return _execution_context.enqueue_task(_job, _priority);
    });
    ::march::list::list_at_op<march::std_msgs::float64list, march::std_msgs::float64>::apply(functional_execution_context_700,
        parameters700, inputs700, outputs700);
    ::march::list::list_at_op<march::std_msgs::float64list, march::std_msgs::float64>::parameters parameters701;
    ::march::list::list_at_op<march::std_msgs::float64list, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs701;
    inputs701.list.set_adaptor(&outputs702.velocity);
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::unsigned_integer64> doa_fake_701_index(march::std_msgs::unsigned_integer64(1));
    inputs701.index.set_adaptor(&doa_fake_701_index);
    ::march::list::list_at_op<march::std_msgs::float64list, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs701;
    ::march::graph_ops::functional_execution_context functional_execution_context_701([_execution_context](uint32_t _event){
      switch(_event)
      {
        default:
          break;
      }
    }, [_execution_context](tasks_machine::abstract_queued_task* _job, tasks_machine::priority _priority) -> tasks_machine::queued_task_status
    {
      return _execution_context.enqueue_task(_job, _priority);
    });
    ::march::list::list_at_op<march::std_msgs::float64list, march::std_msgs::float64>::apply(functional_execution_context_701,
        parameters701, inputs701, outputs701);

  if(outputs700.value.has_received_value())
  {
    _outputs.o0.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs700.value ).get_last_value());
  }
  if(outputs701.value.has_received_value())
  {
    _outputs.o1.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::std_msgs::float64>(&outputs701.value ).get_last_value());
  }
  }
};
/**************
 * Definition of op state 'extract wheel velocities' 
 */


void husky_control_machine_state_22_output_connector_o0::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
    _context.get_interpreter()->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_2, 2, &states->state_2, 2, _context, states );
  }, tasks_machine::system_time::now()));
  _context.get_states()->state_2.receive_message_i2(_context.get_interpreter(), _context.get_states(), _message);
}
  
void husky_control_machine_state_22_output_connector_o1::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::std_msgs::float64& _message) const
{
  
    _context.get_interpreter()->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_2, 2, &states->state_2, 2, _context, states );
  }, tasks_machine::system_time::now()));
  _context.get_states()->state_2.receive_message_i0(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_22_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 22));
#endif
  _states->state_22_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_1.group_697_deactivator = &husky_control_machine_state_22_deactivate;

  // Then call the activity
  _interpreter->enqueue_task(new march::state_graph::op_state_queued_task<husky_control_machine_state_22, husky_control_machine_states>(_interpreter, _states, &_states->state_22, "{421001d5-b9cd-4520-9048-2fcb905c1b5e}"), tasks_machine::priority::medium);
}
void husky_control_machine_state_22_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 22));
#endif
  _states->state_22_active = false;
  
}


void husky_control_machine_state_22_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

struct processing_graph_23
{
  template<typename _inputs_, typename _outputs_>
  inline static void apply(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _execution_context,
                    const husky_control_machine_state_23::parameters& _parameters,
                    const _inputs_& _inputs,
                    const _outputs_& _outputs,
                    uint64_t _time_length = std::numeric_limits<uint64_t>::max() )
  {

    ::march_ros::nav_msgs::tools::odometry_dissassemble_op::parameters parameters769;
    ::march_ros::nav_msgs::tools::odometry_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs769;
    inputs769.message.set_adaptor(&_inputs.i0);
    ::march_ros::nav_msgs::tools::odometry_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs769;
    ::march_ros::nav_msgs::tools::odometry_dissassemble_op::apply(_execution_context,
        parameters769, inputs769, outputs769);
    ::march_ros::geometry_msgs::tools::pose_with_covariance_dissassemble_op::parameters parameters770;
    ::march_ros::geometry_msgs::tools::pose_with_covariance_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs770;
    inputs770.message.set_adaptor(&outputs769.pose);
    ::march_ros::geometry_msgs::tools::pose_with_covariance_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs770;
    ::march_ros::geometry_msgs::tools::pose_with_covariance_dissassemble_op::apply(_execution_context,
        parameters770, inputs770, outputs770);

  if(outputs770.pose.has_received_value())
  {
    _outputs.o0.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march_ros::geometry_msgs::pose>(&outputs770.pose ).get_last_value());
  }
  }
};
/**************
 * Definition of op state 'dissassemble odometry message' 
 */


void husky_control_machine_state_23_output_connector_o0::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march_ros::geometry_msgs::pose& _message) const
{
  
  _context.get_states()->state_9.receive_message_current_pose(_context.get_interpreter(), _context.get_states(), _message);
  _context.get_states()->state_15.receive_message_current_pose(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_23_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 23));
#endif
  _states->state_23_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_1.group_766_deactivator = &husky_control_machine_state_23_deactivate;

  // Then call the activity
  _interpreter->enqueue_task(new march::state_graph::op_state_queued_task<husky_control_machine_state_23, husky_control_machine_states>(_interpreter, _states, &_states->state_23, "{31577209-0e60-40ff-9082-41690c7d39bb}"), tasks_machine::priority::medium);
}
void husky_control_machine_state_23_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 23));
#endif
  _states->state_23_active = false;
  
}


void husky_control_machine_state_23_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

struct processing_graph_26
{
  template<typename _inputs_, typename _outputs_>
  inline static void apply(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _execution_context,
                    const husky_control_machine_state_26::parameters& _parameters,
                    const _inputs_& _inputs,
                    const _outputs_& _outputs,
                    uint64_t _time_length = std::numeric_limits<uint64_t>::max() )
  {

    ::march::debugger::monitor_create_op::parameters parameters4;
    ::march::debugger::monitor_create_op::inputs<::march::graph_ops::direct_input_adaptor> inputs4;
    ::march::debugger::monitor_create_op::outputs<::march::graph_ops::direct_output_adaptor> outputs4;
    ::march::debugger::monitor_create_op::apply(_execution_context,
        parameters4, inputs4, outputs4);
    ::march::debugger::networking::setup_server_connection_op::parameters parameters5;
    parameters5.port = 2001;
    ::march::debugger::networking::setup_server_connection_op::inputs<::march::graph_ops::direct_input_adaptor> inputs5;
    inputs5.monitor.set_adaptor(&outputs4.monitor);
    ::march::debugger::networking::setup_server_connection_op::outputs<::march::graph_ops::direct_output_adaptor> outputs5;
    ::march::debugger::networking::setup_server_connection_op::apply(_execution_context,
        parameters5, inputs5, outputs5);

  if(outputs5.monitor.has_received_value())
  {
    _outputs.o0.send_message(_execution_context, ::march::graph_ops::direct_input_adaptor<march::debugger::msgs::monitor>(&outputs5.monitor ).get_last_value());
  }
  }
};
/**************
 * Definition of op state 'start monitor' 
 */


void husky_control_machine_state_26_output_connector_o0::send_message(const march::state_graph::op_state_execution_context<husky_control_machine_states>& _context, const march::debugger::msgs::monitor& _message) const
{
  
  _context.get_states()->state_27.receive_message_monitor(_context.get_interpreter(), _context.get_states(), _message);
  _context.get_states()->state_24.forward_message_monitor(_context.get_interpreter(), _context.get_states(), _message);
}
  

void husky_control_machine_state_26_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 26));
#endif
  _states->state_26_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_25.group_1_deactivator = &husky_control_machine_state_26_deactivate;

  // Then call the activity
  _interpreter->enqueue_task(new march::state_graph::op_state_queued_task<husky_control_machine_state_26, husky_control_machine_states>(_interpreter, _states, &_states->state_26, "{492e656d-b8ed-465c-bba3-fc0d61af9ba4}"), tasks_machine::priority::medium);
}
void husky_control_machine_state_26_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 26));
#endif
  _states->state_26_active = false;
  
}


void husky_control_machine_state_26_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
  husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 1:
        march::state_graph::transition_helper(&states->state_26, 26, &states->state_27, 27, _interpreter, states);
      break;
    default:
      break;
  }
}

/**************
 * Definition of op state 'process'  with activity 'march_debugger/monitor_process' 
 */



void husky_control_machine_state_27_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 27));
#endif
  _states->state_27_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_25.group_1_deactivator = &husky_control_machine_state_27_deactivate;

  // Then call the activity
  _states->state_27.rt_task.setup_execution_context(_interpreter, _states, &husky_control_machine_state_27_event_handler);
  _interpreter->schedule_task(&_states->state_27.rt_task, 1, 0); 
}
void husky_control_machine_state_27_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 27));
#endif
  _states->state_27_active = false;
  
  _interpreter->schedule_task(nullptr, 1, 0); 
}


void husky_control_machine_state_27_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of super state 'networking_debugger'
 */

void husky_control_machine_state_25_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 25));
#endif
  _states->state_25_active = true;
  
    husky_control_machine_state_26_activate(_interpreter, _states);
}
void husky_control_machine_state_25_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 25));
#endif
  _states->state_25_active = false;
  
    _states->state_25.group_1_deactivator(_interpreter, _states);
}


void husky_control_machine_state_25_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of activity state 'debugger' with component 'debugger'
 */



void husky_control_machine_state_24::forward_message_monitor(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states, const march::debugger::msgs::monitor& _message)
{
  
  _states->state_28.receive_message_monitor(_interpreter, _states, _message);
  _states->state_29.receive_message_monitor(_interpreter, _states, _message);
  _states->state_30.receive_message_monitor(_interpreter, _states, _message);
}

void husky_control_machine_state_24::forward_event_timeout(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
}

void husky_control_machine_state_24::forward_event_finished(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
  
}


// State class definition

husky_control_machine_state_24::husky_control_machine_state_24()
  
{
}

void husky_control_machine_state_24_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 24));
#endif
  _states->state_24_active = true;
  
  
  _states->state_1.group_879_deactivator = &husky_control_machine_state_24_deactivate;
  
  husky_control_machine_state_25_activate(_interpreter, _states);
}

void husky_control_machine_state_24_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 24));
#endif
  _states->state_24_active = true;

  
  
  husky_control_machine_state_25_deactivate(_interpreter, _states);
}

void husky_control_machine_state_24_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{
  husky_control_machine_states * states = reinterpret_cast<husky_control_machine_states *>(_states);
  switch(_event)
  {
    case 0:
      states->state_24.forward_event_timeout(_interpreter, states);
      break;
    case 1:
      states->state_24.forward_event_finished(_interpreter, states);
      break;
    default:
      break;
  }
}


// Guards' is_guarded

/**************
 * Definition of op state 'send'  with activity 'march_debugger/send_message' 
 */



void husky_control_machine_state_28_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 28));
#endif
  _states->state_28_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_1.group_881_deactivator = &husky_control_machine_state_28_deactivate;

  // Then call the activity
  husky_control_machine_state_28::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_28_event_handler), husky_control_machine_state_28::get_parameters(_states->get_parameters()), _states->state_28.inputs, _states->state_28.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_28_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_28_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 28));
#endif
  _states->state_28_active = false;
  
}


void husky_control_machine_state_28_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of op state 'send'  with activity 'march_debugger/send_message' 
 */



void husky_control_machine_state_29_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 29));
#endif
  _states->state_29_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_1.group_898_deactivator = &husky_control_machine_state_29_deactivate;

  // Then call the activity
  husky_control_machine_state_29::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_29_event_handler), husky_control_machine_state_29::get_parameters(_states->get_parameters()), _states->state_29.inputs, _states->state_29.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_29_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_29_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 29));
#endif
  _states->state_29_active = false;
  
}


void husky_control_machine_state_29_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of op state 'send'  with activity 'march_debugger/send_message' 
 */



void husky_control_machine_state_30_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 30));
#endif
  _states->state_30_active = true;
  
  // First setup the deactivation function in the container group
  _states->state_1.group_899_deactivator = &husky_control_machine_state_30_deactivate;

  // Then call the activity
  husky_control_machine_state_30::Op::apply(march::state_graph::op_state_execution_context<husky_control_machine_states>(_interpreter,_states, &husky_control_machine_state_30_event_handler), husky_control_machine_state_30::get_parameters(_states->get_parameters()), _states->state_30.inputs, _states->state_30.outputs);
  _interpreter->add_event(march::state_graph::event(uint32_t(march::state_graph::state_events::finished), &husky_control_machine_state_30_event_handler, tasks_machine::system_time::now()));

}
void husky_control_machine_state_30_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 30));
#endif
  _states->state_30_active = false;
  
}


void husky_control_machine_state_30_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

/**************
 * Definition of super state 'husky_control'
 */

void husky_control_machine_state_1_activate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_activated, std::placeholders::_1, 1));
#endif
  _states->state_1_active = true;
  
    husky_control_machine_state_3_activate(_interpreter, _states);
    husky_control_machine_state_4_activate(_interpreter, _states);
    husky_control_machine_state_22_activate(_interpreter, _states);
    husky_control_machine_state_23_activate(_interpreter, _states);
    husky_control_machine_state_24_activate(_interpreter, _states);
    husky_control_machine_state_28_activate(_interpreter, _states);
    husky_control_machine_state_29_activate(_interpreter, _states);
    husky_control_machine_state_30_activate(_interpreter, _states);
}
void husky_control_machine_state_1_deactivate(march::state_graph::interpreter_context* _interpreter, husky_control_machine_states * _states)
{
#ifdef MARCH_MONITORING
  _interpreter->on_monitors(std::bind(&march::state_graph::abstract_monitor::state_deactivated, std::placeholders::_1, 1));
#endif
  _states->state_1_active = false;
  
    _states->state_1.group_1_deactivator(_interpreter, _states);
    _states->state_1.group_59_deactivator(_interpreter, _states);
    _states->state_1.group_697_deactivator(_interpreter, _states);
    _states->state_1.group_766_deactivator(_interpreter, _states);
    _states->state_1.group_879_deactivator(_interpreter, _states);
    _states->state_1.group_881_deactivator(_interpreter, _states);
    _states->state_1.group_898_deactivator(_interpreter, _states);
    _states->state_1.group_899_deactivator(_interpreter, _states);
}


void husky_control_machine_state_1_event_handler(march::state_graph::interpreter_context* _interpreter, march::state_graph::states* _states, uint32_t _event)
{ 
  
}

// Guards' is_guarded


husky_control_machine::husky_control_machine(const parameters& _parameters) : march::state_graph::machine(), m_states(new husky_control_machine_states(_parameters))
{
  
}

husky_control_machine::~husky_control_machine()
{
  delete m_states;
}

march::state_graph::states* husky_control_machine::setup(march::state_graph::interpreter* _interpreter)
{
  _interpreter->get_schedule()->create_time_slot(1000000, 0);
  _interpreter->get_schedule()->create_time_slot(1, 1);

  husky_control_machine_state_1_activate(_interpreter->get_context(), m_states);
  
  return m_states;
}

tinytl::vector<march::state_graph::machine_meta_information> husky_control_machine::get_meta_informations() const
{
  tinytl::vector<march::state_graph::machine_meta_information> mmis;
    mmis.push_back({"debug_information", "{\"files\":[{\"filename\":\"/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab1/machines/husky_control.mhl\",\"lastmodified\":\"2022-02-21T13:13:54.353\"},{\"filename\":\"/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab1/modules/components/air_lab1/velocity_controller.mhl\",\"lastmodified\":\"2022-01-28T13:14:22.968\"},{\"filename\":\"/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab1/modules/components/air_lab1/reach_point_controller.mhl\",\"lastmodified\":\"2022-01-28T13:14:22.964\"},{\"filename\":\"/home/cheka108/TDDE05/catkin_ws/src/air_labs/air_lab1/modules/components/air_lab1/waypoints_controller.mhl\",\"lastmodified\":\"2022-01-28T13:14:22.973\"},{\"filename\":\"/courses/TDDE05/software/lrs-pkg/inst/share/march/definitions/components/march/debugger/networking/debugger.mhl\",\"lastmodified\":\"2019-01-18T20:47:28.000\"}],\"machinefile\":0,\"states\":{\"1\":{\"state\":0},\"10\":{\"parent\":9,\"state\":0},\"11\":{\"parent\":9,\"state\":2},\"12\":{\"parent\":9,\"state\":3},\"13\":{\"parent\":9,\"state\":19},\"15\":{\"file\":3,\"state\":991},\"16\":{\"parent\":15,\"state\":0},\"17\":{\"parent\":15,\"state\":2},\"18\":{\"parent\":15,\"state\":3},\"19\":{\"parent\":15,\"state\":4},\"2\":{\"state\":2},\"20\":{\"parent\":15,\"state\":5},\"22\":{\"state\":698},\"23\":{\"state\":767},\"24\":{\"file\":4,\"state\":880},\"25\":{\"parent\":24,\"state\":0},\"26\":{\"parent\":24,\"state\":2},\"27\":{\"parent\":24,\"state\":6},\"28\":{\"state\":882},\"29\":{\"state\":900},\"3\":{\"state\":732},\"30\":{\"state\":901},\"4\":{\"state\":150},\"5\":{\"state\":888},\"6\":{\"file\":1,\"state\":956},\"7\":{\"parent\":6,\"state\":0},\"8\":{\"parent\":6,\"state\":15},\"9\":{\"file\":2,\"state\":976}}}"});
  
  return mmis;
}


void husky_control_machine::listen_to_wheel_cmd_message(const std::function<march::state_graph::message_output_connector<march_ros::sensor_msgs::joint_state>::callback_type>& _callback)
{
  m_states->wheel_cmd_output_connector.register_callback(_callback);
}
void husky_control_machine::trigger_to_idle_control_event()
{
  get_interpreter_context()->add_event(march::state_graph::event(0,
                                                                 [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t _id)
    {
      husky_control_machine_states* states = static_cast<husky_control_machine_states*>(_states);
      
      march::state_graph::transition_helper(&states->state_4, 4, &states->state_4, 4, _context, states);
    }, tasks_machine::system_time::now()));
}
void husky_control_machine::send_wheel_velocities_message(const march_ros::sensor_msgs::joint_state& _message)
{
  
  m_states->state_22.receive_message_i0(get_interpreter_context(), m_states, _message);
    get_interpreter_context()->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_22, 22, &states->state_22, 22, _context, states );
  }, tasks_machine::system_time::now()));
}
void husky_control_machine::send_odometry_message(const march_ros::nav_msgs::odometry& _message)
{
  
  m_states->state_23.receive_message_i0(get_interpreter_context(), m_states, _message);
    get_interpreter_context()->add_event(march::state_graph::event(0, [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t) {
    husky_control_machine_states * states = static_cast<husky_control_machine_states *>(_states);
    march::state_graph::transition_helper(&states->state_23, 23, &states->state_23, 23, _context, states );
  }, tasks_machine::system_time::now()));
}
void husky_control_machine::send_cmd_vel_message(const march_ros::geometry_msgs::twist& _message)
{
  
  m_states->state_6.receive_message_cmd_vel(get_interpreter_context(), m_states, _message);
}
void husky_control_machine::trigger_to_vel_control_event()
{
  get_interpreter_context()->add_event(march::state_graph::event(0,
                                                                 [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t _id)
    {
      husky_control_machine_states* states = static_cast<husky_control_machine_states*>(_states);
      
      march::state_graph::transition_helper(&states->state_4, 4, &states->state_4, 4, _context, states);
      march::state_graph::transition_helper(&states->state_5, 5, &states->state_6, 6, _context, states);
    }, tasks_machine::system_time::now()));
}
void husky_control_machine::send_cmd_position_message(const march_ros::geometry_msgs::pose_stamped& _message)
{
  
  m_states->state_9.receive_message_cmd_pose(get_interpreter_context(), m_states, _message);
}
void husky_control_machine::send_max_velocity_message(const march_ros::geometry_msgs::twist& _message)
{
  
  m_states->state_9.receive_message_max_velocity(get_interpreter_context(), m_states, _message);
  m_states->state_15.receive_message_max_velocity(get_interpreter_context(), m_states, _message);
}
void husky_control_machine::trigger_to_position_control_event()
{
  get_interpreter_context()->add_event(march::state_graph::event(0,
                                                                 [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t _id)
    {
      husky_control_machine_states* states = static_cast<husky_control_machine_states*>(_states);
      
      march::state_graph::transition_helper(&states->state_4, 4, &states->state_4, 4, _context, states);
      march::state_graph::transition_helper(&states->state_5, 5, &states->state_9, 9, _context, states);
    }, tasks_machine::system_time::now()));
}
void husky_control_machine::trigger_to_waypoints_control_event()
{
  get_interpreter_context()->add_event(march::state_graph::event(0,
                                                                 [](march::state_graph::interpreter_context* _context, march::state_graph::states* _states, uint32_t _id)
    {
      husky_control_machine_states* states = static_cast<husky_control_machine_states*>(_states);
      
      march::state_graph::transition_helper(&states->state_4, 4, &states->state_4, 4, _context, states);
      march::state_graph::transition_helper(&states->state_5, 5, &states->state_15, 15, _context, states);
    }, tasks_machine::system_time::now()));
}
void husky_control_machine::send_cmd_waypoints_message(const march_ros::nav_msgs::path& _message)
{
  
  m_states->state_15.receive_message_waypoints(get_interpreter_context(), m_states, _message);
}
void husky_control_machine::listen_to_position_reached_event(const std::function<march::state_graph::event_output_connector::callback_type>& _callback)
{
  return m_states->position_reached_output_connector.register_callback(_callback);
}
void husky_control_machine::listen_to_waypoints_finished_event(const std::function<march::state_graph::event_output_connector::callback_type>& _callback)
{
  return m_states->waypoints_finished_output_connector.register_callback(_callback);
}
