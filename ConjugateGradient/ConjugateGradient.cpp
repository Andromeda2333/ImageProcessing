// ConjugateGradient.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConjugateGra.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	double a[9]={2 ,-1 ,3,4 ,2 ,5,2 ,1, 2};
	double a2[3]={1,4,5};
	double a3[3]={13,32,45};
	cv::Mat Q(3,3,CV_64F,a);
	cv::Mat b(3,1,CV_64F,a2);
	cv::Mat x(3,1,CV_64F,a3);

	std::cout<<Q<<std::endl;
	ConjugateGra f(Q,b);
	std::cout<<f(x)<<std::endl;
	return 0;
}

