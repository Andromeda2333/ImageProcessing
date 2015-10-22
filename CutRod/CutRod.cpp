// CutRod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void MaxProfit(const vector<int> &profit,vector<int> &maxPro,
			   vector<int> &divPoint );
int MaxProfit1(const vector<int> &profit,int index);
void OutSoulution( vector<int> &MaxPro,vector<int>&divPoint,int index  );

int _tmain(int argc, _TCHAR* argv[])
{
	int p[11]={0,1,5,8,9,10,17,17,20,24,30};
	vector<int> profit(p,p+11);
	vector<int> maxPro(profit);
	int p1[11]={0,1,2,3,4,5,6,7,8,9,10};
	vector<int> divPoint(p1,p1+11);
	MaxProfit(profit,maxPro,divPoint);

	for(int i=1;i<profit.size();++i)
	{
		OutSoulution(maxPro,divPoint,i);
	}	
	cout<<MaxProfit1(profit,23)<<endl;
	return 0;
}

void MaxProfit( const vector<int> &profit,vector<int> &maxPro,
			   vector<int> &divPoint )
{
	int n=profit.size();
	
	for(int i=1;i<n;++i)
	{
		int temp=maxPro.at(i);

		for(int j=1;j<i;++j)
		{
			if(temp<profit.at(j)+maxPro.at(i-j))
			{
				temp=profit.at(j)+maxPro.at(i-j);
				divPoint.at(i)=j;
			}
		}
		maxPro.at(i)=temp;
	}

}

int MaxProfit1( const vector<int> &profit,int length )
{
	//vector<int> r(length+1,0);
	vector<int> bestPrice(profit);
	if (length>profit.size()-1)
	{
		for (int i=0;i<length+2-profit.size();++i)
		{
			bestPrice.push_back(0);
		}
	}

	vector<int> tagCut(length+1,0);
	cout<<"the max price of "<<length<<" :"<<endl;
	for(int i=1;i<length+1;++i){
		int temp=bestPrice.at(i);
		for (int j=0;j<=i;++j)
		{
			if (temp<bestPrice[j]+bestPrice[i-j])
			{
				temp=bestPrice[j]+bestPrice[i-j];
				tagCut[i]=j;
			}
		}
		bestPrice[i]=temp;
	}
	return bestPrice[length];
}


void OutSoulution( vector<int> &MaxPro,vector<int>&divPoint,int index )
{
	cout<<"the max profit of "<<index<<" is : "<<'\n';
	cout<<MaxPro.at(index)<<endl;
	cout<<"the solution of division :"<<'\n';

	while(index>0){
		if (divPoint[index]==0)
		{
			cout<<divPoint.at(index)<<'\t';
			break;
		}
		cout<<divPoint.at(index)<<'\t';
		index=index-divPoint.at(index);
	}

	cout<<endl<<"************************"<<endl;

}

