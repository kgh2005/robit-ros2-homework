#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rclcpp/rclcpp.hpp"
#include "turtle_interface/msg/num.hpp"  // turtle_interface 메시지 타입 포함
#include "geometry_msgs/msg/twist.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    // 버튼 클릭 시 호출되는 슬롯 함수
    void on_up_button_clicked();
    void on_left_button_clicked();
    void on_down_button_clicked();
    void on_right_button_clicked();

private:
    // 방향 정보를 퍼블리시하는 함수
    void publishDirection(double linear, double angular);
    void spinSome();

    Ui::MainWindow *ui;
    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<turtle_interface::msg::Num>::SharedPtr num_publisher_;  // Num 메시지 퍼블리셔
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr twist_publisher_;  // Twist 메시지 퍼블리셔
};

#endif // MAINWINDOW_H
