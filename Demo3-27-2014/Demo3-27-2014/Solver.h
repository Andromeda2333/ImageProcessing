#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <math.h>
#include <algorithm>
#include "Result.h"
/**
	ʹ��IDE�汾:visual studio 2012

	totalNum:ÿ���������
	startValue:�����װʱ����Сֵ
	endValue:�����װʱ�����ֵ
	times:�����������
	machinT:����ӹ�ʱ��
	instalT:ÿ�������װʱ������
	
	
	Calculate:����times���������
	Print:��ӡ������
	FuncOne:����f1
	FuncTwo:����f2
	Sum:��ָ���������*/

class Solver
{
public:
	Solver(void);
	~Solver(void);

	static Result<double> Calculate(const int totalNum=20,
		const int startValue=0,const int endValue=40,const int times=10,double machinT=20);
	static void Print(const std::vector<double>& vec);//�������
private:
	static double FuncOne(const std::vector<double>&instalT,double machinT=20);
	static double FuncTwo(const std::vector<double>&instalT,double machinT=20);
	static std::vector<std::vector<double>> RandomVecGenerate(const int totalNum=20,
		const int startValue=0,const int endValue=40,const int times=10);
	static double Sum(std::vector<double> const &vec);
};

