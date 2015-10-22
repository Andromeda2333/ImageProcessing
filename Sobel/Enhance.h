#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>
#include <iostream>
class Enhance
{
public:
	Enhance(void);
	~Enhance(void);

	static cv::Mat Sobel(cv::Mat& image,cv::Mat& sobelRow,cv::Mat& sobelCol);
};

