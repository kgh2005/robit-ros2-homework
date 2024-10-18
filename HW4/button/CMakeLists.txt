cmake_minimum_required(VERSION 3.5)
project(button)  # 프로젝트 이름은 'button'

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Qt6 또는 Qt5를 찾기 위한 설정
find_package(Qt6 COMPONENTS Widgets QUIET)
if(Qt6_FOUND)
    set(QT_VERSION_MAJOR 6)
    message(STATUS "Found Qt6: ${Qt6_VERSION}")
else()
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    set(QT_VERSION_MAJOR 5)
    message(STATUS "Found Qt5: ${Qt5_VERSION}")
endif()

if(NOT Qt5_FOUND AND NOT Qt6_FOUND)
    message(FATAL_ERROR "Qt5 or Qt6 not found. Please install Qt.")
endif()

# include 디렉터리 경로 설정
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})

# 소스 및 헤더 파일 확인
set(SOURCES
    src/main.cpp         # src/main.cpp 파일이 있는지 확인
    src/mainwindow.cpp    # src/mainwindow.cpp 파일이 있는지 확인
    src/qnode.cpp         # src/qnode.cpp 파일이 있는지 확인
)

set(HEADERS
    include/button/mainwindow.hpp  # include/button/mainwindow.hpp 파일이 있는지 확인
    include/button/qnode.hpp       # include/button/qnode.hpp 파일이 있는지 확인
)

# UI 및 리소스 파일 경로 확인
set(UI_FILES
    ui/mainwindow.ui      # ui/mainwindow.ui 파일이 있는지 확인
)

set(RESOURCE_FILES
    resources/images.qrc  # resources/images.qrc 파일이 있는지 확인
)

# Qt MOC 및 UI 파일 처리
if(QT_VERSION_MAJOR EQUAL 6)
    qt6_wrap_cpp(MOC_SOURCES ${HEADERS})
    qt6_wrap_ui(UIC_SOURCES ${UI_FILES})
    qt_add_resources(RESOURCE_SOURCES ${RESOURCE_FILES})
else()
    qt5_wrap_cpp(MOC_SOURCES ${HEADERS})
    qt5_wrap_ui(UIC_SOURCES ${UI_FILES})
    qt5_add_resources(RESOURCE_SOURCES ${RESOURCE_FILES})
endif()

# 실행 파일 생성 (프로젝트 이름과 타겟을 'button_node'로 변경)
add_executable(button_node ${SOURCES} ${MOC_SOURCES} ${UIC_SOURCES} ${RESOURCE_SOURCES})

# ament_target_dependencies에서 타겟 이름 수정
ament_target_dependencies(button_node rclcpp std_msgs)  # std_msgs 추가

if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(button_node Qt6::Widgets)
else()
    target_link_libraries(button_node Qt5::Widgets)
endif()

# 설치 경로 설정
install(TARGETS button_node
    RUNTIME DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
    DESTINATION include/${PROJECT_NAME}
    FILES_MATCHING PATTERN "*.hpp"
)

# 테스트 빌드 설정
if(BUILD_TESTING)
    find_package(ament_lint_auto REQUIRED)
    ament_lint_auto_find_test_dependencies()
endif()

ament_package()
