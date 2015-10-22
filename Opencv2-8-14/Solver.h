#pragma once
#include<iostream>
#include<opencv2/core/core.hpp>
#include <opencv2/highgui//highgui.hpp>
#include <opencv2/imgproc//imgproc.hpp>
class Solver
{
public:
	Solver(void);
	~Solver(void);

	cv::Mat Equalize(const cv::Mat &image);
};

