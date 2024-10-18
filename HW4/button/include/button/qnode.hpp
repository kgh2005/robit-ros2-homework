#ifndef QNODE_HPP_
#define QNODE_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <QThread>

class QNode : public QThread
{
    Q_OBJECT

public:
    QNode();
    virtual ~QNode();
    void init();
    void publishMessage(const std::string& msg);

public Q_SLOTS:
    void messageCallback(const std_msgs::msg::String::SharedPtr msg); // 콜백 함수 선언

Q_SIGNALS:
    void rosShutDown(); // 신호 선언

private:
    void run() override;

    rclcpp::Node::SharedPtr node;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_; // 구독자 변수 선언
};

#endif // QNODE_HPP_
