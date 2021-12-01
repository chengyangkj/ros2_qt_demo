/*
 * @Author: chengyangkj
 * @Date: 2021-10-30 02:08:29
 * @LastEditTime: 2021-12-01 06:18:27
 * @LastEditors: chengyangkj
 * @Description: ros2的通信类 在这个类进行订阅与发布话题
 * @FilePath: /ros2_qt_demo/src/rclcomm.cpp
 * https://github.com/chengyangkj
 */
#include "rclcomm.h"
rclcomm::rclcomm()  {
  int argc=0;
  char **argv=NULL;
  rclcpp::init(argc,argv);
  node=rclcpp::Node::make_shared("ros2_qt_demo");
  _publisher =
      node->create_publisher<std_msgs::msg::Int32>("ros2_qt_demo_publish", 10);
  _subscription = node->create_subscription<std_msgs::msg::Int32>("ros2_qt_demo_publish", 10,std::bind(&rclcomm::recv_callback,this,std::placeholders::_1));
  this->start();
}
void rclcomm::run(){
    //20HZ
    std_msgs::msg::Int32 pub_msg;
    pub_msg.data=0;
    rclcpp::WallRate loop_rate(1);
    while (rclcpp::ok())
    {
        pub_msg.data++;
        _publisher->publish(pub_msg);
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }
    rclcpp::shutdown();
}
void rclcomm::recv_callback(const std_msgs::msg::Int32::SharedPtr msg){
    //  RCLCPP_INFO(node->get_logger(), "I heard: '%d'", msg->data);
    emitTopicData("I head from ros2_qt_demo_publish:"+QString::fromStdString(std::to_string(msg->data)));
}