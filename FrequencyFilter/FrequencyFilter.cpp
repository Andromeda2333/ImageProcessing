// FrequencyFilter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("image1.tif",CV_LOAD_IMAGE_GRAYSCALE);

	//cv::Mat padded;
	//int rValue=cv::getOptimalDFTSize(image.rows);
	//int cValue=cv::getOptimalDFTSize(image.cols);
	//cv::copyMakeBorder(image,padded,0,rValue-image.rows,0,cValue-image.cols,
	//	cv::BORDER_CONSTANT,cv::Scalar::all(0));

	//cv::Mat planes[]={cv::Mat_<float>(padded),cv::Mat::zeros(padded.size(),CV_32F)};
	//cv::Mat comple;
	//cv::merge(planes,2,comple);
	//cv::dft(comple,comple);
	//cv::split(comple,planes);
	//
	//cv::Mat mark(rValue,cValue,CV_32F,cv::Scalar(1));
	//mark.at<float>(rValue/2,cValue/2)=0;
	//planes[0]=planes[0].mul(mark);
	//planes[1]=planes[1].mul(mark);
	//cv::merge(planes,2,comple);
	//cv::idft(comple,comple);
	//cv::split(comple,planes);
	//cv::magnitude(planes[0],planes[1],planes[0]);
	//cv::Mat res(planes[0]);

	//res+=cv::Scalar::all(1);
	//cv::log(res,res);
	//
	//double maxV,minV;
	//cv::minMaxIdx(res,&minV,&maxV);
	//res=res/maxV*255;

	//res.convertTo(res,CV_8UC1);
	//cv::imshow("原图",image);
	//cv::imshow("处理图",res);
	//cv::waitKey();
	cv::Mat dst;
	cv::blur(image,dst,cv::Size(3,3),cv::Point(-1,-1));
	cv::imshow("原图",image);
	cv::imshow("归一化图",dst);

	cv::Mat dst1;
	cv::GaussianBlur(image,dst1,cv::Size(5,5),0,0);
	cv::imshow("高斯滤波图",dst1);

	cv::waitKey();
	return 0;
}

