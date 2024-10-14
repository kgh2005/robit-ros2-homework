cmake_minimum_required(VERSION 3.5)
project(ui_test)

# 컴파일러가 GNUCXX이거나 Clang이면 컴파일 경고 옵션 추가
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ROS2 및 Qt5/Qt6 패키지 의존성 설정
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(turtle_interface REQUIRED)  # tutorial_interface 패키지 추가
find_package(geometry_msgs REQUIRED)     # geometry_msgs 패키지 추가

# C++ 표준 버전 설정 (C++14 사용 권장)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt6 또는 Qt5를 찾기 위한 설정 (Qt6 우선, 없으면 Qt5를 사용)
find_package(Qt6 COMPONENTS Widgets QUIET)
if(Qt6_FOUND)
    set(QT_VERSION_MAJOR 6)
    message(STATUS "Found Qt6: ${Qt6_VERSION}")
else()
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    set(QT_VERSION_MAJOR 5)
    message(STATUS "Found Qt5: ${Qt5_VERSION}")
endif()

# Qt5와 Qt6 둘 다 없으면 에러 발생
if(NOT Qt5_FOUND AND NOT Qt6_FOUND)
    message(FATAL_ERROR "Qt5 or Qt6 not found. Please install Qt.")
endif()

# 헤더 파일 및 소스 파일 경로 포함
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})

# 소스 및 헤더 파일 경로 설정
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

set(HEADERS
    include/mainwindow.h
)

set(UI_FILES
    ui/mainwindow.ui
)

# MOC(Meta-Object Compiler) 및 UI 파일 처리
if(QT_VERSION_MAJOR EQUAL 6)
    qt6_wrap_cpp(MOC_SOURCES ${HEADERS})
    qt6_wrap_ui(UIC_SOURCES ${UI_FILES})
else()
    qt5_wrap_cpp(MOC_SOURCES ${HEADERS})
    qt5_wrap_ui(UIC_SOURCES ${UI_FILES})
endif()

# 실행 파일 생성
add_executable(${PROJECT_NAME} ${SOURCES} ${MOC_SOURCES} ${UIC_SOURCES})

# ROS2 및 Qt Widgets 라이브러리 의존성 추가
ament_target_dependencies(${PROJECT_NAME} rclcpp std_msgs turtle_interface geometry_msgs)  # geometry_msgs 의존성 추가

# Qt Widgets 라이브러리 링크
if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(${PROJECT_NAME} Qt6::Widgets)  # Qt6 라이브러리 링크
else()
    target_link_libraries(${PROJECT_NAME} Qt5::Widgets)  # Qt5 라이브러리 링크
endif()

# 빌드 결과물 설치 경로 설정
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION lib/${PROJECT_NAME}
    LIBRARY DESTINATION lib/${PROJECT_NAME}
    ARCHIVE DESTINATION lib/${PROJECT_NAME}
)

# include 디렉터리의 헤더 파일 설치
install(DIRECTORY include/
    DESTINATION include/${PROJECT_NAME}
)

# 빌드 시 테스트 옵션을 활성화한 경우 린트 자동 검사 설정
if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    set(ament_cmake_cpplint_FOUND TRUE)
    ament_lint_auto_find_test_dependencies()
endif()

# ROS2 패키지로서 설치할 수 있도록 설정
ament_package()
