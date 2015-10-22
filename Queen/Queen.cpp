// Queen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

bool IsFine(const std::vector<int>& location,const int lineNum);
std::vector<int> LocateQueen(const int nQueen);

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> loc=LocateQueen(10);
	for each (int i in loc)
	{
		std::cout<<i<<'\n';
	}
	return 0;
}

bool IsFine( std::vector<int>& location,int lineNum)
{
	//判断当前局部的皇后是否满足约束条件
	for (int i=0;i<lineNum;++i)
	{
		if (location[i]==location[lineNum]||abs(location[i]-location[lineNum])==abs(i-lineNum))
		{
			return false;
		}
	}
	return true;
}

std::vector<int> LocateQueen( const int nQueen )
{
	std::vector<int> loc(nQueen,0);//存储皇后位置
	int k=0;

	while (k>=0)
	{
		//对第k行的皇后进行位置确定
		while (!IsFine(loc,k)&&loc[k]<nQueen)
		{
			loc[k]++;
		}

		
		if (loc[k]<nQueen)//判断第k行的最终位置时候在可行范围内
		{
			if (k==nQueen-1)//判断是否为最后一行
			{
				break;
			}
			k++;//继续下一行的位置确定
		}
		else
		{
			//如果第k行在可行范围内无法找到确切位置,则退回上一行,
			//并且将上一行位置往前递增一个

			loc[k]=0;
			--k;
			loc[k]+=1;
		}
	}
	return loc;
}

