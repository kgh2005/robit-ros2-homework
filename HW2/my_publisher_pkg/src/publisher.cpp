#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "tutorial_interface/msg/num.hpp"

using namespace std::chrono_literals;

class Publisher : public rclcpp::Node
{
  public:
    Publisher()
    : Node("publisher")
    {
      publisher_ = this->create_publisher<tutorial_interface::msg::Num>("topic", 10);
      timer_ = this->create_wall_timer(
      500ms, std::bind(&Publisher::timer_callback, this));
    }

  private:
    void timer_callback()
    {
      auto message = tutorial_interface::msg::Num();  // Num 메시지 타입 사용

      // 사용자 입력 받기
      std::string text_input;

      std::cout << "Enter : ";
      std::cin >> text_input;

      // message에 저장
      message.message = text_input;

      // 로그 출력
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.message.c_str());

      // 메시지 전송
      publisher_->publish(message);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<tutorial_interface::msg::Num>::SharedPtr publisher_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Publisher>());
  rclcpp::shutdown();
  return 0;
}
