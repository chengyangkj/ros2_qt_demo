/*
 * @Author: chengyangkj
 * @Date: 2021-10-30 02:15:28
 * @LastEditTime: 2021-10-31 06:02:40
 * @LastEditors: chengyangkj
 * @Description: ros2的通信类 在这个类进行订阅与发布话题
 * @FilePath: /ros_apps/src/ros2_qt_demo/include/ros2_qt_demo/rclcomm.h
 * https://github.com/chengyangkj
 */
#ifndef RCLCOMM_H
#define RCLCOMM_H
#include <QObject>
#include <QThread>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
using namespace std::chrono_literals;
class rclcomm:public QThread,public rclcpp::Node
{
    Q_OBJECT
public:
    rclcomm();
    void run();
private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _publisher;
};

#endif // RCLCOMM_H
