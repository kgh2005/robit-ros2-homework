# ROS2_HW2

### How to run

1. Move to workspace and build
```
cd ~/robot_ws
colcon build --packages-select tutorial_interface
colcon build --packages-select my_publisher_pkg
colcon build --packages-select my_subscribe_pkg
```

2. Setting environment variables
```
source install/setup.bash
```

3. Run publisher and subscriber nodes
```
ros2 run my_publisher_pkg publisher_node
ros2 run my_publisher_pkg publisher_node
```
