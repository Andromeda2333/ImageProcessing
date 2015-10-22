#include <QCoreApplication>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

cv::Mat getObject(cv::Mat src_back,cv::Mat src_fore);
cv::Mat getObject(cv::Mat src);
cv::Mat getCannyImg(cv::Mat src);

cv::Mat getFilterImg(cv::Mat src);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat src_back=cv::imread("E:\\code\\Edge_extraction\\DSC05498.JPG",CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat src_fore=cv::imread("E:\\code\\Edge_extraction\\DSC05504.JPG",CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat src_back_2,src_fore_2;
    cv::pyrDown(src_back,src_back_2);
    cv::pyrDown(src_fore,src_fore_2);

    cv::Mat dst;
//    cv::GaussianBlur(src_fore_2,dst,cv::Size(4,5),0.5,0.5);
    cv::namedWindow("src window");
    cv::namedWindow("dst window");
    dst=getObject(src_back_2,src_fore_2);
//    dist=getObject(src_fore_2);

//    dst=getFilterImg(src_fore_2);

    cv::Mat ROI=dst(cv::Range((int)(dst.rows*0.20),(int)(dst.rows*0.925)),
                    cv::Range((int)(dst.cols*0.20),(int)(dst.cols*0.90)));
    cv::Mat ROI_img;
    ROI.copyTo(ROI_img);

    std::cout<<ROI_img.rows<<"  "<<ROI_img.cols;
//    cv::medianBlur(ROI_img,ROI_img,5);
//    cv::equalizeHist(ROI_img,ROI_img);
//    cv::imwrite("edge_1.jpg",ROI_img);
//    cv::namedWindow("ROI");
//    cv::imshow("ROI",ROI_img);
//    cv::threshold(ROI_img,ROI_img,0,255,CV_THRESH_BINARY|CV_THRESH_OTSU);

    cv::imwrite("edge_2.jpg",ROI_img);
    cv::namedWindow("edge");
    cv::imshow("edge",ROI_img);

    cv::imwrite("src_img.jpg",src_fore_2);
    cv::imwrite("dst_img.jpg",dst);
    cv::imshow("src window",src_fore_2);
    cv::imshow("dst window",dst);
    cv::waitKey();

    return a.exec();
}

cv::Mat getObject(cv::Mat src_back,cv::Mat src_fore){
    cv::Mat src_back_double,src_fore_double,object;
    src_back.convertTo(src_back_double,CV_64F);
    src_fore.convertTo(src_fore_double,CV_64F);
    cv::absdiff(src_fore_double,src_back_double,object);
//    object=src_fore_double-src_back_double;
    cv::normalize(object,object,0,255,cv::NORM_MINMAX);
//    std::cout<<object;
//    cv::Mat object_2;
//    object.copyTo(object_2);
//    cv::Laplacian(object_2,object_2,CV_64F,3);

//    object+=object_2;
//    cv::normalize(object,object,0,255,CV_MINMAX);
    object.convertTo(object,CV_8U);
//    object=getFilterImg(object);
//    object=getCannyImg(object);

    return object;
}
cv::Mat getFilterImg(cv::Mat src){
    cv::Mat dst;
//    cv::medianBlur(src,dst,3);
    cv::morphologyEx(src,dst,cv::MORPH_CLOSE,cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(3,3)));
//    cv::morphologyEx(dst,dst,cv::MORPH_OPEN,cv::getStructuringElement(cv::MORPH_ELLIPSE,cv::Size(3,3)));
    return dst;
}
cv::Mat getObject(cv::Mat src){
    cv::Mat src_2;
    cv::equalizeHist(src_2,src_2);
    src.convertTo(src_2,CV_64F);
    cv::Mat src_lap;
    cv::Laplacian(src_2,src_lap,CV_64F,3);
    src_lap=src_lap+src_2;
    cv::normalize(src_lap,src_lap,0,255,CV_MINMAX);
    src_lap.convertTo(src_lap,CV_8U);
    return src_lap;
}
cv::Mat getCannyImg(cv::Mat src){
    cv::Mat dst;
    cv::GaussianBlur(src,dst,cv::Size(5,5),0.4,0.4);
//    cv::Canny(dst,dst,133,47);
    return dst;
}
