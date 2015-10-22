#include <QCoreApplication>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
void show();
void test(){
    double data[9]={1,25,4,5,6,7,8,9,0};
    cv::Mat m(cv::Size(3,3),CV_64F,data);
    std::cout<<m<<'\n';
    cv::normalize(m,m,250,0,cv::NORM_MINMAX);
    std::cout<<m<<'\n';
}

cv::Mat getDftImg(cv::Mat src);
cv::Mat dft2Shift(cv::Mat src);
cv::Mat getBLPF(int rows,int cols);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    show();
    return a.exec();
}
void show(){
    cv::Mat src=cv::imread("./edge_2.JPG",CV_LOAD_IMAGE_GRAYSCALE);
//    cv::pyrDown(src,src);

    cv::Mat dft_img=getDftImg(src);

    cv::namedWindow("src");
    cv::imshow("src",src);
    cv::namedWindow("dst");
    cv::imshow("dst",dft_img);
    cv::imwrite("dst_img.jpg",dft_img);
    cv::waitKey();
}

cv::Mat getDftImg(cv::Mat src){
    cv::Mat padded;
    int m=cv::getOptimalDFTSize(src.rows);
    int n=cv::getOptimalDFTSize(src.cols);
    cv::copyMakeBorder(src,padded,0,m-src.rows,0,n-src.cols,cv::BORDER_CONSTANT,cv::Scalar::all(0));
    padded=dft2Shift(padded);
    cv::Mat planes[]={padded,cv::Mat::zeros(padded.size(),CV_32F)};
    cv::Mat complexI;
    cv::merge(planes,2,complexI);

    cv::dft(complexI,complexI);
    cv::split(complexI,planes);
//    cv::magnitude(planes[0],planes[1],planes[0]);

    cv::Mat BLPF=getBLPF(m,n);
    cv::multiply(planes[0],BLPF,planes[0]);
    cv::multiply(planes[1],BLPF,planes[1]);

    cv::merge(planes,2,complexI);
    cv::idft(complexI,complexI);

    cv::split(complexI,planes);
    cv::Mat magI=dft2Shift(planes[0]);
//    magI+=cv::Scalar::all(1);
//    cv::log(magI,magI);
    cv::normalize(magI, magI, 255,0, cv::NORM_MINMAX);
    magI.convertTo(magI,CV_8U);
    cv::Mat timg=magI(cv::Range(0,src.rows),cv::Range(0,src.cols));
    return timg;
}
cv::Mat dft2Shift(cv::Mat src){
    cv::Mat dst;
    src.copyTo(dst);
    dst.convertTo(dst,CV_32F);

     float* p;
    for (int i=0;i<dst.rows;++i){
        p=dst.ptr<float>(i);
        for (int j=0;j<dst.cols;++j){
            p[j]=p[j]*std::pow(-1,i+j);
        }
    }
    return dst;
}

cv::Mat getBLPF(int rows,int cols){
    cv::Mat tmp=cv::Mat::zeros(rows,cols,CV_32F);
    float d_0=6,n=2,h_l=0.5,h_h=2;
    float h=h_h-h_l;
    float cent_x=rows/2,cent_y=cols/2;


    float* p;
    for (int i=0;i<rows;++i){
        p=tmp.ptr<float>(i);
        for (int j=0;j<cols;++j){
            p[j]=h/(1+std::pow(d_0/(std::sqrt((i-cent_x)*(i-cent_x)+
                                              (j-cent_y)*(j-cent_y))),2*n))+h_l;
        }
    }
    return tmp;
}
