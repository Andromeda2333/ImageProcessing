#include "stdafx.h"
#include "Histogram1D.h"


Histogram1D::Histogram1D(void)
{
	histSize[0]=256;
	hranges[0]=0;
	hranges[1]=255;
	ranges[0]=hranges;
	channels[0]=0;
}


Histogram1D::~Histogram1D(void)
{
}

cv::MatND Histogram1D::GetHistogram( const cv::Mat &image )
{
	cv::MatND hist;
	cv::calcHist(&image,1,channels,cv::Mat(),hist,1,histSize,ranges);
	return hist;
}

cv::Mat Histogram1D::GetHistogramImage( const cv::Mat &image )
{
	cv::MatND hist=GetHistogram(image);

	double maxVal=0;
	double minVal=0;
	cv::minMaxLoc(hist,&minVal,&maxVal,0,0);
	cv::Mat histImg(histSize[0],histSize[0],CV_8U,cv::Scalar(255));
	int hpt=static_cast<int>(0.9*histSize[0]);
	for (int h=0;h<histSize[0];++h)
	{
		float binVal=hist.at<float>(h);
		int intensity=static_cast<int>(binVal*hpt/maxVal);
		cv::line(histImg,cv::Point(h,histSize[0]),
			cv::Point(h,histSize[0]-intensity),cv::Scalar::all(0));
	}
	return histImg;
}
