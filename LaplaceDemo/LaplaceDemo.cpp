// LaplaceDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
using namespace cv;
int _tmain(int argc, _TCHAR* argv[])
{
	double m[3][3]={1,2,3,4,5,6,7,8,9};
	cv::Mat M(3,3,CV_64FC1,m);
	std::cout<<M<<std::endl;


	double r[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
	double c[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
	cv::Mat sobelRow(3,3,CV_64FC1,r);
	cv::Mat sobelCol(3,3,CV_64FC1,c);
	std::cout<<sobelRow<<std::endl<<sobelCol<<std::endl;

	M=M.mul(sobelRow);
	std::cout<<M<<std::endl;
	cv::Scalar s=cv::sum(M);
	//M.convertTo(M,CV_8S);
	std::cout<<s<<std::endl;
	std::cout<<s[0]<<std::endl;
	std::cout<<s<<std::endl;
	cv::waitKey();
	return 0;
}

