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
	T GetResult();//���ؽ��
	void Search();

protected:
	std::vector<std::vector<T>*> *dataBase;//�洢f(n,m)��ֵ��Ӧ����
	int mLengthValue = 0;//dataBase����
	int mWideValue = 0;//dataBase���

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
		//���������ֵ��dataBase�д�����ֱ�ӷ���
		if (dataBase->at(n)->at(m) != 1)
		{
			return dataBase->at(n)->at(m);
		}
		if (n == 1 || m == 0)
		{
			dataBase->at(n)->at(m) = m + 1;//��Ӧf(n,m)��ֵ����dataBase
			return m + 1;
		}

		T tmpResult = 0;//�ֲ����
		if (n > m)
		{
			//n==m�����������
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
			std::cout << "����n��m��ֵ�Ѳ�ѯ��� (n<=" << mWideValue - 1 << ",m<=" << mLengthValue - 1
				<< " ��m=-1����n=-1�˳���ѯ!!) " << std::endl;
			int n = 0, m = 0;
			std::cout << "����n="; std::cin >> n;
			std::cout << "����m="; std::cin >> m;
			if (n >= mWideValue || m >= mLengthValue)
			{
				std::cout << "n����m��ֵԽ��!!" << std::endl;
				break;
			}
			if (n == -1 || m == -1)
			{
				break;
			}

			std::cout << "��n=" << n << ",m=" << m << "ʱ,���Ϊ:";
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
	this->mLengthValue = mValue + 1;//��ʼ�����þ����"���",
	this->mWideValue = nValue + 1;//��ʼ�����þ����"����"

	//����һ��n*m�ľ���,����Ԫ�س�ʼֵΪ1
	this->dataBase = new std::vector<std::vector<T>*>();
	for (int i = 0; i < mWideValue; ++i)
	{
		dataBase->push_back(new std::vector<T>(mLengthValue, 1));
	}
}

