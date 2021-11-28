/*
 * @Author: chengyangkj
 * @Date: 2021-11-27 19:02:15
 * @LastEditTime: 2021-11-28 06:23:28
 * @LastEditors: chengyangkj
 * @Description: 
 * @FilePath: /ros_app/src/ros2_qt_demo/src/main.cpp
 * https://github.com/chengyangkj
 */
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
