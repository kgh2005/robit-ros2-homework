// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from turtle_interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_
#define TURTLE_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "turtle_interface/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace turtle_interface
{

namespace msg
{

namespace builder
{

class Init_Num_angular_z
{
public:
  explicit Init_Num_angular_z(::turtle_interface::msg::Num & msg)
  : msg_(msg)
  {}
  ::turtle_interface::msg::Num angular_z(::turtle_interface::msg::Num::_angular_z_type arg)
  {
    msg_.angular_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::turtle_interface::msg::Num msg_;
};

class Init_Num_linear_x
{
public:
  Init_Num_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Num_angular_z linear_x(::turtle_interface::msg::Num::_linear_x_type arg)
  {
    msg_.linear_x = std::move(arg);
    return Init_Num_angular_z(msg_);
  }

private:
  ::turtle_interface::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::turtle_interface::msg::Num>()
{
  return turtle_interface::msg::builder::Init_Num_linear_x();
}

}  // namespace turtle_interface

#endif  // TURTLE_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_
