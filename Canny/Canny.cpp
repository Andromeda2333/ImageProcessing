// Canny.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>

cv::Mat src,dst,srcGray,detectedEdges;
int kernelSize=3;
int lowThreshold;
int const maxThreshold=100;
std::string windowName="±ßÔµÍ¼Ïñ";

void CannyThreshold(int,void*);

int _tmain(int argc, _TCHAR* argv[])
{
	src=cv::imread("image.jpg");
	if (!src.data)
	{
		std::cerr<<"error!!\n";
	}
	cv::cvtColor(src,srcGray,CV_RGB2GRAY);
	dst.create(srcGray.size(),srcGray.type());
	cv::namedWindow(windowName,CV_WINDOW_AUTOSIZE);

	cv::createTrackbar("Min threshold:",windowName,&lowThreshold,
		maxThreshold,CannyThreshold);
	CannyThreshold(0,0);

	cv::waitKey();
	return 0;
}

void CannyThreshold( int,void* )
{
	cv::blur(srcGray,detectedEdges,cv::Size(kernelSize,kernelSize));
	cv::Canny(detectedEdges,detectedEdges,lowThreshold,3*lowThreshold,kernelSize);
	dst=cv::Scalar::all(0);

	src.copyTo(dst,detectedEdges);
	cv::imshow(windowName,dst);
}

