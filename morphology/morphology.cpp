// morphology.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
cv::Mat src,dst;
int morphElem=0;
int morphSize=0;
int morphOPerator=0;
int const maxOPerator=4;
int const maxElem=2;
int const maxKernelSize=21;
std::string windowName="Morpholopy Transformation";

void MorphologyOperations(int,void*);
int _tmain(int argc, _TCHAR* argv[])
{
	src=cv::imread("image.jpg");
	cv::namedWindow(windowName,CV_WINDOW_AUTOSIZE);
	
	cv::createTrackbar("Operator: \n\r   0: Opening - 1: Closing  \n\r   2: Gradient - 3: Top Hat  \n\r   4: Black Hat",
		windowName,&morphOPerator,maxOPerator,MorphologyOperations);
	cv::createTrackbar("Element: \n\r   0: Rect - 1: Cross - 2: Ellipse",
		windowName,&morphElem,maxElem,MorphologyOperations);
	cv::createTrackbar("Kernerl size: \n\r 2n+1",
		windowName,&morphSize,maxKernelSize,MorphologyOperations);
	cv::waitKey();

	return 0;
}

void MorphologyOperations( int,void* )
{
	int operation=morphOPerator+2;
	cv::Mat element=getStructuringElement(
		morphElem,cv::Size(morphSize*2+1,morphSize*2+1),
		cv::Point(morphSize,morphSize));
	cv::morphologyEx(src,dst,operation,element);
	cv::imshow(windowName,dst);
}

