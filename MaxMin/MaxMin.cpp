// MaxMin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Solver.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> iVec;
	Solver iVecMaxMin;
	int iVecMax(0),iVecMin=0;

	iVec.push_back(12);
	iVec.push_back(6);
	iVec.push_back(39);
	iVec.push_back(32);
	iVec.push_back(51);

	iVecMaxMin.OutPut(iVec);
	iVecMaxMin.MaxMin(iVec,0,iVec.size()-1,iVecMax,iVecMin);

	std::cout<<"the maximum of the iVec :"<<iVecMax<<std::endl;
	std::cout<<"the minimal of the iVec :"<<iVecMin<<std::endl;

	for (int i=1;i<=6;++i)
	{
		std::cout<<"*************************************"<<std::endl;
		std::vector<std::vector<int>> ans=iVecMaxMin.Slice(i);
		std::cout<<"index "<<i<<std::endl;
		for (int i=0;i<ans.size();++i)
		{
			iVecMaxMin.OutPut(ans[i]);
		}
	}



	return 0;
}

