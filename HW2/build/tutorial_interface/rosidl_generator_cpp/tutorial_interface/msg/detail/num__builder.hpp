// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_
#define TUTORIAL_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interface/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interface
{

namespace msg
{

namespace builder
{

class Init_Num_message
{
public:
  Init_Num_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interface::msg::Num message(::tutorial_interface::msg::Num::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interface::msg::Num msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interface::msg::Num>()
{
  return tutorial_interface::msg::builder::Init_Num_message();
}

}  // namespace tutorial_interface

#endif  // TUTORIAL_INTERFACE__MSG__DETAIL__NUM__BUILDER_HPP_
