// Majority5_25_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <time.h>
#include <math.h>
#include <algorithm>

using namespace std;
bool Majority(vector<int> const &vec);
double MajorityMonte(vector<int> const &vec,const double error);

int _tmain(int argc, _TCHAR* argv[])
{
	int a[55]={1,23,1,32,12,3,1,6,5,1,3,21,3,2,1,2,1,1,1,1,1,
		1,1,11,1,1,1,1,1,11,1,1,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1,11,1,1,1,1,1};
	vector<int> vec(a,a+55);
	//srand(100);
	//generate(vec.begin(),vec.end(),[]()
	//{
	//	return rand()%4;
	//});

	for each (int i in vec)
	{
		cout<<i<<'\t';
	}

	cout<<'\n'<<boolalpha<<Majority(vec)<<endl;
	cout<<MajorityMonte(vec,0.000000000000004)<<endl;
	cout<<log(16)/log(2)<<endl;
	return 0;
}

bool Majority( vector<int> const &vec )
{
	srand(unsigned(time(0)));
	int n=vec.size();
	int k=rand()%n;

	int num=0;
	for (int i=0;i<n;++i)
	{
		if (vec[i]==vec[k])
		{
			++num;
		}
	}
	if (num>=n/2)
	{
		return true;
	}
	return false;
}

double MajorityMonte( vector<int> const &vec,const double error )
{
	int m=log(1/error)/log(2);
	srand(unsigned(time(0)));
	int n=vec.size();
	int k=0;
	int num=0;
	double tag=0;

	for (int j=0;j<m;++j)
	{
		num=0;
		k=rand()%n;
		for (int i=0;i<n;++i)
		{
			if (vec[i]==vec[k])
			{
				++num;
			}
		}
		if (num<n/2)
		{
			tag++;
		}
	}
	return (double)(tag/m);//·µ»Ø´íÎó±ÈÂÊ
}

