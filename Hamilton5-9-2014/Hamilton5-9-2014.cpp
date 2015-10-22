// Hamilton5-9-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> Halmit(vector<vector<bool>> lMat,int n);

int _tmain(int argc, _TCHAR* argv[])
{
	int n=5;
	vector<vector<bool>> lMat(n,vector<bool>(n,false));
	lMat[0][1]=lMat[0][3]=true;
	lMat[1][0]=lMat[1][2]=lMat[1][3]=lMat[1][4]=true;
	lMat[2][1]=lMat[2][3]=lMat[2][4]=true;
	lMat[3][0]=lMat[3][2]=lMat[3][4]=lMat[3][1]=true;
	lMat[4][1]=lMat[4][2]=lMat[4][3]=true;
	//lMat[0][0]=lMat[1][1]=lMat[2][2]=lMat[3][3]=lMat[4][4]=true;
	
	vector<int> res=Halmit(lMat,n);
	for each (auto i in res)
	{
		cout<<i<<endl;
	}
	return 0;
}

vector<int> Halmit( vector<vector<bool>> lMat,int n )
{
	vector<bool> s(n,false);
	vector<int> loc(n,-1);
	int k=1;

	loc[0]=0;s[0]=true;//路线起始点
	while (k>=0)
	{
		loc[k]++;
		while (loc[k]<n)
		{
			if (!s[loc[k]]&&lMat[loc[k-1]][loc[k]])//当前点没有被选中且和局部路线最后一个点相连
			{
				break;
			}
			loc[k]++;
		}

		if (loc[k]<n&&k!=n-1)//k不是最后一个点
		{
			s[loc[k]]=true;
			k++;
		}
		else if (loc[k]<n&&k==n-1&&lMat[loc[0]][loc[k]])//k是最后一个点且和起点相连
		{
			break;
		}
		else
		{
			//对当前局部路线无法找到下一个点加入,无法形成新的局部解则退回当点k-1
			loc[k--]=-1;
			s[loc[k]]=false;
		}
	}
	return loc;
}

