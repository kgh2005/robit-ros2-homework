# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_button_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED button_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(button_FOUND FALSE)
  elseif(NOT button_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(button_FOUND FALSE)
  endif()
  return()
endif()
set(_button_CONFIG_INCLUDED TRUE)

# output package information
if(NOT button_FIND_QUIETLY)
  message(STATUS "Found button: 0.1.0 (${button_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'button' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${button_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(button_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${button_DIR}/${_extra}")
endforeach()
