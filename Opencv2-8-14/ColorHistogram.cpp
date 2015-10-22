#include "stdafx.h"
#include "ColorHistogram.h"


ColorHistogram::ColorHistogram(void)
{
	histSize[0]=histSize[1]=histSize[2]=256;
	hranges[0]=0;
	hranges[1]=256;
	ranges[0]=ranges[1]=ranges[2]=hranges;
	channels[0]=0;
	channels[1]=1;
	channels[2]=2;
}


ColorHistogram::~ColorHistogram(void)
{
}

cv::MatND ColorHistogram::GetHistogram( const cv::Mat& image )
{
	cv::MatND hist;
	cv::calcHist(&image,
		1,
		channels,
		cv::Mat(),
		hist,
		3,
		histSize,
		ranges
		);
	return hist;
}

cv::SparseMat ColorHistogram::GetSparseHitogram( const cv::Mat& image )
{
	cv::SparseMat hist(3,histSize,CV_32F);
	cv::calcHist(&image,
		1,
		channels,
		cv::Mat(),
		hist,
		3,
		histSize,
		ranges
		);
	return hist;
}

cv::MatND ColorHistogram::GetHueHistogram( const cv::Mat& image,int minSaturation/*=0*/ )
{
	cv::MatND hist;
	cv::Mat hsv;
	cv::cvtColor(image,hsv,CV_RGB2HSV);
	cv::Mat mask; 
	if (minSaturation>0)
	{
		std::vector<cv::Mat>v;
		cv::split(hsv,v);
		cv::threshold(v[1],mask,minSaturation,255,cv::THRESH_BINARY);
	}
	hranges[0]=0;
	hranges[1]=180;
	channels[0]=0;
	cv::calcHist(&hsv,
		1,
		channels,
		mask,
		hist,
		1,
		histSize,
		ranges
		);
	return hist;
}