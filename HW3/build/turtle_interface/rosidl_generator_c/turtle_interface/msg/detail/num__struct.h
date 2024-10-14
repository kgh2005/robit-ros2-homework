// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from turtle_interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef TURTLE_INTERFACE__MSG__DETAIL__NUM__STRUCT_H_
#define TURTLE_INTERFACE__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Num in the package turtle_interface.
typedef struct turtle_interface__msg__Num
{
  double linear_x;
  double angular_z;
} turtle_interface__msg__Num;

// Struct for a sequence of turtle_interface__msg__Num.
typedef struct turtle_interface__msg__Num__Sequence
{
  turtle_interface__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} turtle_interface__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TURTLE_INTERFACE__MSG__DETAIL__NUM__STRUCT_H_
