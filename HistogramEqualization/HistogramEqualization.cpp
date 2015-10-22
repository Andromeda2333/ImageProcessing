// HistogramEqualization.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Histogram.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

cv::Mat LocalMat(int i,int j,const cv::Mat& image)
{
	/*获取像素(i,j)的领域:3*3*/
	//uchar m[3][3]={{image.at<uchar>(i-1,j-1),image.at<uchar>(i-1,j),image.at<uchar>(i-1,j+1)},
	//{image.at<uchar>(i,j-1),image.at<uchar>(i,j),image.at<uchar>(i,j+1)},
	//{image.at<uchar>(i+1,j-1),image.at<uchar>(i+1,j),image.at<uchar>(i+1,j+1)}};
	return cv::Mat(image,cv::Rect(i,j,3,3));
}

int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("image.jpg");
	cv::cvtColor(image,image,CV_RGB2GRAY);

	std::cout<<LocalMat(45,23,image)<<std::endl;
	cv::waitKey();
	return 0;

	Histogram h;
	cv::imshow("1",image);
	h.Traditional(image);
	cv::imshow("2",image);
	cv::waitKey();
	return 0;

}