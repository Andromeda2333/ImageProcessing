// Blur.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int DELAY_CAPTION=1500;
int DELAY_BLUR=200;
int MAX_KERNEL_ENGTH=40;

cv::Mat src;
cv::Mat dst;
char windowName[]="Filter Demo 1";

int DisplayCaption(char* caption);
int DisplayDst(int delay);

int _tmain(int argc, _TCHAR* argv[])
{
	cv::namedWindow(windowName,CV_WINDOW_AUTOSIZE);
	//载入源图像
	src=cv::imread("image.jpg",1);
	if (DisplayCaption("Original Image")!=0)
	{
		return 0;
	}
	
	dst=src.clone();
	if (DisplayDst(DELAY_CAPTION)!=0)
	{
		return 0;
	}

	///使用均值平滑
	if (DisplayCaption("Homogeneous Blur")!=0)
	{
		return 0;
	}
	for (int i=1;i<MAX_KERNEL_ENGTH;i+=2)
	{
		cv::blur(src,dst,cv::Size(i,i),cv::Point(-1,-1));
		if (DisplayDst(DELAY_BLUR)!=0)
		{
			return 0;
		}
	}

	//使用高斯平滑
	if (DisplayCaption("Gaussian Blur")!=0)
	{
		return 0;
	}
	for (int i=1;i<MAX_KERNEL_ENGTH;i+=2)
	{
		cv::GaussianBlur(src,dst,cv::Size(i,i),
			0,0);
		if (DisplayDst(DELAY_BLUR)!=0)
		{
			return 0;
		}
	}

	//使用中指平滑
	if (DisplayCaption("Median Blur")!=0)
	{
		return 0;
	}
	for (int i=1;i<MAX_KERNEL_ENGTH;i+=2)
	{
		cv::medianBlur(src,dst,i);
		if (DisplayDst(DELAY_BLUR)!=0)
		{
			return 0;
		}
	}

	//使用双边平滑
	if (DisplayCaption("Bilateral Blur")!=0)
	{
		return 0;
	}
	for (int i=1;i<MAX_KERNEL_ENGTH;i+=2)
	{
		cv::bilateralFilter(src,dst,i,i*2,i/2);
		if (DisplayDst(DELAY_BLUR)!=0)
		{
			return 0;
		}
	}
	DisplayCaption("End: Press a key!");

	cv::waitKey();
	return 0;
}

int DisplayCaption( char* caption )
{
	dst=cv::Mat::zeros(src.size(),src.type());

	cv::putText(dst,caption,
		cv::Point(src.cols/4,src.rows/4),
		CV_FONT_HERSHEY_COMPLEX,1,cv::Scalar(255,255,255));
	cv::imshow(windowName,dst);

	int c=cv::waitKey(DELAY_CAPTION);
	if (c>=0)
	{
		return -1;
	}

	return 0;
}

int DisplayDst( int delay )
{
	cv::imshow(windowName,dst);

	int c=cv::waitKey(delay);
	if (c>=0)
	{
		return -1;
	}

	return 0;
}

