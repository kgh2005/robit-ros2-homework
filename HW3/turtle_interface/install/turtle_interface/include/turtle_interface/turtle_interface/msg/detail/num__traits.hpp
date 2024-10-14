// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtle_interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACE__MSG__DETAIL__NUM__TRAITS_HPP_
#define TURTLE_INTERFACE__MSG__DETAIL__NUM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "turtle_interface/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace turtle_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Num & msg,
  std::ostream & out)
{
  out << "{";
  // member: linear_x
  {
    out << "linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_x, out);
    out << ", ";
  }

  // member: angular_z
  {
    out << "angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Num & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: linear_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.linear_x, out);
    out << "\n";
  }

  // member: angular_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.angular_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Num & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace turtle_interface

namespace rosidl_generator_traits
{

[[deprecated("use turtle_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtle_interface::msg::Num & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtle_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtle_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const turtle_interface::msg::Num & msg)
{
  return turtle_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<turtle_interface::msg::Num>()
{
  return "turtle_interface::msg::Num";
}

template<>
inline const char * name<turtle_interface::msg::Num>()
{
  return "turtle_interface/msg/Num";
}

template<>
struct has_fixed_size<turtle_interface::msg::Num>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<turtle_interface::msg::Num>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<turtle_interface::msg::Num>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TURTLE_INTERFACE__MSG__DETAIL__NUM__TRAITS_HPP_
