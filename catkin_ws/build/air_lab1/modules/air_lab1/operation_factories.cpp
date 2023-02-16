#include "operation_factories.h"

#include <utility>
#include <tinytl/list>
#include <tinytl/string>

#include <march/graph_flow/execution_context.h>
#include <march/graph_flow/operation_factory.h>


namespace air_lab1_march::operation_models
{
  class reach_point_operation_node : public march::graph_flow::abstract_operation_node
  {
    typedef air_lab1_march::reach_point_op Op;
  public:
    march::graph_flow::abstract_message_input_connector* get_input_connector(std::size_t _index) override
    {
      switch(_index)
      {
        case 0:
          return &m_inputs.cmd_position;
        case 1:
          return &m_inputs.cmd_max_vel;
        case 2:
          return &m_inputs.current_position;
        default:
          return nullptr;
      }
    }
    march::graph_flow::abstract_message_output_connector* get_output_connector(std::size_t _index) override
    {
      switch(_index)
      {
        case 0:
          return &m_outputs.linear;
        case 1:
          return &m_outputs.angular;
        default:
          return nullptr;
      }
    }
    bool set_parameter(std::size_t _index, const tinytl::variant& _value) override
    {
      switch(_index)
      {
        case 0:
          m_parameters.krho = _value.to_value<double>();
          return true;
        case 1:
          m_parameters.kalpha = _value.to_value<double>();
          return true;
        case 2:
          m_parameters.kbeta = _value.to_value<double>();
          return true;        
        default:
          return false;
      }
      
    }
    void process(const march::graph_flow::execution_context& _execution_context) override
    {
      Op::apply(_execution_context, m_parameters, m_inputs, m_outputs);
    }
    bool should_run() const override
    {
      return false
             or m_inputs.cmd_position.has_queued_value()
             or m_inputs.cmd_max_vel.has_queued_value()
             or m_inputs.current_position.has_queued_value();
    }    
  private:
    struct inputs
    {
      march::graph_flow::message_input_connector<march_ros::geometry_msgs::pose_stamped> cmd_position;
      march::graph_flow::message_input_connector<march_ros::geometry_msgs::twist> cmd_max_vel;
      march::graph_flow::message_input_connector<march_ros::geometry_msgs::pose> current_position;
    };
    inputs m_inputs;
    struct outputs
    {
      march::graph_flow::message_output_connector<march::std_msgs::float64> linear;
      march::graph_flow::message_output_connector<march::std_msgs::float64> angular;
    };
    outputs m_outputs;
    typename Op::parameters m_parameters;
  };

  class linear_angular_to_left_right_velocities_operation_node : public march::graph_flow::abstract_operation_node
  {
    typedef air_lab1_march::linear_angular_to_left_right_velocities_op Op;
  public:
    march::graph_flow::abstract_message_input_connector* get_input_connector(std::size_t _index) override
    {
      switch(_index)
      {
        case 0:
          return &m_inputs.linear_velocity;
        case 1:
          return &m_inputs.angular_velocity;
        default:
          return nullptr;
      }
    }
    march::graph_flow::abstract_message_output_connector* get_output_connector(std::size_t _index) override
    {
      switch(_index)
      {
        case 0:
          return &m_outputs.left_velocity;
        case 1:
          return &m_outputs.right_velocity;
        default:
          return nullptr;
      }
    }
    bool set_parameter(std::size_t _index, const tinytl::variant& _value) override
    {
      switch(_index)
      {
        case 0:
          m_parameters.wheel_radius = _value.to_value<double>();
          return true;
        case 1:
          m_parameters.left_right_distance = _value.to_value<double>();
          return true;        
        default:
          return false;
      }
      
    }
    void process(const march::graph_flow::execution_context& _execution_context) override
    {
      Op::apply(_execution_context, m_parameters, m_inputs, m_outputs);
    }
    bool should_run() const override
    {
      return false
             or m_inputs.linear_velocity.has_queued_value()
             or m_inputs.angular_velocity.has_queued_value();
    }    
  private:
    struct inputs
    {
      march::graph_flow::message_input_connector<march::std_msgs::float64> linear_velocity;
      march::graph_flow::message_input_connector<march::std_msgs::float64> angular_velocity;
    };
    inputs m_inputs;
    struct outputs
    {
      march::graph_flow::message_output_connector<march::std_msgs::float64> left_velocity;
      march::graph_flow::message_output_connector<march::std_msgs::float64> right_velocity;
    };
    outputs m_outputs;
    typename Op::parameters m_parameters;
  };


}

extern "C"
{
  tinytl::list<std::pair<tinytl::string, march::graph_flow::abstract_operation_factory*>> march_create_factories()
  {
    tinytl::list<std::pair<tinytl::string, march::graph_flow::abstract_operation_factory*>> models;
    using namespace air_lab1_march::operation_models;

    models.push_back({"air_lab1_march/reach_point", new march::graph_flow::operation_factory<reach_point_operation_node>()});
    models.push_back({"air_lab1_march/linear_angular_to_left_right_velocities", new march::graph_flow::operation_factory<linear_angular_to_left_right_velocities_operation_node>()});
    return models;
  }
}
