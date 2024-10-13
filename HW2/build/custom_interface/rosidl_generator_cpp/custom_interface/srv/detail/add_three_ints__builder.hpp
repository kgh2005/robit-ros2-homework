// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interface:srv/AddThreeInts.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_
#define CUSTOM_INTERFACE__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interface/srv/detail/add_three_ints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interface
{

namespace srv
{

namespace builder
{

class Init_AddThreeInts_Request_num
{
public:
  explicit Init_AddThreeInts_Request_num(::custom_interface::srv::AddThreeInts_Request & msg)
  : msg_(msg)
  {}
  ::custom_interface::srv::AddThreeInts_Request num(::custom_interface::srv::AddThreeInts_Request::_num_type arg)
  {
    msg_.num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::srv::AddThreeInts_Request msg_;
};

class Init_AddThreeInts_Request_message
{
public:
  Init_AddThreeInts_Request_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddThreeInts_Request_num message(::custom_interface::srv::AddThreeInts_Request::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_AddThreeInts_Request_num(msg_);
  }

private:
  ::custom_interface::srv::AddThreeInts_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::srv::AddThreeInts_Request>()
{
  return custom_interface::srv::builder::Init_AddThreeInts_Request_message();
}

}  // namespace custom_interface


namespace custom_interface
{

namespace srv
{

namespace builder
{

class Init_AddThreeInts_Response_sum
{
public:
  explicit Init_AddThreeInts_Response_sum(::custom_interface::srv::AddThreeInts_Response & msg)
  : msg_(msg)
  {}
  ::custom_interface::srv::AddThreeInts_Response sum(::custom_interface::srv::AddThreeInts_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interface::srv::AddThreeInts_Response msg_;
};

class Init_AddThreeInts_Response_message
{
public:
  Init_AddThreeInts_Response_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddThreeInts_Response_sum message(::custom_interface::srv::AddThreeInts_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return Init_AddThreeInts_Response_sum(msg_);
  }

private:
  ::custom_interface::srv::AddThreeInts_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interface::srv::AddThreeInts_Response>()
{
  return custom_interface::srv::builder::Init_AddThreeInts_Response_message();
}

}  // namespace custom_interface

#endif  // CUSTOM_INTERFACE__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_
