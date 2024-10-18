#ifndef QNODE_H
#define QNODE_H

#include <QThread>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class QNode : public QThread {
    Q_OBJECT

public:
    QNode(rclcpp::Node::SharedPtr node);
    ~QNode();

    void init();
    void publishMessage(const std::string& msg);
    rclcpp::Node::SharedPtr getNode() const; // getNode 메서드 추가

protected:
    void run() override;

signals:
    void messageReceived(const QString &message);
    void rosShutDown();

private:
    rclcpp::Node::SharedPtr node;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

    void messageCallback(const std_msgs::msg::String::SharedPtr msg);
};

#endif // QNODE_H
