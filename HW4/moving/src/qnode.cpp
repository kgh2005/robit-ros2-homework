#include "../include/moving/qnode.hpp"

QNode::QNode(rclcpp::Node::SharedPtr node)
    : node(node) // 생성자에서 전달된 노드를 사용
{
    this->start(); // QThread 시작
}

QNode::~QNode()
{
    if (rclcpp::ok())
    {
        rclcpp::shutdown();
    }
}

void QNode::init()
{
    // 퍼블리셔 초기화
    publisher_ = node->create_publisher<std_msgs::msg::String>("keypad_commands", 10);

    // 구독자 초기화
    subscription_ = node->create_subscription<std_msgs::msg::String>(
        "keypad_commands", // 구독할 주제 이름
        10,
        std::bind(&QNode::messageCallback, this, std::placeholders::_1) // 콜백 함수 연결
    );
}

void QNode::publishMessage(const std::string& msg)
{
    auto message = std_msgs::msg::String();
    message.data = msg;
    publisher_->publish(message);
}

void QNode::messageCallback(const std_msgs::msg::String::SharedPtr msg)
{
    // 수신된 메시지를 처리하는 부분
    QString command = QString::fromStdString(msg->data);
    emit messageReceived(command); // 메시지를 메인 윈도우로 전송
}

void QNode::run()
{
    rclcpp::WallRate loop_rate(20);
    while (rclcpp::ok())
    {
        rclcpp::spin_some(node); // ROS 콜백 처리
        loop_rate.sleep(); // 루프 속도 조절
    }
    emit rosShutDown(); // ROS 종료 시그널 발송
}

rclcpp::Node::SharedPtr QNode::getNode() const {
    return node; // 노드 반환
}
