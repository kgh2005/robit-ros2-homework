// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TUTORIAL_INTERFACE__MSG__DETAIL__NUM__TRAITS_HPP_
#define TUTORIAL_INTERFACE__MSG__DETAIL__NUM__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tutorial_interface/msg/detail/num__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tutorial_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const Num & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Num & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
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

}  // namespace tutorial_interface

namespace rosidl_generator_traits
{

[[deprecated("use tutorial_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tutorial_interface::msg::Num & msg,
  std::ostream & out, size_t indentation = 0)
{
  tutorial_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tutorial_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const tutorial_interface::msg::Num & msg)
{
  return tutorial_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tutorial_interface::msg::Num>()
{
  return "tutorial_interface::msg::Num";
}

template<>
inline const char * name<tutorial_interface::msg::Num>()
{
  return "tutorial_interface/msg/Num";
}

template<>
struct has_fixed_size<tutorial_interface::msg::Num>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<tutorial_interface::msg::Num>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<tutorial_interface::msg::Num>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACE__MSG__DETAIL__NUM__TRAITS_HPP_
