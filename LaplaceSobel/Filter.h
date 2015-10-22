#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
class Filter
{
public:
	Filter(void);
	~Filter(void);

	static cv::Mat Laplace(cv::Mat& image);
	static cv::Mat Sobel( cv::Mat&image);
};

