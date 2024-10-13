cmake_minimum_required(VERSION 3.8)
project(my_publisher_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)  # ROS 2 rclcpp 의존성
find_package(tutorial_interface REQUIRED)  # tutorial_interface 의존성

# 실행 파일 추가
add_executable(publisher_node src/publisher.cpp)  # 실행 파일 이름 및 소스 파일 경로
ament_target_dependencies(publisher_node rclcpp tutorial_interface)  # 의존성 설정
install(TARGETS publisher_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
