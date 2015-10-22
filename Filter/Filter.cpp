// Filter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyFilter.h"
#include <sstream>

int _tmain(int argc, _TCHAR* argv[])
{
	/*1.对图片进行均值滤波和中值滤波*/
	/*
	cv::Mat image=cv::imread("image.tif");
	cv::cvtColor(image,image,CV_RGB2GRAY);
	cv::Mat modeMat(3,3,CV_8UC1,cv::Scalar(1));
	cv::Mat resultMid=MyFilter::MidFilter(image,modeMat);
	cv::Mat resultAve=MyFilter::AverFilter(image,modeMat);
	cv::imshow("BeforeFilter",image);
	cv::imshow("MidFilter",resultMid);
	cv::imshow("AverageFilter",resultAve);
	cv::waitKey();
	*/

	/*以不同大小的掩膜对同一图片进行均值滤波*/
	
	cv::Mat image=cv::imread("image1.tif");
	cv::cvtColor(image,image,CV_RGB2GRAY);
	std::vector<cv::Mat> vec;
	std::vector<std::string> strVec;
	std::string str;
	for (int i=3;i<16;i+=4)
	{
		std::ostringstream strOut;
		cv::Mat modeMat(i,i,CV_8UC1,cv::Scalar(1));
		cv::Mat resultAve=MyFilter::AverFilter(image,modeMat);
		vec.push_back(resultAve);
		strOut<<i;
		str=strOut.str()+std::string("x")+strOut.str()+std::string(".jpg");
		strOut.clear();
		strVec.push_back(str);
	}
	
	cv::imshow("BeforeFilter",image);
	for (int i=0;i<vec.size();++i)
	{
		cv::imwrite(strVec.at(i),vec.at(i));
	}
	cv::waitKey();
	
	return 0;
}

