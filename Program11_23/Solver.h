#pragma once
#include <vector>
#include <iostream>
class Solver
{
public:
	Solver();
	Solver(int nValue, int mValue);//Ϊ���û�����ô洢��,ʵ������ʱ����ʹ�˹��캯��,
									//��Ҫʹ��Ĭ�Ϲ��캯��
	~Solver();
	virtual int GetResult();//���ؽ��
	virtual void Search();

protected:
	std::vector<std::vector<int>*> *dataBase;//�洢f(n,m)��ֵ��Ӧ����
	int mLengthValue=0;//dataBase����
	int mWideValue=0;//dataBase���

	virtual int Merge(int n, int m);
};

