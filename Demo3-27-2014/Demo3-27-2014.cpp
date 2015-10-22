// Demo3-27-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solver.h"
#include "Result.h"

int _tmain(int argc, _TCHAR* argv[])
{
	/**
	ÿ�������ĿΪ20
	�����װʱ������Ϊ[0,40]
	����Ϊ250
	����ӹ�ʱ��Ϊ20*/
	Result<double> res=Solver::Calculate(20,0,40,250,20);
	
	std::cout<<"f2/21�Ľ��Ϊ"<<std::endl;
	Solver::Print(res.GetVector());
	std::cout<<"��С��ֵΪ:"<<res.GetMinValue()<<std::endl;
	std::cout<<"����ֵΪ:"<<res.GetMaxValue()<<std::endl;
	system("pause");
	return 0;
}
