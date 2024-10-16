#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class TeleopTurtle : public rclcpp::Node
{
public:
    TeleopTurtle()
    : Node("myteleop"), linear(2), angular(2.0)
    {
        // 퍼블리셔 설정
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
        publisher = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", qos_profile);
        RCLCPP_INFO(this->get_logger(), "'s' square, 'c' circle, 't' triangle, 'r' return, and 'q' quit.");

        // 터미널 설정
        tcgetattr(STDIN_FILENO, &orig_termios);
        termios new_termios = orig_termios;
        new_termios.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

        // 논블로킹 입력 설정
        int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

        // 키 입력 처리
        timer = this->create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&TeleopTurtle::timer_callback, this));
    }

    ~TeleopTurtle()
    {
        // 원래 터미널 설정 복원
        tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
    }

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher;
    rclcpp::TimerBase::SharedPtr timer;
    int linear;
    double angular;
    int x;
    double y;
    termios orig_termios;   // 원래 터미널 속성을 저장할 변수

    // 직선과 회전 동작을 위한 함수
    void draw_line(int linear, double angular)
    {
        auto twist = geometry_msgs::msg::Twist();
        twist.linear.x = linear;
        twist.angular.z = angular;
        publisher->publish(twist);
    }

    // 사각형 그리기
    void square()
    {
        RCLCPP_INFO(this->get_logger(), "Square");
        for (int i = 0; i < 4; i++)
        {
            draw_line(2, 0);  // 직진
            sleep(1); // 대기
            draw_line(0, 1.57); // 90도 회전 (1.57 라디안)
            sleep(1); // 대기
        }
    }

    // 원 그리기
    void circle()
    {
        RCLCPP_INFO(this->get_logger(), "Circle");
        for(int i = 0; i < 4; i++)
        {
            draw_line(2, 1.57); // 원을 그리기
            sleep(1); // 대기
        }
    }

    // 삼각형 그리기
    void triangle()
    {
        RCLCPP_INFO(this->get_logger(), "Triangle");
        for (int i = 0; i < 3; i++)
        {
            draw_line(2, 0.0);  // 직진
            sleep(1); // 대기
            draw_line(0, 2.09); // 120도 회전 (2.09 라디안)
            sleep(1); // 대기
        }
    }

    // 터틀을 중심으로 이동
    void return_to_center()
    {
        RCLCPP_INFO(this->get_logger(), "Returning to Center");
        draw_line(0, y * (-1));
        sleep(1); // 대기
        draw_line(x * (-1), 0);
        sleep(1); // 대기
        draw_line(0, 0.0); // 정지
        x = 0;
        y = 0.0;
    }

    // 타이머 콜백 함수
    void timer_callback()
    {
        char key;
        int size = read(STDIN_FILENO, &key, 1); // 입력 읽기
        if (size > 0)
        {
            if (key == '\x1b') // 방향키는 이스케이프 시퀀스로 시작
            {
                char seq[2];
                read(STDIN_FILENO, &seq[0], 1);
                read(STDIN_FILENO, &seq[1], 1);

                auto twist = geometry_msgs::msg::Twist();
                bool publish = false;

                if (seq[0] == '[') // 방향키 인식
                {
                    switch (seq[1])
                    {
                        case 'A': // 위쪽 화살표
                        case 75:
                            twist.linear.x = linear;
                            x += linear;
                            publish = true;
                            break;
                        case 'B': // 아래쪽 화살표
                        case 77:
                            twist.linear.x = -linear;
                            x -= linear;
                            publish = true;
                            break;
                        case 'C': // 오른쪽 화살표
                        case 79:
                            twist.angular.z = -angular;
                            y -= angular;
                            publish = true;
                            break;
                        case 'D': // 왼쪽 화살표
                        case 76:
                            twist.angular.z = angular;
                            y += angular;
                            publish = true;
                            break;
                    }
                }

                if (publish)
                {
                    publisher->publish(twist); // 메시지 퍼블리시
                    RCLCPP_INFO(this->get_logger(), "Published Twist: linear.x=%.2f, angular.z=%.2f",
                                twist.linear.x, twist.angular.z);
                }
            }
            switch (key)
            {
                case 's':
                    square();
                    break;
                case 'c':
                    circle();
                    break;
                case 't':
                    triangle();
                    break;
                case 'r':
                    return_to_center();
                    break;
                case 'q':
                    RCLCPP_INFO(this->get_logger(), "Shut down");
                    rclcpp::shutdown();
                    break;
            }
        }
    }
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<TeleopTurtle>();
    rclcpp::spin(node); // 노드 실행
    rclcpp::shutdown(); // 종료
    return 0;
}
