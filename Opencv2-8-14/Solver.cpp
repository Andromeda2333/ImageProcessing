#include "stdafx.h"
#include "Solver.h"


Solver::Solver(void)
{
}


Solver::~Solver(void)
{
}

cv::Mat Solver::Equalize( const cv::Mat &image )
{
	cv::Mat result;
	cv::equalizeHist(image,result);
	return result;
}


