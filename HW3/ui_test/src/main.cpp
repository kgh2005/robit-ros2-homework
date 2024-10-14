#include "mainwindow.h"
#include <QApplication>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char* argv[])
{
  // ROS 2 초기화
  rclcpp::init(argc, argv);

  // Qt 애플리케이션 초기화
  QApplication a(argc, argv);

  // MainWindow 객체 생성 및 설정
  MainWindow w;
  w.setFixedSize(610, 600);
  w.show();

  // Qt 애플리케이션 실행
  int result = a.exec();

  // ROS 2 종료
  rclcpp::shutdown();

  return result;
}
