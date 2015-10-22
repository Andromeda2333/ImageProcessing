// RadixSortList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int GetNum(int num,int i);
void RadixSort(vector<int> &iVec);



int _tmain(int argc, _TCHAR* argv[])

{
	int a[8]={136,48,71,66,32,783,163};
	vector<int> iVec(a,a+8);
	RadixSort(iVec);
	
	for each (auto i in iVec)
	{
		cout<<i<<'\t';
	}
	return 0;
}

int GetNum( int num,int i )
{
	int temp=num/pow(10,i-1);
	return temp%10;
}

void RadixSort( vector<int>& iVec)
{
	vector<vector<int>> subVec(10,vector<int>());
	int y=10;
	int index=1;
	while(y)
	{
		for(int i=0;i<iVec.size();++i)
		{
			int j=GetNum(iVec.at(i),index);
			subVec[j].push_back(iVec.at(i));
		}
		iVec.clear();
		for(int j=0;j<10;++j)
		{
			for(int i=0;i<subVec[j].size();++i)
			{
				iVec.push_back(subVec[j].at(i));
			}
			subVec.at(j).clear();
		}
		
		//y--;
		y=iVec.at(0)/pow(10,index);
		for(int i=1;i<iVec.size();++i)
		{
		if(iVec.at(i)/pow(10,index)>y)
		y=iVec.at(i)/pow(10,index);
		}
		index++;
	}
}

