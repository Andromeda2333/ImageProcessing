#pragma once
#include <vector>
#include <iostream>
class Solver
{
public:
	Solver();
	Solver(int nValue, int mValue);//为简洁没有设置存储器,实例化的时候请使此构造函数,
									//不要使用默认构造函数
	~Solver();
	virtual int GetResult();//返回结果
	virtual void Search();

protected:
	std::vector<std::vector<int>*> *dataBase;//存储f(n,m)的值对应的是
	int mLengthValue=0;//dataBase长度
	int mWideValue=0;//dataBase宽度

	virtual int Merge(int n, int m);
};

