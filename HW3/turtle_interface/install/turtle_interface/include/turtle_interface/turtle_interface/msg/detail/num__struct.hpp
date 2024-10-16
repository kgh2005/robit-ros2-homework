// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from turtle_interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACE__MSG__DETAIL__NUM__STRUCT_HPP_
#define TURTLE_INTERFACE__MSG__DETAIL__NUM__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__turtle_interface__msg__Num __attribute__((deprecated))
#else
# define DEPRECATED__turtle_interface__msg__Num __declspec(deprecated)
#endif

namespace turtle_interface
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Num_
{
  using Type = Num_<ContainerAllocator>;

  explicit Num_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->angular_z = 0.0;
    }
  }

  explicit Num_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->linear_x = 0.0;
      this->angular_z = 0.0;
    }
  }

  // field types and members
  using _linear_x_type =
    double;
  _linear_x_type linear_x;
  using _angular_z_type =
    double;
  _angular_z_type angular_z;

  // setters for named parameter idiom
  Type & set__linear_x(
    const double & _arg)
  {
    this->linear_x = _arg;
    return *this;
  }
  Type & set__angular_z(
    const double & _arg)
  {
    this->angular_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    turtle_interface::msg::Num_<ContainerAllocator> *;
  using ConstRawPtr =
    const turtle_interface::msg::Num_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<turtle_interface::msg::Num_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<turtle_interface::msg::Num_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      turtle_interface::msg::Num_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<turtle_interface::msg::Num_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      turtle_interface::msg::Num_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<turtle_interface::msg::Num_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<turtle_interface::msg::Num_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<turtle_interface::msg::Num_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__turtle_interface__msg__Num
    std::shared_ptr<turtle_interface::msg::Num_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__turtle_interface__msg__Num
    std::shared_ptr<turtle_interface::msg::Num_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Num_ & other) const
  {
    if (this->linear_x != other.linear_x) {
      return false;
    }
    if (this->angular_z != other.angular_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const Num_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Num_

// alias to use template instance with default allocator
using Num =
  turtle_interface::msg::Num_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace turtle_interface

#endif  // TURTLE_INTERFACE__MSG__DETAIL__NUM__STRUCT_HPP_
