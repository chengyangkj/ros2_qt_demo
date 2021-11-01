/*
 * @Author: chengyangkj
 * @Date: 2021-10-30 02:08:29
 * @LastEditTime: 2021-11-01 07:02:20
 * @LastEditors: chengyangkj
 * @Description: ros2的通信类 在这个类进行订阅与发布话题
 * @FilePath: /ros_apps/src/ros2_qt_demo/src/rclcomm.cpp
 * https://github.com/chengyangkj
 */
#include "rclcomm.h"

rclcomm::rclcomm() : Node("ros2_qt_demo") {
  int argc;
  char **argv;
  //开启线程
  this->start();
  _publisher =
      this->create_publisher<std_msgs::msg::String>("ros2_qt_demo_publish", 10);
}
void rclcomm::run() {
   int argc;
   char** argv;
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcomm>();
  rclcpp::executors::MultiThreadedExecutor executor;
  executor.add_node(node->get_node_base_interface());
int count_ = 0;
  // 1hz
  int sleep_time = 1000;
  while (rclcpp::ok()) {
    count_++;
     executor.spin_some();
    auto message = std_msgs::msg::String();
    message.data = "Hello, world! " + std::to_string(count_++);
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
    QThread::msleep(sleep_time);
  }
    rclcpp::shutdown();
}