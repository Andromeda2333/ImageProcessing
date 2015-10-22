#include <QCoreApplication>
#include<QDebug>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout<<cv::Mat::eye(cv::Size(3,3),CV_8U);

    qDebug()<<"hello world !!";
    return a.exec();
}
