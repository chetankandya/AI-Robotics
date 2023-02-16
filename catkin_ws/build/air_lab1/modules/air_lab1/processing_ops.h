#ifndef _AIR_LAB1_MARCH_PROCESSING_OPS_H_
#define _AIR_LAB1_MARCH_PROCESSING_OPS_H_

#include <march/graph_ops/direct_op_traits.h>
#include <march/graph_ops/functional_execution_context.h>
#include <march/graph_ops/op_queued_task.h>


#include <march_ros/geometry_msgs_tools.h>
#include <march/eigen3_geometry.h>
#include <march/math.h>
#include <march/std_lib.h>

#include "bases.h"


namespace air_lab1_march
{

  MARCH_OP_DEFINE(reach_point)
  {
    ::march::graph_ops::direct_output_adaptor<::march_ros::geometry_msgs::pose_stamped> inputs_cmd_position(MARCH_OP_INPUT(cmd_position));
        
    ::march::graph_ops::direct_output_adaptor<::march_ros::geometry_msgs::twist> inputs_cmd_max_vel(MARCH_OP_INPUT(cmd_max_vel));
        
    ::march::graph_ops::direct_output_adaptor<::march_ros::geometry_msgs::pose> inputs_current_position(MARCH_OP_INPUT(current_position));
        
    ::march_ros::geometry_msgs::tools::twist_dissassemble_op::parameters parameters183;
    ::march_ros::geometry_msgs::tools::twist_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs183;
    inputs183.message.set_adaptor(&inputs_cmd_max_vel);
    ::march_ros::geometry_msgs::tools::twist_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs183;
    ::march_ros::geometry_msgs::tools::twist_dissassemble_op::apply(_execution_context,
        parameters183, inputs183, outputs183);
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::parameters parameters184;
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs184;
    inputs184.message.set_adaptor(&outputs183.linear);
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs184;
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::apply(_execution_context,
        parameters184, inputs184, outputs184);
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::parameters parameters185;
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs185;
    inputs185.message.set_adaptor(&outputs183.angular);
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs185;
    ::march_ros::geometry_msgs::tools::vector3_dissassemble_op::apply(_execution_context,
        parameters185, inputs185, outputs185);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters269;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs269;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_269_a(march::std_msgs::float64(0));
    inputs269.a.set_adaptor(&doa_fake_269_a);
    inputs269.b.set_adaptor(&outputs184.x);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs269;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters269, inputs269, outputs269);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters273;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs273;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_273_a;
    inputs273.a.set_adaptor(&doa_fake_273_a);
    inputs273.b.set_adaptor(&outputs185.z);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs273;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters273, inputs273, outputs273);
    ::march_ros::geometry_msgs::tools::pose_stamped_dissassemble_op::parameters parameters330;
    ::march_ros::geometry_msgs::tools::pose_stamped_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs330;
    inputs330.message.set_adaptor(&inputs_cmd_position);
    ::march_ros::geometry_msgs::tools::pose_stamped_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs330;
    ::march_ros::geometry_msgs::tools::pose_stamped_dissassemble_op::apply(_execution_context,
        parameters330, inputs330, outputs330);
    ::march_ros::geometry_msgs::tools::pose_dissassemble_op::parameters parameters484;
    ::march_ros::geometry_msgs::tools::pose_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs484;
    inputs484.message.set_adaptor(&inputs_current_position);
    ::march_ros::geometry_msgs::tools::pose_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs484;
    ::march_ros::geometry_msgs::tools::pose_dissassemble_op::apply(_execution_context,
        parameters484, inputs484, outputs484);
    ::march_ros::geometry_msgs::tools::point_dissassemble_op::parameters parameters485;
    ::march_ros::geometry_msgs::tools::point_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs485;
    inputs485.message.set_adaptor(&outputs484.position);
    ::march_ros::geometry_msgs::tools::point_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs485;
    ::march_ros::geometry_msgs::tools::point_dissassemble_op::apply(_execution_context,
        parameters485, inputs485, outputs485);
    ::march_ros::geometry_msgs::tools::quaternion_dissassemble_op::parameters parameters486;
    ::march_ros::geometry_msgs::tools::quaternion_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs486;
    inputs486.message.set_adaptor(&outputs484.orientation);
    ::march_ros::geometry_msgs::tools::quaternion_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs486;
    ::march_ros::geometry_msgs::tools::quaternion_dissassemble_op::apply(_execution_context,
        parameters486, inputs486, outputs486);
    ::march::eigen3_geometry::quaternion_create_op::parameters parameters487;
    ::march::eigen3_geometry::quaternion_create_op::inputs<::march::graph_ops::direct_input_adaptor> inputs487;
    inputs487.w.set_adaptor(&outputs486.w);
    inputs487.x.set_adaptor(&outputs486.x);
    inputs487.y.set_adaptor(&outputs486.y);
    inputs487.z.set_adaptor(&outputs486.z);
    ::march::eigen3_geometry::quaternion_create_op::outputs<::march::graph_ops::direct_output_adaptor> outputs487;
    ::march::eigen3_geometry::quaternion_create_op::apply(_execution_context,
        parameters487, inputs487, outputs487);
    ::march::eigen3_geometry::quaternion_to_ypr_op::parameters parameters488;
    ::march::eigen3_geometry::quaternion_to_ypr_op::inputs<::march::graph_ops::direct_input_adaptor> inputs488;
    inputs488.quaternion.set_adaptor(&outputs487.quaternion);
    ::march::eigen3_geometry::quaternion_to_ypr_op::outputs<::march::graph_ops::direct_output_adaptor> outputs488;
    ::march::eigen3_geometry::quaternion_to_ypr_op::apply(_execution_context,
        parameters488, inputs488, outputs488);
    ::march::std_lib::output_float64_op::parameters parameters500;
    parameters500.value = _parameters.krho;
    ::march::std_lib::output_float64_op::inputs<::march::graph_ops::direct_input_adaptor> inputs500;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_500_value;
    inputs500.value.set_adaptor(&doa_fake_500_value);
    ::march::std_lib::output_float64_op::outputs<::march::graph_ops::direct_output_adaptor> outputs500;
    ::march::std_lib::output_float64_op::apply(_execution_context,
        parameters500, inputs500, outputs500);
    ::march::std_lib::output_float64_op::parameters parameters501;
    parameters501.value = _parameters.kalpha;
    ::march::std_lib::output_float64_op::inputs<::march::graph_ops::direct_input_adaptor> inputs501;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_501_value;
    inputs501.value.set_adaptor(&doa_fake_501_value);
    ::march::std_lib::output_float64_op::outputs<::march::graph_ops::direct_output_adaptor> outputs501;
    ::march::std_lib::output_float64_op::apply(_execution_context,
        parameters501, inputs501, outputs501);
    ::march::std_lib::output_float64_op::parameters parameters502;
    parameters502.value = _parameters.kbeta;
    ::march::std_lib::output_float64_op::inputs<::march::graph_ops::direct_input_adaptor> inputs502;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_502_value;
    inputs502.value.set_adaptor(&doa_fake_502_value);
    ::march::std_lib::output_float64_op::outputs<::march::graph_ops::direct_output_adaptor> outputs502;
    ::march::std_lib::output_float64_op::apply(_execution_context,
        parameters502, inputs502, outputs502);
    ::march_ros::geometry_msgs::tools::pose_dissassemble_op::parameters parameters190;
    ::march_ros::geometry_msgs::tools::pose_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs190;
    inputs190.message.set_adaptor(&outputs330.pose);
    ::march_ros::geometry_msgs::tools::pose_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs190;
    ::march_ros::geometry_msgs::tools::pose_dissassemble_op::apply(_execution_context,
        parameters190, inputs190, outputs190);
    ::march_ros::geometry_msgs::tools::quaternion_dissassemble_op::parameters parameters191;
    ::march_ros::geometry_msgs::tools::quaternion_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs191;
    inputs191.message.set_adaptor(&outputs190.orientation);
    ::march_ros::geometry_msgs::tools::quaternion_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs191;
    ::march_ros::geometry_msgs::tools::quaternion_dissassemble_op::apply(_execution_context,
        parameters191, inputs191, outputs191);
    ::march::eigen3_geometry::quaternion_create_op::parameters parameters192;
    ::march::eigen3_geometry::quaternion_create_op::inputs<::march::graph_ops::direct_input_adaptor> inputs192;
    inputs192.w.set_adaptor(&outputs191.w);
    inputs192.x.set_adaptor(&outputs191.x);
    inputs192.y.set_adaptor(&outputs191.y);
    inputs192.z.set_adaptor(&outputs191.z);
    ::march::eigen3_geometry::quaternion_create_op::outputs<::march::graph_ops::direct_output_adaptor> outputs192;
    ::march::eigen3_geometry::quaternion_create_op::apply(_execution_context,
        parameters192, inputs192, outputs192);
    ::march::eigen3_geometry::quaternion_to_ypr_op::parameters parameters193;
    ::march::eigen3_geometry::quaternion_to_ypr_op::inputs<::march::graph_ops::direct_input_adaptor> inputs193;
    inputs193.quaternion.set_adaptor(&outputs192.quaternion);
    ::march::eigen3_geometry::quaternion_to_ypr_op::outputs<::march::graph_ops::direct_output_adaptor> outputs193;
    ::march::eigen3_geometry::quaternion_to_ypr_op::apply(_execution_context,
        parameters193, inputs193, outputs193);
    ::march_ros::geometry_msgs::tools::point_dissassemble_op::parameters parameters189;
    ::march_ros::geometry_msgs::tools::point_dissassemble_op::inputs<::march::graph_ops::direct_input_adaptor> inputs189;
    inputs189.message.set_adaptor(&outputs190.position);
    ::march_ros::geometry_msgs::tools::point_dissassemble_op::outputs<::march::graph_ops::direct_output_adaptor> outputs189;
    ::march_ros::geometry_msgs::tools::point_dissassemble_op::apply(_execution_context,
        parameters189, inputs189, outputs189);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters224;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs224;
    inputs224.a.set_adaptor(&outputs189.x);
    inputs224.b.set_adaptor(&outputs485.x);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs224;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters224, inputs224, outputs224);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters225;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs225;
    inputs225.a.set_adaptor(&outputs189.y);
    inputs225.b.set_adaptor(&outputs485.y);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs225;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters225, inputs225, outputs225);
    ::march::math::atan2_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters235;
    ::march::math::atan2_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs235;
    inputs235.arg0.set_adaptor(&outputs225.value);
    inputs235.arg1.set_adaptor(&outputs224.value);
    ::march::math::atan2_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs235;
    ::march::math::atan2_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters235, inputs235, outputs235);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters238;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs238;
    inputs238.a.set_adaptor(&outputs235.result);
    inputs238.b.set_adaptor(&outputs488.yaw);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs238;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters238, inputs238, outputs238);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters241;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs241;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_241_a(
              outputs193.yaw, march::std_msgs::float64(0));
    inputs241.a.set_adaptor(&doa_fake_241_a);
    inputs241.b.set_adaptor(&outputs235.result);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs241;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters241, inputs241, outputs241);
    ::march::math::angle_mod_op<march::std_msgs::float64, march::std_msgs::float64>::parameters parameters248;
    ::march::math::angle_mod_op<march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs248;
    inputs248.argument.set_adaptor(&outputs238.value);
    ::march::math::angle_mod_op<march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs248;
    ::march::math::angle_mod_op<march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters248, inputs248, outputs248);
    ::march::math::angle_mod_op<march::std_msgs::float64, march::std_msgs::float64>::parameters parameters249;
    ::march::math::angle_mod_op<march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs249;
    inputs249.argument.set_adaptor(&outputs241.value);
    ::march::math::angle_mod_op<march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs249;
    ::march::math::angle_mod_op<march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters249, inputs249, outputs249);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters213;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs213;
    inputs213.a.set_adaptor(&outputs224.value);
    inputs213.b.set_adaptor(&outputs224.value);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs213;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters213, inputs213, outputs213);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters214;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs214;
    inputs214.a.set_adaptor(&outputs225.value);
    inputs214.b.set_adaptor(&outputs225.value);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs214;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters214, inputs214, outputs214);
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters215;
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs215;
    inputs215.a.set_adaptor(&outputs213.value);
    inputs215.b.set_adaptor(&outputs214.value);
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs215;
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters215, inputs215, outputs215);
    ::march::math::sqrt_op<march::std_msgs::float64, march::std_msgs::float64>::parameters parameters216;
    ::march::math::sqrt_op<march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs216;
    inputs216.argument.set_adaptor(&outputs215.value);
    ::march::math::sqrt_op<march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs216;
    ::march::math::sqrt_op<march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters216, inputs216, outputs216);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters243;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs243;
    inputs243.a.set_adaptor(&outputs216.result);
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_243_b(
              outputs500.value, march::std_msgs::float64(3));
    inputs243.b.set_adaptor(&doa_fake_243_b);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs243;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters243, inputs243, outputs243);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters244;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs244;
    inputs244.a.set_adaptor(&outputs248.result);
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_244_b(
              outputs501.value, march::std_msgs::float64(8));
    inputs244.b.set_adaptor(&doa_fake_244_b);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs244;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters244, inputs244, outputs244);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters245;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs245;
    inputs245.a.set_adaptor(&outputs249.result);
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_245_b(
              outputs502.value, march::std_msgs::float64(-4));
    inputs245.b.set_adaptor(&doa_fake_245_b);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs245;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters245, inputs245, outputs245);
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters246;
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs246;
    inputs246.a.set_adaptor(&outputs244.value);
    inputs246.b.set_adaptor(&outputs245.value);
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs246;
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters246, inputs246, outputs246);
    ::march::math::clamp_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters256;
    ::march::math::clamp_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs256;
    inputs256.arg0.set_adaptor(&outputs243.value);
    inputs256.arg1.set_adaptor(&outputs269.value);
    inputs256.arg2.set_adaptor(&outputs184.x);
    ::march::math::clamp_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs256;
    ::march::math::clamp_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters256, inputs256, outputs256);
    ::march::math::clamp_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters257;
    ::march::math::clamp_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs257;
    inputs257.arg0.set_adaptor(&outputs246.value);
    inputs257.arg1.set_adaptor(&outputs273.value);
    inputs257.arg2.set_adaptor(&outputs185.z);
    ::march::math::clamp_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs257;
    ::march::math::clamp_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters257, inputs257, outputs257);

  if(outputs256.result.has_received_value())
  {
    MARCH_OP_SEND(linear, ::march::graph_ops::direct_input_adaptor<::march::std_msgs::float64>(&outputs256.result).get_last_value());
  }
  if(outputs257.result.has_received_value())
  {
    MARCH_OP_SEND(angular, ::march::graph_ops::direct_input_adaptor<::march::std_msgs::float64>(&outputs257.result).get_last_value());
  }
  }
  MARCH_OP_DEFINE(linear_angular_to_left_right_velocities)
  {
    ::march::graph_ops::direct_output_adaptor<::march::std_msgs::float64> inputs_linear_velocity(MARCH_OP_INPUT(linear_velocity));
        
    ::march::graph_ops::direct_output_adaptor<::march::std_msgs::float64> inputs_angular_velocity(MARCH_OP_INPUT(angular_velocity));
        
    ::march::std_lib::output_float64_op::parameters parameters5;
    parameters5.value = _parameters.left_right_distance;
    ::march::std_lib::output_float64_op::inputs<::march::graph_ops::direct_input_adaptor> inputs5;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_5_value;
    inputs5.value.set_adaptor(&doa_fake_5_value);
    ::march::std_lib::output_float64_op::outputs<::march::graph_ops::direct_output_adaptor> outputs5;
    ::march::std_lib::output_float64_op::apply(_execution_context,
        parameters5, inputs5, outputs5);
    ::march::std_lib::output_float64_op::parameters parameters10;
    parameters10.value = _parameters.wheel_radius;
    ::march::std_lib::output_float64_op::inputs<::march::graph_ops::direct_input_adaptor> inputs10;
    ::march::graph_ops::direct_output_adaptor<march::std_msgs::float64> doa_fake_10_value;
    inputs10.value.set_adaptor(&doa_fake_10_value);
    ::march::std_lib::output_float64_op::outputs<::march::graph_ops::direct_output_adaptor> outputs10;
    ::march::std_lib::output_float64_op::apply(_execution_context,
        parameters10, inputs10, outputs10);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters3;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs3;
    inputs3.a.set_adaptor(&outputs5.value);
    inputs3.b.set_adaptor(&inputs_angular_velocity);
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs3;
    ::march::math::multiplication_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters3, inputs3, outputs3);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters7;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs7;
    inputs7.a.set_adaptor(&inputs_linear_velocity);
    inputs7.b.set_adaptor(&outputs3.value);
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs7;
    ::march::math::substraction_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters7, inputs7, outputs7);
    ::march::math::division_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters8;
    ::march::math::division_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs8;
    inputs8.a.set_adaptor(&outputs7.value);
    inputs8.b.set_adaptor(&outputs10.value);
    ::march::math::division_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs8;
    ::march::math::division_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters8, inputs8, outputs8);
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters11;
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs11;
    inputs11.a.set_adaptor(&inputs_linear_velocity);
    inputs11.b.set_adaptor(&outputs3.value);
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs11;
    ::march::math::addition_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters11, inputs11, outputs11);
    ::march::math::division_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::parameters parameters9;
    ::march::math::division_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::inputs<::march::graph_ops::direct_input_adaptor> inputs9;
    inputs9.a.set_adaptor(&outputs11.value);
    inputs9.b.set_adaptor(&outputs10.value);
    ::march::math::division_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::outputs<::march::graph_ops::direct_output_adaptor> outputs9;
    ::march::math::division_op<march::std_msgs::float64, march::std_msgs::float64, march::std_msgs::float64>::apply(_execution_context,
        parameters9, inputs9, outputs9);

  if(outputs8.value.has_received_value())
  {
    MARCH_OP_SEND(left_velocity, ::march::graph_ops::direct_input_adaptor<::march::std_msgs::float64>(&outputs8.value).get_last_value());
  }
  if(outputs9.value.has_received_value())
  {
    MARCH_OP_SEND(right_velocity, ::march::graph_ops::direct_input_adaptor<::march::std_msgs::float64>(&outputs9.value).get_last_value());
  }
  }
}


#endif
