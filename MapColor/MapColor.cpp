// MapColor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;
bool IsFine(vector<vector<bool>> linkMat,vector<int> x,int k);
vector<int> Coloring(vector<vector<bool>>linkMat,int n,int m);

int _tmain(int argc, _TCHAR* argv[])
{
	int n=5;
	vector<vector<bool>> linkMat(n,vector<bool>(n,false));
	linkMat[0][1]=linkMat[0][2]=true;
	linkMat[1][0]=linkMat[1][2]=linkMat[1][3]=linkMat[1][4]=true;
	linkMat[2][0]=linkMat[2][1]=linkMat[2][4]=true;
	linkMat[3][1]=linkMat[3][4]=true;
	linkMat[4][1]=linkMat[4][2]=linkMat[4][3]=true;
	vector<int> res=Coloring(linkMat,n,3);
	for each (int i in res)
	{
		cout<<i<<'\n';
	}
	return 0;
}

bool IsFine( vector<vector<bool>> linkMat,vector<int> x,int k )
{
	//判断当前着色是否满足要求
	for (int i=0;i<k;++i)
	{
		if (linkMat[k][i]&&x[k]==x[i])//判断点k和点i是否相连,如果相连那么他们的颜色是否相同
		{
			return false;
		}
	}
	return true;
}

vector<int> Coloring( vector<vector<bool>>linkMat,int n,int m )
{
	vector<int> loc(n,0);
	int k=0;
	while (true)
	{
		loc[k]++;//当前点的颜色加一,即选择下一个可行颜色

		//当前点的颜色在可选范围类且所选颜色不满足图的着色问题要求则继续迭代
		while (loc[k]<=m&&!IsFine(linkMat,loc,k))
		{
			loc[k]++;
		}
		if (loc[k]<=m)
		{
			if (k==n-1)//最后一个点着色完毕则退出
			{
				break;
			}
			k++;
		}
		else
		{
			//当前点无法再色彩集中找到可行解,则退回到前一个点
			loc[k--]=0;
		}
	}
	return loc;
}

