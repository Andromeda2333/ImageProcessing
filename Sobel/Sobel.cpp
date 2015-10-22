// Sobel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Enhance.h"
int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("image.tif");
	cv::cvtColor(image,image,CV_RGB2GRAY);
	double r[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
	double c[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
	cv::Mat sobelRow(3,3,CV_64FC1,r);
	cv::Mat sobelCol(3,3,CV_64FC1,c);
	/*std::cout<<sobelRow<<std::endl<<sobelCol<<std::endl;*/
	cv::Mat result=Enhance::Sobel(image,sobelRow,sobelCol);

	cv::imshow("Before",image);
	cv::imshow("Result",result);
	cv::imwrite("result.tif",result);
	cv::waitKey();
	return 0;
}

