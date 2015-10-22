// Opencv2-8-14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Solver.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "ColorHistogram.h"
#include "ContentFinder.h"
int _tmain(int argc, _TCHAR* argv[])
{
	/*cv::Mat image1=cv::imread("1.jpg");
	cv::Mat image;
	cv::cvtColor(image1,image,CV_BGR2GRAY);
	cv::namedWindow("1");
	cv::imshow("1",image);

	Solver s;
	cv::Mat result=s.Equalize(image);
	cv::namedWindow("2");
	cv::imshow("2",result);
	cv::waitKey();*/
	cv::Mat image=cv::imread("baboon1.jpg");
	cv::namedWindow("baboon1");
	cv::imshow("baboon1",image);
	cv::waitKey();
	return 0;
}

