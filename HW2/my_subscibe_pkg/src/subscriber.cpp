#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "tutorial_interface/msg/num.hpp"

class Subscriber : public rclcpp::Node
{
  public:
    Subscriber()
    : Node("subscriber")
    {
      // 메시지가 수신될 때마다 콜백 함수 호출
      subscription_ = this->create_subscription<tutorial_interface::msg::Num>(
        "topic", 10, std::bind(&Subscriber::topic_callback, this, std::placeholders::_1));
        // 수신된 메시지를 전달
    }

  private:
  // 로그로 출력
    void topic_callback(const tutorial_interface::msg::Num::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "text = %s", msg->message.c_str());
    }

    rclcpp::Subscription<tutorial_interface::msg::Num>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Subscriber>());
  rclcpp::shutdown();
  return 0;
}
