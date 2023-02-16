#ifndef _AIR_LAB1_MARCH_BASES_H_
#define _AIR_LAB1_MARCH_BASES_H_

#include <march/graph_ops/define_op.h>

#include <tinytl/string>

#include <march_ros/geometry_msgs.h>
#include <march/std_msgs.h>


namespace air_lab1_march
{

  class reach_point_op_base
  {
  public:
    enum class events : uint32_t
    {
    };
  public:
    struct parameters
    {
      double krho = 0;
      double kalpha = 0;
      double kbeta = 0;
    };
    template<template<typename> class adaptor>
    struct inputs
    {
      adaptor<::march_ros::geometry_msgs::pose_stamped> cmd_position;
      adaptor<::march_ros::geometry_msgs::twist> cmd_max_vel;
      adaptor<::march_ros::geometry_msgs::pose> current_position;
    };
    template<template<typename> class adaptor>
    struct outputs
    {
      adaptor<::march::std_msgs::float64> linear;
      adaptor<::march::std_msgs::float64> angular;
    };
  };

  class linear_angular_to_left_right_velocities_op_base
  {
  public:
    enum class events : uint32_t
    {
    };
  public:
    struct parameters
    {
      double wheel_radius = 0.16;
      double left_right_distance = 0.55;
    };
    template<template<typename> class adaptor>
    struct inputs
    {
      adaptor<::march::std_msgs::float64> linear_velocity;
      adaptor<::march::std_msgs::float64> angular_velocity;
    };
    template<template<typename> class adaptor>
    struct outputs
    {
      adaptor<::march::std_msgs::float64> left_velocity;
      adaptor<::march::std_msgs::float64> right_velocity;
    };
  };

}

#endif
  
