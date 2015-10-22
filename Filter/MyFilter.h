#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
class MyFilter
{
public:
	MyFilter(void);
	~MyFilter(void);
	static cv::Mat MidFilter(const cv::Mat& image,const cv::Mat& modeMat);
	static cv::Mat AverFilter(const cv::Mat& image,const cv::Mat& modeMat);
private:
	static uchar MideValue(const cv::Mat& ROIImage);
	static uchar Average(const cv::Mat& ROIImage,const cv::Mat& modeMat);
};

