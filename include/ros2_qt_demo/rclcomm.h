/*
 * @Author: chengyangkj
 * @Date: 2021-10-30 02:15:28
 * @LastEditTime: 2021-12-01 06:03:51
 * @LastEditors: chengyangkj
 * @Description: ros2的通信类 在这个类进行订阅与发布话题
 * @FilePath: /ros2_qt_demo/include/ros2_qt_demo/rclcomm.h
 * https://github.com/chengyangkj
 */
#ifndef RCLCOMM_H
#define RCLCOMM_H
#include <QObject>
#include <QThread>
#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include "std_msgs/msg/int32.hpp"
class rclcomm:public QThread
{
    Q_OBJECT
public:
    rclcomm();
    void publish_topic(int count);
    void recv_callback(const std_msgs::msg::Int32::SharedPtr msg);
protected:
    void run();
private:
    rclcpp::Publisher<std_msgs::msg::Int32>::SharedPtr _publisher;
    rclcpp::Subscription<std_msgs::msg::Int32>::SharedPtr _subscription;
    std::shared_ptr<rclcpp::Node> node;
signals:
    void emitTopicData(QString);
};
#endif // RCLCOMM_H
