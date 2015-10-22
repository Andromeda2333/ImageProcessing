// Threshold.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>

cv::Mat src,dst;
std::string windowName="Threshold Demo";
int thresh=0,threshType=0;
std::string trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
std::string trackbar_value = "Value";
void ThresholdDemo(int,void*);
int _tmain(int argc, _TCHAR* argv[])
{
	src=cv::imread("image.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	cv::namedWindow(windowName,CV_WINDOW_AUTOSIZE);
	cv::createTrackbar(trackbar_type,windowName,
		&threshType,4,ThresholdDemo);
	cv::createTrackbar(trackbar_value,windowName,
		&thresh,255,ThresholdDemo);
	ThresholdDemo( 0, 0 );
	cv::waitKey();
	return 0;
}

void ThresholdDemo( int,void* )
{
	cv::threshold(src,dst,thresh,255,threshType);
	cv::imshow(windowName,dst);
}

