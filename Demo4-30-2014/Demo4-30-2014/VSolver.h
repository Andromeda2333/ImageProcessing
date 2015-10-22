#pragma once
#include <opencv2/core/core.hpp>
#include <random>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <iostream>
class CVSolver
{
public:
	CVSolver(void);
	~CVSolver(void);

	static double ComputeConst(cv::Mat& x,cv::Mat& Q,cv::Mat& b);
	static double ComputeVar(cv::Mat& x,cv::Mat& Q,cv::Mat& b);
	static double ComputeProj(cv::Mat& x,cv::Mat& Q,cv::Mat& b);
	static cv::Mat GetQ(int dim);
	static cv::Mat Getb(int dim);
private:
	static double f(cv::Mat& x,cv::Mat& Q,cv::Mat& b);
	static cv::Mat Getd(cv::Mat& x,cv::Mat& Q,cv::Mat& b);
	static bool IsNonegtive(cv::Mat& x);
	static cv::Mat GetPointAmj(cv::Mat& x,cv::Mat& Q,cv::Mat& b,double sigma=pow(10,-4),double beta=0.5);
	static cv::Mat GetProj(cv::Mat& x,cv::Mat& Q,cv::Mat& b,double s);
};

