#pragma once
#include <vector>
#include <iostream>

template<typename T>
class templateSolver
{
public:
	templateSolver();
	templateSolver(int nValue, int mValue);
	~templateSolver();
	T GetResult();//返回结果
	void Search();

protected:
	std::vector<std::vector<T>*> *dataBase;//存储f(n,m)的值对应的是
	int mLengthValue = 0;//dataBase长度
	int mWideValue = 0;//dataBase宽度

	T Merge(int n, int m);
};

template<typename T>
templateSolver<T>::~templateSolver()
{

}

template<typename T>
templateSolver<T>::templateSolver()
{

}

template<typename T>
T templateSolver<T>::Merge(int n, int m)
{

	{
		//如果函数的值在dataBase中存在则直接返回
		if (dataBase->at(n)->at(m) != 1)
		{
			return dataBase->at(n)->at(m);
		}
		if (n == 1 || m == 0)
		{
			dataBase->at(n)->at(m) = m + 1;//对应f(n,m)的值存入dataBase
			return m + 1;
		}

		T tmpResult = 0;//局部结果
		if (n > m)
		{
			//n==m放在下述情况
			T tmp = Merge(m, m);
			dataBase->at(n)->at(m) = tmp;
			return tmp;
		}
		for (int j = 0; j <= m / n; ++j)
		{
			tmpResult += Merge(n - 1, m - j*n);
		}
		dataBase->at(n)->at(m) = tmpResult;
		return tmpResult;
	}
}

template<typename T>
void templateSolver<T>::Search()
{

	{
		while (true)
		{
			std::cout << "***********************************" << std::endl;
			std::cout << "输入n和m的值已查询结果 (n<=" << mWideValue - 1 << ",m<=" << mLengthValue - 1
				<< " 当m=-1或者n=-1退出查询!!) " << std::endl;
			int n = 0, m = 0;
			std::cout << "输入n="; std::cin >> n;
			std::cout << "输入m="; std::cin >> m;
			if (n >= mWideValue || m >= mLengthValue)
			{
				std::cout << "n或者m的值越界!!" << std::endl;
				break;
			}
			if (n == -1 || m == -1)
			{
				break;
			}

			std::cout << "当n=" << n << ",m=" << m << "时,结果为:";
			if (dataBase->at(n)->at(m) != 1)
			{
				std::cout << dataBase->at(n)->at(m) << std::endl;;
			}
			else
			{
				std::cout << Merge(n, m) << std::endl;
			}
		}

	}

}

template<typename T>
T templateSolver<T>::GetResult()
{
	Merge(mWideValue - 1, mLengthValue - 1);
	return dataBase->at(mWideValue - 1)->at(mLengthValue - 1);
}

template<typename T>
templateSolver<T>::templateSolver(int nValue, int mValue)
{
	this->mLengthValue = mValue + 1;//初始化备用矩阵的"宽度",
	this->mWideValue = nValue + 1;//初始化备用矩阵的"长度"

	//构造一个n*m的矩阵,所有元素初始值为1
	this->dataBase = new std::vector<std::vector<T>*>();
	for (int i = 0; i < mWideValue; ++i)
	{
		dataBase->push_back(new std::vector<T>(mLengthValue, 1));
	}
}

