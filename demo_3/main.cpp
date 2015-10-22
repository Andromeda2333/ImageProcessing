#include <QCoreApplication>
#include<opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IplImage* p=cvLoadImage("dst_img.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    cvNamedWindow("1");
    cvShowImage("1",p);

    cv::Mat img(p);
    cv::namedWindow("2");
    cv::imshow("2",img);
    IplImage p2(img);
    cvNamedWindow("3");
    cvShowImage("3",&p2);
    return a.exec();
}
