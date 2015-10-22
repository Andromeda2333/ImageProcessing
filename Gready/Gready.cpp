// Gready.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

template<class T>
std::vector<T> RecursiveActivitySelector(const std::vector<T>& startT,const std::vector<T>& finishT,size_t k);
template<class T>
std::vector<T> Add(const std::vector<T>& lhs,const std::vector<T>& rhs);
template<class T>
void Print(const std::vector<T>& vecIn);
template<class T>
std::vector<T> GreadyActivitySelector(const std::vector<T>& startT,const std::vector<T>& finishT);

int _tmain(int argc, _TCHAR* argv[])
{
	/*��ʼ�����ʼʱ��ͽ���ʱ��,vector������ֵ��Ϊ����,
	Ϊ������Ҫ������һ����ʼʱ��ͽ���ʱ�䶼Ϊ0������,
	�˳���Ѱ������ʱ��������ź�*/
	int s[]={0,1,3,0,5,3,5,6,8,8,2,12};
	int f[]={0,4,5,6,7,9,9,10,11,12,14,16};
	std::vector<int> startT(s,s+12);
	std::vector<int> finishT(f,f+12);

	std::cout<<"���ʼʱ��:"<<'\n';
	Print(startT);//������ʼʱ��
	std::cout<<"�����ʱ��:"<<'\n';
	Print(finishT);//��������ʱ��
	std::cout<<"��ѻ���Ŵ���(����):"<<'\n';
	std::vector<int>  result=RecursiveActivitySelector(startT,finishT,0);
	Print(result);//��������Ľ��
	std::cout<<"��ѻ���Ŵ���(����):"<<'\n';
	result=GreadyActivitySelector(startT,finishT);
	Print(result);
	char a=getchar();
	return 0;
}


template<class T>
std::vector<T>
	RecursiveActivitySelector( const std::vector<T>& startT,const std::vector<T>& finishT,size_t k )
{
	/*kΪǰһ���Ѿ�ѡ�����*/
	size_t m=k+1;//mָ��k����һ������

	/*�ҳ���һ���ڻk����֮��ʼ�Ļ*/
	while (m<startT.size()&&startT.at(m)<finishT.at(k))
	{
		m++;
	}

	/*�ж��Ƿ�Ҫ�������еݹ�*/
	if (m<startT.size())
	{
		return Add(std::vector<T>(1,m),RecursiveActivitySelector(startT,finishT,m));
	}
	else
	{
		/*û�к�ѡ��򷵻ؿ�*/
		return std::vector<T>();
	}
}

template<class T>
std::vector<T>
	Add( const std::vector<T>& lhs,const std::vector<T>& rhs )
{
	/*�ϲ�����vector*/
	std::vector<T> temp=lhs;
	for (size_t i=0;i<rhs.size();++i)
	{
		temp.push_back(rhs.at(i));
	}
	return temp;
}

template<class T>
void Print( const std::vector<T>& vecIn )
{
	/*���vector*/
	for (size_t i=0;i<vecIn.size();++i)
	{
		std::cout<<vecIn.at(i)<<'\t';
	}
	std::cout<<std::endl;
}

template<class T>
std::vector<T>
	GreadyActivitySelector( const std::vector<T>& startT,const std::vector<T>& finishT )
{
	//��ʼ�����ҽ��1��������
	std::vector<T> vec;
	vec.push_back(1);
	size_t k=1;

	/*�ж��Ƿ�Ҫ�������е���*/
	for (size_t i=2;i<startT.size();++i)
	{
		if (startT.at(i)>=finishT.at(k))
		{
			vec.push_back(i);
			k=i;
		}
	}
	return vec;
}
