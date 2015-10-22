// Filter4-24-2014.cpp : Defines the entry point for the console application.
//
// Filter4-24-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
cv::Mat GetHistImage(cv::Mat& imageVec );
int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat src=cv::imread("Fig0504(i)(salt-pepper-noise).tif",
		CV_LOAD_IMAGE_GRAYSCALE);
	if (src.empty())
	{
		std::cerr<<"Error!";
	}
	cv::namedWindow("picture",CV_WINDOW_AUTOSIZE);
	cv::imshow("picture",src);
	cv::imshow("result",GetHistImage(src));
	cv::waitKey();
	return 0;
}

cv::Mat GetHistImage(cv::Mat& imageVec )
{

	cv::Mat hist;
	int channels[1]={0};
	int histSize=256;
	float hrange[2]={0,256};
	const float* ranges[1]={hrange};
	cv::calcHist(&imageVec,
		1,
		channels,
		cv::Mat(),
		hist,
		1,
		&histSize,
		ranges);
	std::cout<<hist.type();
	double maxV,minV;
	cv::minMaxIdx(hist,&minV,&maxV);
	cv::Mat histImage(256,256,CV_8U,cv::Scalar(255));
	int htp=256;
	for (size_t i=0;i<256;++i)
	{
		float binVal=hist.at<float>(i);
		int temp=static_cast<int>(binVal*htp/maxV);
		cv::line(histImage,cv::Point(i,256),
		cv::Point(i,256-temp),cv::Scalar(0));
	}

	return histImage;
}

