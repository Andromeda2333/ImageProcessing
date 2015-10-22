#include "stdafx.h"
#include "Solver.h"

using namespace std;
Solver::Solver()
{
}

Solver::Solver(int nValue, int mValue)
{
	//���ڼ�����ı�ʾ��������һ��һ��
	this->mLengthValue = mValue+1;//��ʼ�����þ����"���",
	this->mWideValue = nValue+1;//��ʼ�����þ����"����"

	//����һ��n*m�ľ���,����Ԫ�س�ʼֵΪ1
	this->dataBase = new vector<vector<int>*>();
	for (int i = 0; i < mWideValue;++i)
	{
		dataBase->push_back(new vector<int>(mLengthValue,1));
	}
}


Solver::~Solver()
{
}

int Solver::GetResult()
{
	Merge(mWideValue-1,mLengthValue-1);
	return dataBase->at(mWideValue-1)->at(mLengthValue-1);
}

//�㷨���岿��
//�������͵ݹ���
int Solver::Merge(int n, int m)
{
	//���������ֵ��dataBase�д�����ֱ�ӷ���
	if (dataBase->at(n)->at(m)!=1)
	{
		return dataBase->at(n)->at(m);
	}
	if (n==1||m==0)
	{
		dataBase->at(n)->at(m) = m + 1;//��Ӧf(n,m)��ֵ����dataBase
		return m + 1;
	}

	int tmpResult = 0;//�ֲ����
	if (n>m)
	{
		//n==m�����������
		int tmp = Merge(m, m);
		dataBase->at(n)->at(m) =tmp;
		return tmp;
	}
	for (int j = 0; j <= m / n;++j)
	{
		tmpResult += Merge(n - 1, m - j*n);
	}
	dataBase->at(n)->at(m) = tmpResult;
	return tmpResult;
}


//ָ��n,m��ֵ��ѯ���
void Solver::Search()
{
	while (true)
	{
		cout << "***********************************" << endl;
		cout << "����n��m��ֵ�Ѳ�ѯ��� (n<=" << mWideValue - 1 << ",m<=" << mLengthValue - 1
			<< " ��m=-1����n=-1�˳���ѯ!!) " << endl;
		int n =0, m =0;
		cout << "����n="; cin >> n;
		cout << "����m="; cin >> m;
		if (n>=mWideValue||m>=mLengthValue)
		{
			cout << "n����m��ֵԽ��!!" << endl;
			break;
		}
		if (n==-1||m==-1)
		{
			break;
		}

		cout << "��n=" << n << ",m=" << m << "ʱ,���Ϊ:";
		if (dataBase->at(n)->at(m) != 1)
		{
			cout << dataBase->at(n)->at(m) << endl;;
		}
		else
		{
			cout << Merge(n, m) << endl;
		}
	}
	
}
