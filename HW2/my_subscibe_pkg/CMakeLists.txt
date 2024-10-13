cmake_minimum_required(VERSION 3.8)
project(my_subscribe_pkg)  # 패키지 이름 수정

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)  # rclcpp 의존성 추가
find_package(tutorial_interface REQUIRED)  # tutorial_interfaces 의존성 추가

# 실행 파일 추가
add_executable(subscriber_node src/subscriber.cpp)  # 실행 파일 경로 확인
ament_target_dependencies(subscriber_node rclcpp tutorial_interface)  # 의존성 설정

# 설치 디렉토리 설정
install(TARGETS subscriber_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
