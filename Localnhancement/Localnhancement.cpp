// Localnhancement.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
#include <math.h>

int E=5;
double k0=0.4;
double k1=0.0001;
double k2=0.4;

std::pair<double,double> AveAndVar(const cv::Mat& image);
cv::Mat LocalMat(int i,int j,const cv::Mat& image);
uchar Enhance(const cv::Mat& image,const std::pair<double,double>& gAveVar,const std::pair<double,double>& lAveVar,
			  const std::pair<int,int>& locat);
int _tmain(int argc, _TCHAR* argv[])
{
	/*读取并将图像转化为灰度图像*/
	cv::Mat image=cv::imread("image.tif");
	cv::cvtColor(image,image,cv::COLOR_RGB2GRAY);
	cv::Mat result(image.size(),image.type());
	std::pair<double,double> gAveVar=AveAndVar(image);

	for (size_t i=1;i<image.rows-1;++i)
	{
		for (size_t j=1;j<image.cols-1;++j)
		{
			uchar m[3][3]={{image.at<uchar>(i-1,j-1),image.at<uchar>(i-1,j),image.at<uchar>(i-1,j+1)},
			{image.at<uchar>(i,j-1),image.at<uchar>(i,j),image.at<uchar>(i,j+1)},
			{image.at<uchar>(i+1,j-1),image.at<uchar>(i+1,j),image.at<uchar>(i+1,j+1)}};
			cv::Mat localM=cv::Mat(3,3,CV_8UC1,m);
			
			std::pair<double,double> lAveVar=AveAndVar(localM);
			result.at<uchar>(i,j)=Enhance(image,gAveVar,lAveVar,std::pair<int,int>(i,j));
		}
	}
	result.row(0).setTo(cv::Scalar(0));
	result.row(result.rows-1).setTo(cv::Scalar(0));
	result.col(0).setTo(cv::Scalar(0));
	result.col(result.cols-1).setTo(cv::Scalar(0));

	cv::imshow("Berfore",image);
	cv::imshow("EnhanceImage",result);

	cv::waitKey();
	return 0;
}

std::pair<double,double> AveAndVar( const cv::Mat& image )
{
	/*获取指定区域内的平均值和方差*/
	int wide=image.size().width;
	int heigh=image.size().height;
	int n=wide*heigh;
	double average=0;
	double variance=0;
	
	std::vector<int> singNum(256,0);

	uchar* ptr=image.data;

	for (size_t i=0;i<n;++i)
	{
		singNum.at(*ptr)++;
		++ptr;
	}

	for (size_t i=0;i<256;++i)
	{
		average+=singNum.at(i)*i;
	}
	average/=n;

	for (size_t i=0;i<256;++i)
	{
		variance+=std::pow(i-average,2)*singNum.at(i);
	}
	variance/=n;
	return std::pair<double,double>(average,variance);
}

cv::Mat LocalMat(int i,int j,const cv::Mat& image)
{
	/*获取像素(i,j)的领域:3*3*/
	//uchar m[3][3]={{image.at<uchar>(i-1,j-1),image.at<uchar>(i-1,j),image.at<uchar>(i-1,j+1)},
	//			{image.at<uchar>(i,j-1),image.at<uchar>(i,j),image.at<uchar>(i,j+1)},
	//			{image.at<uchar>(i+1,j-1),image.at<uchar>(i+1,j),image.at<uchar>(i+1,j+1)}};
	//localM=cv::Mat(3,3,CV_8UC1,m);

	return cv::Mat(image,cv::Rect(i,j,3,3));
}

uchar Enhance(const cv::Mat& image,const std::pair<double,double>& gAveVar,const std::pair<double,double>& lAveVar,const std::pair<int,int>& locat)
{
	/*对坐标为locat的像素进行增强*/

	//如果满足条件
	if ((lAveVar.first<=k0*gAveVar.first)&&(lAveVar.second<=k2*gAveVar.second)
		&&(lAveVar.second>=k1*gAveVar.second))
	{
		/*std::cout<<1<<std::endl;*/
		return static_cast<uchar>(E*image.at<uchar>(locat.first,locat.second));
	}

	//如果不满足
	return image.at<uchar>(locat.first,locat.second);
}

