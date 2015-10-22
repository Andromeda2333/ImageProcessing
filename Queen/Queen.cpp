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
	//�жϵ�ǰ�ֲ��Ļʺ��Ƿ�����Լ������
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
	std::vector<int> loc(nQueen,0);//�洢�ʺ�λ��
	int k=0;

	while (k>=0)
	{
		//�Ե�k�еĻʺ����λ��ȷ��
		while (!IsFine(loc,k)&&loc[k]<nQueen)
		{
			loc[k]++;
		}

		
		if (loc[k]<nQueen)//�жϵ�k�е�����λ��ʱ���ڿ��з�Χ��
		{
			if (k==nQueen-1)//�ж��Ƿ�Ϊ���һ��
			{
				break;
			}
			k++;//������һ�е�λ��ȷ��
		}
		else
		{
			//�����k���ڿ��з�Χ���޷��ҵ�ȷ��λ��,���˻���һ��,
			//���ҽ���һ��λ����ǰ����һ��

			loc[k]=0;
			--k;
			loc[k]+=1;
		}
	}
	return loc;
}

