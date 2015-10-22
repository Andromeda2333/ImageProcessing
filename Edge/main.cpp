#include <QCoreApplication>
#include<iostream>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::cout<<cv::Mat::eye(3,3,CV_8U);
    return a.exec();
}
