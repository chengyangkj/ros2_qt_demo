/*
 * @Author: chengyangkj
 * @Date: 2021-10-30 02:09:08
 * @LastEditTime: 2021-12-01 06:01:17
 * @LastEditors: chengyangkj
 * @Description: 
 * @FilePath: /ros2_qt_demo/include/ros2_qt_demo/mainwindow.h
 * https://github.com/chengyangkj
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rclcomm.h"
#include <iostream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    rclcomm *commNode;
public slots:
    void updateTopicInfo(QString);
};
#endif // MAINWINDOW_H
