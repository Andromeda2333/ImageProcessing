// RadixSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <math.h>
#include <iostream>

std::vector<int> Sort(const std::vector<int>&vec);
int CetSigNum(int value,int index);
void Print(std::vector<int> const &vec);
int _tmain(int argc, _TCHAR* argv[])
{
	int a[15]={781,48,916,9162,3716,789,415,735,216,321,639,186,718,36};
	std::vector<int> vec(a,a+15);
	std::vector<int> res=Sort(vec);
	Print(vec);
	Print(res);
	return 0;
}

std::vector<int> Sort( const std::vector<int>&vec )
{
	std::vector<std::vector<int>> table(10,std::vector<int>());
	std::vector<int> temp(vec);
	for (int i=1;i<=5;++i)
	{
		for (int k=0;k<10;++k)
		{
			table.at(k).clear();
		}
		for (size_t j=0;j<vec.size();++j)
		{
			table.at(CetSigNum(temp.at(j),i)).push_back(temp.at(j));
		}

		temp.clear();
		for (int l=0;l<10;++l)
		{
			for (size_t k=0;k<table.at(l).size();++k)
			{
				temp.push_back(table.at(l).at(k));
			}
		}
	}
	return temp;
}

int CetSigNum( int value,int index )
{
	int temp=value/int(pow(10,index-1));
	return temp%10;
}

void Print( std::vector<int> const &vec )
{
	for (size_t i=0;i<vec.size();++i)
	{
		std::cout<<vec.at(i)<<'\t';
	}
	std::cout<<'\n';
}

