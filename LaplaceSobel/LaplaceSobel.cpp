// LaplaceSobel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "Filter.h"
int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("image.tif",CV_LOAD_IMAGE_GRAYSCALE);//原始图像
	cv::Mat imageLaplace;
	cv::Laplacian(image,imageLaplace,CV_8UC1,3);//拉普拉斯图像
	cv::Mat imageLaplace1=image-imageLaplace;//拉普拉斯图像和原图相加的图像

	/*Sobel处理*/
	cv::Mat imageSobel,gradx,grady;
	cv::Mat absGradx,absGrady;

	cv::Sobel(image,gradx,CV_16S,1,0,3);
	cv::Sobel(image,grady,CV_16S,0,1,3);

	cv::convertScaleAbs(gradx,absGradx);
	cv::convertScaleAbs(grady,absGrady);
	cv::addWeighted(absGradx,0.5,absGrady,0.5,0,imageSobel);

	/*对Sobel处理后的图像进行均值平滑处理*/
	cv::Mat imageAver;
	cv::blur(imageSobel,imageAver,cv::Size(3,3),cv::Point(-1,-1));

	cv::Mat imageLapSobel=imageLaplace1.mul(imageAver);
	cv::imshow("原始图像",image);
	cv::imshow("拉普拉斯图像",imageLaplace);
	cv::imshow("拉普拉斯+原图",imageLaplace1);
	cv::imshow("Sobel图像",imageSobel);
	cv::imshow("Sobel均值图像",imageAver);
	cv::imshow("lap乘sobel",imageLapSobel);

	cv::waitKey();
	return 0;
}

