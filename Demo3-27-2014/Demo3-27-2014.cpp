// Demo3-27-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solver.h"
#include "Result.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/**
	每组零件数目为20
	零件安装时间区间为[0,40]
	组数为250
	零件加工时间为20*/
	Result<double> res=Solver::Calculate(20,0,40,250,20);
	
	std::cout<<"f2/21的结果为"<<std::endl;
	Solver::Print(res.GetVector());
	std::cout<<"最小比值为:"<<res.GetMinValue()<<std::endl;
	std::cout<<"最大比值为:"<<res.GetMaxValue()<<std::endl;
	system("pause");
	return 0;
}
