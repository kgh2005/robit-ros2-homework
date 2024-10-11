# ROS2_HW1_Turtlesim

### 노드 실행 방법

```
ros2 pkg create myteleop --build-type ament_cmake --dependencies rclcpp geometry_msgs turtlesim
```

- `ros2 pkg create` : ROS2에서 새로운 패키지를 생성하는 명령어
- `myteleop` : 생성할 패키지 이름
- `—build-type ament_cmake` : 패키지의 빌드 시스템으로 `ament_cmake`를 사용하도록 지정
- `--dependencies`: 패키지가 의존하는 다른 ROS2 패키지를 나열합니다.
    - `rclcpp`, `geometry_msgs`, `turtlesim` 패키지를 의존성으로 추가

```
cd ~/robot_ws
colcon build --packages-select myteleop
```

작업공간으로 이동 후 빌드

- `colcon build` : ROS2 패키지를 빌드하는 명령어
- `-packages-select myteleop` : 특정 패키지(`myteleop`)만 빌드하도록 지정

```
source ~/robot_ws/install/setup.bash
```

- ROS2 작업공간의 설치된 패키지와 라이브러리를 사용하기 위해 환경 변수를 설정

```
ros2 run turtlesim turtlesim_node
```

- `ros2 run` : 지정한 패키지에서 특정 노드를 실행하는 명령어
- `turtlesim` : 실행할 패키지의 이름
- `turtlesim_node` : 실행할 노드의 이름

```
ros2 run myteleop myteleop
```

- `ros2 run`: 이전과 같이 특정 패키지에서 노드를 실행하는 명령어
- `myteleop`: 실행할 패키지의 이름
- `myteleop`: 실행할 노드의 이름
    - `CMakeLists.txt` 파일의 `add_executable`에서 정의한 노드의 이름과 일치해야함
