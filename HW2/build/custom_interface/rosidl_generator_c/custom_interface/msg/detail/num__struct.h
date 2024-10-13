// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interface:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACE__MSG__DETAIL__NUM__STRUCT_H_
#define CUSTOM_INTERFACE__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Num in the package custom_interface.
typedef struct custom_interface__msg__Num
{
  rosidl_runtime_c__String message;
  int64_t num;
} custom_interface__msg__Num;

// Struct for a sequence of custom_interface__msg__Num.
typedef struct custom_interface__msg__Num__Sequence
{
  custom_interface__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interface__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACE__MSG__DETAIL__NUM__STRUCT_H_
