// MyFFT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <complex>
#include <math.h>
#include <algorithm>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Solver.h"
int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("image.jpg");
	cv::cvtColor(image,image,CV_RGB2BGRA);

	cv::Mat padded;                            //将输入图像延扩到最佳的尺寸
	int m = cv::getOptimalDFTSize( image.rows );
	int n = cv::getOptimalDFTSize( image.cols ); // 在边缘添加0
	cv::copyMakeBorder(image, padded, 0, m - image.rows, 0, n - image.cols, cv::BORDER_CONSTANT,cv::Scalar::all(0));

	cv::imshow("原图",image);
	cv::Mat res=Solver::Fft2(padded);
	cv::imshow("处理图",res);
	cv::waitKey();
	return 0;
}



