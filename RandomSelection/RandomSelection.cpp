// RandomSelection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
//随机选择算法

template <class T>
T SelectRandom(vector<T> src,const int const low,const int high,const int k);
template <class T>
T Select(vector<T> &src,const int const low,const int high,const int k);
template <class T>
T Split(vector<T> &src,const int low,const int high);
int _tmain(int argc, _TCHAR* argv[])
{
	srand(unsigned(time(0)));
	vector<int> vec;
	for (int i=0;i<10000;++i)
	{
		vec.push_back(rand()%10000);
	}

	cout<<SelectRandom<int>(vec,0,vec.size()-1,5090);
	return 0;
}


template <class T>
T SelectRandom( vector<T> src,const int const low,const int high,const int k )
{
	srand(unsigned(time(0)));
	return Select<T>(src,low,high,k);
}

template <class T>
T Select( vector<T> &src,const int const low,const int high,const int k )
{
	if (high==low)
	{
		return src[low];
	}

	swap(src[low],src[rand()%(high-low+1)]);
	int i=Split<T>(src,low,high);

	//判断k在i的左侧还是右侧
	if (k==i-low+1)
	{
		return src[i];
	}
	else if (k<i-low+1)
	{
		return Select<T>(src,low,i-1,k);
	}
	else
	{
		return Select<T>(src,i+1,high,k-(i-low+1));
	}
}

/*
	把src中从low到high部分以i分为两部分
	low->i-1部分小于等于src[i],
	i+1->high部分大于等于src[i]
	**/
template <class T>
T Split( vector<T>&src,const int low,const int high )
{
	T tag=src[low];
	int i=low;

	for (int k=low+1;k<=high;++k)
	{
		if (src[k]<=tag)
		{
			++i;
			if (k!=i)
			{
				swap(src[i],src[k]);
			}
		}
	}
	swap(src[i],src[low]);
	return i;
}
