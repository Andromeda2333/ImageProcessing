// Demo4-30-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Solver.h"
#include "VSolver.h"
int _tmain(int argc, _TCHAR* argv[])
{

	cv::Mat Q=CVSolver::GetQ(20);
	cv::Mat b=CVSolver::Getb(20);
	//cv::Mat x=CVSolver::Getb(3);

	std::srand((unsigned)time(0));
	cv::Mat x(20,1,CV_64F);
	for (int i=0;i<20;++i)
	{
		x.at<double>(i,0)=std::rand()%10;
	}
	//std::cout<<Q<<'\n'<<b<<'\n';
	//CVSolver::ComputeVar(x,Q,b);
	CVSolver::ComputeProj(x,Q,b);

	//double a[12]={14,54,45,646,54,8,48,97,49,84,984,84};
	//std::vector<double> vec(a,a+12);
	//cv::Mat test(3,4,CV_64F,vec.data());
	//std::cout<<test<<std::endl;
	return 0;
}

