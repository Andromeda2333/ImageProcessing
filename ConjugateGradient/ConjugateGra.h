#pragma once
#include <opencv2/core/core.hpp>
#include <functional>
#include <iostream>
class ConjugateGra
{
public:
	ConjugateGra(cv::Mat inQ,cv::Mat inb);
	~ConjugateGra(void);

	cv::Mat operator ()(const cv::Mat x)const;
private:
	double Func(const cv::Mat x)const;
	cv::Mat Dfunc(const cv::Mat x)const;
	cv::Mat GetNextPoint(const cv::Mat x,const cv::Mat d)const;
	cv::Mat Compute(const cv::Mat x0)const;

	cv::Mat Q;
	cv::Mat b;
	cv::Mat A;
	std::function<double(cv::Mat)> f;
	std::function<cv::Mat(cv::Mat)> df;
};

