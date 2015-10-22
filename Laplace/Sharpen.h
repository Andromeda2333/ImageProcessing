#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>
class Sharpen
{
public:
	Sharpen(void);
	~Sharpen(void);

	static cv::Mat Laplace(cv::Mat& image,cv::Mat& filterMat);
	static cv::Mat LaplaceMore(cv::Mat& image,cv::Mat& filterMat);
private:
	static double LaplaceComput(cv::Mat& ROI,cv::Mat& filterMat);
	static std::pair<double,double> MaxMinValue(cv::Mat& image);
};

