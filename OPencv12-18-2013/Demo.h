#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

class Demo
{
public:
	Demo(void);
	~Demo(void);

	void ImReadAndShow()const;
	void Salt()const;
	void ColorReduce()const;
	void Sharpen(const cv::Mat &image,cv::Mat &result)const;
	void Add(cv::Mat &image,cv::Mat &fImage)const;
	void AddOther(cv::Mat &image,cv::Mat &fImage)const;
};

