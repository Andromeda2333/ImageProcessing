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
	/*初始化活动开始时间和结束时间,vector的索引值即为活动编号,
	为处理需要设置了一个开始时间和结束时间都为0的虚拟活动,
	活动顺序已按活动结束时间递增的排好*/
	int s[]={0,1,3,0,5,3,5,6,8,8,2,12};
	int f[]={0,4,5,6,7,9,9,10,11,12,14,16};
	std::vector<int> startT(s,s+12);
	std::vector<int> finishT(f,f+12);

	std::cout<<"活动开始时间:"<<'\n';
	Print(startT);//输出活动开始时间
	std::cout<<"活动结束时间:"<<'\n';
	Print(finishT);//输出活动结束时间
	std::cout<<"最佳活动安排次序(活动编号):"<<'\n';
	std::vector<int>  result=RecursiveActivitySelector(startT,finishT,0);
	Print(result);//输出处理后的结果
	std::cout<<"最佳活动安排次序(活动编号):"<<'\n';
	result=GreadyActivitySelector(startT,finishT);
	Print(result);
	char a=getchar();
	return 0;
}


template<class T>
std::vector<T>
	RecursiveActivitySelector( const std::vector<T>& startT,const std::vector<T>& finishT,size_t k )
{
	/*k为前一个已经选择活动编号*/
	size_t m=k+1;//m指向活动k的下一个活动编号

	/*找出第一个在活动k结束之后开始的活动*/
	while (m<startT.size()&&startT.at(m)<finishT.at(k))
	{
		m++;
	}

	/*判断是否要继续进行递归*/
	if (m<startT.size())
	{
		return Add(std::vector<T>(1,m),RecursiveActivitySelector(startT,finishT,m));
	}
	else
	{
		/*没有候选活动则返回空*/
		return std::vector<T>();
	}
}

template<class T>
std::vector<T>
	Add( const std::vector<T>& lhs,const std::vector<T>& rhs )
{
	/*合并两个vector*/
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
	/*输出vector*/
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
	//初始化并且将活动1放入结果中
	std::vector<T> vec;
	vec.push_back(1);
	size_t k=1;

	/*判断是否要继续进行迭代*/
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
