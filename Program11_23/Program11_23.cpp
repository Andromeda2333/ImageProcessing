// Program11_23.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//#include "Solver.h"
#include <iostream>
#include "templateSolver.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int n = 0, m = 0;
	std::cout << "����n��ֵ:";
	std::cin >> n;
	std::cout << "����m��ֵ:";
	std::cin >> m;

	/*Solver s(n,m);*/
	templateSolver<double> s(n,m);//����ģ����,�м��double���Ի�����������������,int,long,float
	std::cout <<"��n="<<n<<",m="<<m<<"ʱ,���Ϊ:"<< s.GetResult() << std::endl<<std::endl;
	s.Search();
	return 0;
}

