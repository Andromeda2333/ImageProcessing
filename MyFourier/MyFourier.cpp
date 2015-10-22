// MyFourier.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <complex>
#include <iostream>
#include <math.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::Mat FourierTrans(const cv::Mat& image);
std::complex<double> Trans(const cv::Mat& image,size_t u,size_t v);
int _tmain(int argc, _TCHAR* argv[])
{
	
	cv::Mat image=cv::imread("image.PNG",CV_LOAD_IMAGE_GRAYSCALE);
	cv::Mat res=FourierTrans(image);
	cv::imshow("image",image);
	cv::imshow("result",res);
	cv::waitKey();
	return 0;
}

cv::Mat FourierTrans( const cv::Mat& image )
{
	cv::Mat result(image.size(),CV_8UC1,cv::Scalar(0));
	size_t rValue=image.rows;
	size_t cValue=image.cols;

	for (size_t r=0;r<rValue;++r)
	{
		for (size_t c=0;c<cValue;++c)
		{
			double temp=log(abs(Trans(image,r,c))+1);
			result.at<uchar>(r,c)=static_cast<uchar>(temp);
		}
	}
	double minV=0;
	double maxV=0;
	cv::minMaxIdx(result,&minV,&maxV);
	result=result/maxV*255;
	return result;
}

std::complex<double> Trans( const cv::Mat& image,size_t u,size_t v )
{
	double rValue=image.rows;
	double cValue=image.cols;
	std::complex<double> temp(0,0);

	for (size_t r=0;r<rValue;++r)
	{
		for (size_t c=0;c<cValue;++c)
		{
			double rad=-2*3.14159*(u*r/rValue+v*c/cValue);
			std::complex<double> mult(cos(rad),sin(rad));
			temp+=static_cast<double>(image.at<uchar>(r,c))*pow(-1,r+c)*mult;
		}
	}
	return temp/(rValue*cValue);
}

