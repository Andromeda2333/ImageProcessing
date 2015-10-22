// Laplace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Sharpen.h"
#include <iostream>
#include "MyClass.h"
#include <string>
int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("image5.JPG");
	cv::cvtColor(image,image,CV_RGB2GRAY);


	double m[3][3]={-1,-1,-1,-1,8,-1,-1,-1,-1};
	cv::Mat laplaceMat(3,3,CV_64FC1,m);

	
	cv::Mat result=Sharpen::Laplace(image,laplaceMat);
	cv::Mat resultMore=Sharpen::LaplaceMore(image,laplaceMat);
	cv::imshow("Before",image);
	cv::imshow("Result",result);
	cv::imshow("ResultMore",resultMore);
	cv::waitKey();



	return 0;
}

