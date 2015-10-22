#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <algorithm>
#include "Result.h"
/**
	使用IDE版本:visual studio 2012

	totalNum:每组零件数量
	startValue:零件安装时间最小值
	endValue:零件安装时间最大值
	times:零件数组组数
	machinT:零件加工时间
	instalT:每组零件安装时间数组
	
	
	Calculate:计算times组零件数据
	Print:打印出数组
	FuncOne:函数f1
	FuncTwo:函数f2
	Sum:对指定数组求和*/

class Solver
{
public:
	Solver(void);
	~Solver(void);

	static Result<double> Calculate(const int totalNum=20,
		const int startValue=0,const int endValue=40,const int times=10,double machinT=20);
	static void Print(const std::vector<double>& vec);//输出数组
private:
	static double FuncOne(const std::vector<double>&instalT,double machinT=20);
	static double FuncTwo(const std::vector<double>&instalT,double machinT=20);
	static std::vector<std::vector<double>> RandomVecGenerate(const int totalNum=20,
		const int startValue=0,const int endValue=40,const int times=10);
	static double Sum(std::vector<double> const &vec);
};

