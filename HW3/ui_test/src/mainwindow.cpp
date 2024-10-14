#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "geometry_msgs/msg/twist.hpp"
#include "turtle_interface/msg/num.hpp"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ROS 2 노드 생성
    node_ = rclcpp::Node::make_shared("ui_node");

    // 퍼블리셔 생성
    twist_publisher_ = node_->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
    num_publisher_ = node_->create_publisher<turtle_interface::msg::Num>("direction_topic", 10);

    // 타이머 설정
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::spinSome);  // 타이머가 호출될 때 spinSome 호출
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::publishDirection(double linear, double angular) {
    // Num 메시지 생성 및 퍼블리시
    auto num_msg = turtle_interface::msg::Num();
    num_msg.linear_x = linear;
    num_msg.angular_z = angular;
    num_publisher_->publish(num_msg);

    // Twist 메시지 생성 및 퍼블리시
    auto twist_msg = geometry_msgs::msg::Twist();
    twist_msg.linear.x = linear;
    twist_msg.angular.z = angular;
    twist_publisher_->publish(twist_msg);
}

void MainWindow::on_up_button_clicked()
{
    publishDirection(1.0, 0.0);
}

void MainWindow::on_left_button_clicked()
{
    publishDirection(0.0, 1.0);
}

void MainWindow::on_down_button_clicked()
{
    publishDirection(-1.0, 0.0);
}

void MainWindow::on_right_button_clicked()
{
    publishDirection(0.0, -1.0);
}

void MainWindow::spinSome()
{
    rclcpp::spin_some(node_);
}
