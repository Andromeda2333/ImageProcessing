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
	//�жϵ�ǰ��ɫ�Ƿ�����Ҫ��
	for (int i=0;i<k;++i)
	{
		if (linkMat[k][i]&&x[k]==x[i])//�жϵ�k�͵�i�Ƿ�����,���������ô���ǵ���ɫ�Ƿ���ͬ
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
		loc[k]++;//��ǰ�����ɫ��һ,��ѡ����һ��������ɫ

		//��ǰ�����ɫ�ڿ�ѡ��Χ������ѡ��ɫ������ͼ����ɫ����Ҫ�����������
		while (loc[k]<=m&&!IsFine(linkMat,loc,k))
		{
			loc[k]++;
		}
		if (loc[k]<=m)
		{
			if (k==n-1)//���һ������ɫ������˳�
			{
				break;
			}
			k++;
		}
		else
		{
			//��ǰ���޷���ɫ�ʼ����ҵ����н�,���˻ص�ǰһ����
			loc[k--]=0;
		}
	}
	return loc;
}

