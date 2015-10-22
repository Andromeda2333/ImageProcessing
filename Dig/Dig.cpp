// Dig.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

void Print(const std::vector<int>& vec);
std::vector<int> Dcere(const std::vector<int>&vce,int season);
std::pair<int,int> MaxLoc(const std::vector<int>&vec);
std::vector<int> Add(const std::vector<int>&lhs,const std::vector<int>&rhs);

std::pair<int,std::vector<int>> Solve(const std::vector<int>&star,
	std::vector<std::vector<int>> tab);
int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::vector<int>> tab;

	int a[9]={0,-3,-5,-3,0,-2,-5,-2,0};
	tab.push_back(std::vector<int>(a,a+3));
	tab.push_back(std::vector<int>(a+3,a+6));
	tab.push_back(std::vector<int>(a+6,a+9));
	int b[3]={24,18,16};
	std::vector<int> star(b,b+3);

	std::pair<int,std::vector<int>> result=Solve(star,tab);
	std::cout<<result.first<<std::endl;
	Print(result.second);
	return 0;
}

void Print( const std::vector<int>& vec )
{
	for each (auto var in vec)
	{
		std::cout<<var<<'\t';
	}
	std::cout<<std::endl;
}

std::vector<int> Dcere( const std::vector<int>&vec,int season )
{
	std::vector<int> temp;
	std::vector<int> d;
	d.push_back(4);
	d.push_back(3);
	d.push_back(2);

	for (int i=0;i<vec.size();++i)
	{
		temp.push_back(vec[i]-season*d[i]);
	}

	return temp;
}

std::pair<int,std::vector<int>> Solve( const std::vector<int>&star,
	std::vector<std::vector<int>> tab)
{
	std::vector<int> temp=Dcere(star,0);
	std::pair<int,int> tempRes=MaxLoc(temp);
	std::vector<int> resTab;
	int res=tempRes.first;
	resTab.push_back(tempRes.second+1);
	for (int i=1;i<7;++i)
	{
		temp.clear();
		temp=Dcere(star,i);
		temp=Add(temp,tab.at(tempRes.second));

		tempRes=MaxLoc(temp);
		res+=tempRes.first;
		resTab.push_back(tempRes.second+1);
	}
	return std::pair<int,std::vector<int>>(res,resTab);
}

std::pair<int,int> MaxLoc( const std::vector<int>&vec )
{
	int maxV=-1;
	int loca=-1;
	for (int i=0;i<vec.size();++i)
	{
		if(vec[i]>maxV)
		{
			maxV=vec[i];
			loca=i;
		}
	}
	return std::pair<int,int>(maxV,loca);
}

std::vector<int> Add( const std::vector<int>&lhs,const std::vector<int>&rhs )
{
	std::vector<int> temp;
	for (int i=0;i<lhs.size();++i)
	{
		temp.push_back(lhs[i]+rhs[i]);
	}
	return temp;
}

