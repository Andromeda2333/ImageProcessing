// Filter2-4-24-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
cv::Mat geoMean(cv::Mat src);
double Multi(cv::Mat ROI);
cv::Mat MaxBlur(cv::Mat src);
cv::Mat MinBlur(cv::Mat src);
cv::Mat MidBlur(cv::Mat src);

int _tmain(int argc, _TCHAR* argv[])
{
	Mat src=imread("Fig0507(b)(ckt-board-gauss-var-400).tif",CV_LOAD_IMAGE_GRAYSCALE);
	imshow("picture",src);

	Mat dst;
	//cv::medianBlur(src,dst,3);//中值滤波
	//cv::imshow("medianBlur",dst);

	//
	//cv::blur(src,dst,Size(3,3),Point(-1,-1));//算数均值
	//cv::imshow("blur",dst);

	//
	//dst=geoMean(src);//几何均值
	//cv::imshow("ds",dst);

	dst=MaxBlur(src);//最大值滤波
	cv::imshow("maxblur",dst);

	dst=MinBlur(src);//最小值滤波
	cv::imshow("minblur",dst);

	dst=MidBlur(src);//中点滤波
	cv::imshow("midblur",dst);

	cv::waitKey();
	return 0;
}

cv::Mat geoMean( cv::Mat src)
{
	cv::copyMakeBorder(src,src,1,1,1,1,BORDER_CONSTANT);
	cv::Mat dst(src.size(),CV_64F,cv::Scalar(0));
	double tag=1.0/9.0;

	for (int i=1;i<src.rows-1;++i)
	{
		for (int j=1;j<src.cols-1;++j)
		{
		cv::Mat ROI(src,cv::Rect(j-1,i-1,3,3));
		double tem=Multi(ROI);
		//std::cout<<tem<<std::endl;
		dst.at<double>(i,j)=std::pow(tem,tag);
		}
	}
	dst.convertTo(dst,CV_8UC1);
	return dst;
}

double Multi( cv::Mat ROI )
{
	double total=1;
	for (int i=0;i<ROI.cols;++i)
	{
		for (int j=0;j<ROI.rows;++j)
		{
			total*=ROI.at<uchar>(i,j);
		}
	}
	return total;
}

cv::Mat MaxBlur( cv::Mat src )
{
	cv::copyMakeBorder(src,src,1,1,1,1,BORDER_CONSTANT);
	cv::Mat dst(src.size(),CV_8U,cv::Scalar(0));

	for (int i=1;i<src.rows-1;++i)
	{
		for (int j=1;j<src.cols-1;++j)
		{
			cv::Mat ROI(src,cv::Rect(j-1,i-1,3,3));
			double maxV=0,minV=0;
			cv::minMaxIdx(ROI,&minV,&maxV);
			//std::cout<<maxV<<"  "<<minV<<'\n';
			dst.at<uchar>(i,j)=static_cast<uchar>(maxV);
		}
	}
	return dst;
}

cv::Mat MinBlur( cv::Mat src )
{
	cv::copyMakeBorder(src,src,1,1,1,1,BORDER_CONSTANT);
	cv::Mat dst(src.size(),CV_8U,cv::Scalar(0));

	for (int i=1;i<src.rows-1;++i)
	{
		for (int j=1;j<src.cols-1;++j)
		{
			cv::Mat ROI(src,cv::Rect(j-1,i-1,3,3));
			double maxV=0,minV=0;
			cv::minMaxIdx(ROI,&minV,&maxV);
			//std::cout<<maxV<<"  "<<minV<<'\n';
			dst.at<uchar>(i,j)=static_cast<uchar>(minV);
		}
	}
	return dst;
}

cv::Mat MidBlur( cv::Mat src )
{
	cv::copyMakeBorder(src,src,1,1,1,1,BORDER_CONSTANT);
	cv::Mat dst(src.size(),CV_8U,cv::Scalar(0));

	for (int i=1;i<src.rows-1;++i)
	{
		for (int j=1;j<src.cols-1;++j)
		{
			cv::Mat ROI(src,cv::Rect(j-1,i-1,3,3));
			double maxV=0,minV=0;
			cv::minMaxIdx(ROI,&minV,&maxV);
			//std::cout<<maxV<<"  "<<minV<<'\n';
			dst.at<uchar>(i,j)=static_cast<uchar>((minV+maxV)/2);
		}
	}
	return dst;
}

