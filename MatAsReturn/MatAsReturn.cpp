// MatAsReturn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
cv::Mat ROI(cv::Mat& image,int i,int j);
uchar Average(cv::Mat& localImage);
int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("image.tif");
	cv::cvtColor(image,image,CV_RGB2GRAY);
	for (int i=0;i<100;++i)
	{
		std::cout<<static_cast<int>(Average(ROI(image,i,i)))<<std::endl;
	}
	return 0;
}

cv::Mat ROI( cv::Mat& image,int i,int j)
{
	return cv::Mat(image,cv::Rect(i,j,3,3));
}

uchar Average( cv::Mat& localImage )
{
	int sum=0;
	for (int i=0;i<localImage.rows;++i)
	{
		for (int j=0;j<localImage.cols;++j)
		{
			sum+=localImage.at<uchar>(i,j);
		}
	}
	return sum/(localImage.rows*localImage.cols);
}

