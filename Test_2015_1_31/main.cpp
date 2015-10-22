#include <QCoreApplication>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include"histogram1d.h"

void test();
void test_2();
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test_2();
    return a.exec();
}

void test(){
    cv::Mat image=cv::imread("group.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    Histogram1D h;
    cv::MatND histo=h.getHistogram(image);
    for(int i=0;i<256;++i){
        std::cout<<"value"<<i<<"="<<histo.at<float>(i)<<std::endl;
    }

    cv::namedWindow("histogram");
    cv::imshow("histogram",h.getHistogramImg(image));
}
void test_2(){
    cv::Mat image=cv::imread("waves.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    int channels[3]={0,1,2};
    float hrange[2]={0,255};
    const float* ranges[1]={hrange};


    cv::Mat imageROI,result;
    imageROI=image(cv::Rect(360,55,40,50));


//    cv::namedWindow("result");
//    cv::imshow("result",imageROI);

    Histogram1D h;
    cv::MatND histo=h.getHistogram(image);
    cv::normalize(histo,histo,cv::NORM_INF);

    cv::calcBackProject(
                &image,
                1,
                channels,
                histo,
                result,
                ranges,
                255);
    result.convertTo(result,CV_8U,-1,255);

    cv::threshold(result,result,120,255,cv::THRESH_BINARY);
    cv::namedWindow("result");
    cv::imshow("result",result);
}
