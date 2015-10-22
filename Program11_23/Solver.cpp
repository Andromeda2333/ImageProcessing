#include "stdafx.h"
#include "Solver.h"

using namespace std;
Solver::Solver()
{
}

Solver::Solver(int nValue, int mValue)
{
	//由于计算机的表示机制增加一行一列
	this->mLengthValue = mValue+1;//初始化备用矩阵的"宽度",
	this->mWideValue = nValue+1;//初始化备用矩阵的"长度"

	//构造一个n*m的矩阵,所有元素初始值为1
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

//算法主体部分
//计数法和递归结合
int Solver::Merge(int n, int m)
{
	//如果函数的值在dataBase中存在则直接返回
	if (dataBase->at(n)->at(m)!=1)
	{
		return dataBase->at(n)->at(m);
	}
	if (n==1||m==0)
	{
		dataBase->at(n)->at(m) = m + 1;//对应f(n,m)的值存入dataBase
		return m + 1;
	}

	int tmpResult = 0;//局部结果
	if (n>m)
	{
		//n==m放在下述情况
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


//指定n,m的值查询结果
void Solver::Search()
{
	while (true)
	{
		cout << "***********************************" << endl;
		cout << "输入n和m的值已查询结果 (n<=" << mWideValue - 1 << ",m<=" << mLengthValue - 1
			<< " 当m=-1或者n=-1退出查询!!) " << endl;
		int n =0, m =0;
		cout << "输入n="; cin >> n;
		cout << "输入m="; cin >> m;
		if (n>=mWideValue||m>=mLengthValue)
		{
			cout << "n或者m的值越界!!" << endl;
			break;
		}
		if (n==-1||m==-1)
		{
			break;
		}

		cout << "当n=" << n << ",m=" << m << "时,结果为:";
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
