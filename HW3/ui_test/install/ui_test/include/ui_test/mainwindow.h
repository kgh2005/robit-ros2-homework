#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "geometry_msgs/msg/twist.hpp"
#include "rclcpp/rclcpp.hpp"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_up_button_clicked();
    void on_left_button_clicked();
    void on_down_button_clicked();
    void on_right_button_clicked();

private:
    Ui::MainWindow* ui;

    // ROS2 노드를 멤버 변수로 선언
    rclcpp::Node::SharedPtr node_;
    // ROS2 퍼블리셔
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;

    // Twist 메시지를 퍼블리시하는 함수 선언
    void publishDirection(double linear, double angular);
};

#endif  // MAINWINDOW_H
