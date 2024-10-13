// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_
#define CUSTOM_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interface/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interface
{

namespace msg
{

namespace builder
{

class Init_Num_num
{
public:
  explicit Init_Num_num(::custom_interface::msg::Num & msg)
  : msg_(msg)
  {}
  ::custom_interface::msg::Num num(::custom_interface::msg::Num::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::msg::Num msg_;
};

class Init_Num_message
{
public:
  Init_Num_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Num_num message(::custom_interface::msg::Num::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_Num_num(msg_);
  }

private:
  ::custom_interface::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::msg::Num>()
{
  return custom_interface::msg::builder::Init_Num_message();
}

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_
