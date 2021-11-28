/*
 * @Author: chengyangkj
 * @Date: 2021-10-30 03:11:50
 * @LastEditTime: 2021-11-28 07:33:31
 * @LastEditors: chengyangkj
 * @Description: 程序的主入口类
 * @FilePath: /ros_app/src/ros2_qt_demo/src/mainwindow.cpp
 * https://github.com/chengyangkj
 */
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage img;
    img.load(":/icon/images/foxy.jpg");
    img.scaled(ui->label->width(),ui->label->height());
    ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    commNode=new rclcomm();
    connect(commNode,SIGNAL(emitTopicData(QString)),this,SLOT(updateTopicInfo(QString)));
}
void MainWindow::updateTopicInfo(QString data){
    ui->label_4->setText(data);
}
MainWindow::~MainWindow()
{
    delete ui;
}

