#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIcon icon(":/image/images/icon.png");
    setWindowIcon(icon);

    // ROS 2 초기화
    rclcpp::init(0, nullptr);

    // 노드 및 퍼블리셔 생성
    node_ = rclcpp::Node::make_shared("turtle_teleop_gui");
    publisher_ = node_->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
}

MainWindow::~MainWindow()
{
    rclcpp::shutdown();
    delete ui;
}

void MainWindow::publishDirection(double linear, double angular)
{
    auto msg = geometry_msgs::msg::Twist();
    msg.linear.x = linear;
    msg.angular.z = angular;

    // 메시지를 퍼블리시
    publisher_->publish(msg);
}

// 앞으로 이동
void MainWindow::on_up_button_clicked()
{
    publishDirection(1.0, 0.0);
}

// 왼쪽 회전
void MainWindow::on_left_button_clicked()
{
    publishDirection(0.0, 1.0);
}

// 뒤로 이동
void MainWindow::on_down_button_clicked()
{
    publishDirection(-1.0, 0.0);
}

// 오른쪽 회전
void MainWindow::on_right_button_clicked()
{
    publishDirection(0.0, -1.0);
}
