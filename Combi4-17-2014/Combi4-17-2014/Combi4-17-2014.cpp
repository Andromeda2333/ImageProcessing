// Combi4-17-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>

long Combi(int nRow,int r);
std::vector<std::vector<long>> Product(int size);
void Print(std::vector<long>& vec);
void PrintTrangle(std::vector<std::vector<long>>&db);

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::vector<long>> db=Product(10);
	std::for_each(db.begin(),db.end(),Print);
	PrintTrangle(db);
	return 0;
}

long Combi( int nRow,int r )
{//�����ƶ����е�����
	int temp(1);

	for (int i=1;i<=r;++i)
	{
		temp=temp*(nRow-i+1)/i;
	}
	return temp;
}

std::vector<std::vector<long>> Product( int size )
{//���������������
	std::vector<std::vector<long>> db;

	for (int i=0;i<=size;++i)
	{
		int tag=0;
		std::vector<long> temp(i+1,0);
		std::generate(temp.begin(),temp.end(),[&tag,i]()
		{
			return Combi(i,tag++);
		});
		db.push_back(temp);
	}

	return db;
}

void Print( std::vector<long>& vec )
{//�����������
	std::for_each(vec.begin(),vec.end(),[](long i)
	{
		std::cout<<i<<" ";
	});
	std::cout<<std::endl;
}

void PrintTrangle( std::vector<std::vector<long>>&db )
{//������תΪ���������ε���ʽ���
	int n=2*db[db.size()-1].size()-1;
	int tag=0;
	for (int r=0;r<db.size();++r)
	{
		tag=db.size()-r-1;
		for (int i=0,j=0;i<n,j<db[r].size();)
		{
			if (i<tag)
			{
				std::cout<<"  ";
				++i;
				continue;
			}
			std::cout<<db[r].at(j++)<<"  ";
			i+=2;
		}
		std::cout<<std::endl;
	}
}

