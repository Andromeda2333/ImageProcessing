// newTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	vector<int>ve(10, 1);
	for_each(ve.begin(), ve.end(), [](int value){cout << value << endl; });
	int value = 4;

	//lambda表达式输出数组
	generate(ve.begin(), ve.end(), [&]{value *= 2; return value; });
	for (auto& i:ve)
	{
		cout << i << endl;
	}
	int tag = 500;

	int countNum = count_if(ve.cbegin(), ve.cend(), [&](int i){return i > tag; });
	cout << "number in ve:" << countNum << endl;
	system("pause");
	return 0;
}
