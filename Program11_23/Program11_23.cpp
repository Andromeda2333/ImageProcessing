// Program11_23.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include "Solver.h"
#include <iostream>
#include "templateSolver.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0, m = 0;
	std::cout << "输入n的值:";
	std::cin >> n;
	std::cout << "输入m的值:";
	std::cin >> m;

	/*Solver s(n,m);*/
	templateSolver<double> s(n,m);//调用模板类,中间的double可以换成其他数据类型如,int,long,float
	std::cout <<"当n="<<n<<",m="<<m<<"时,结果为:"<< s.GetResult() << std::endl<<std::endl;
	s.Search();
	return 0;
}

