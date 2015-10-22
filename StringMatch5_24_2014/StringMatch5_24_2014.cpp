// StringMatch5_24_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int GetHashValue(const string& src,const int q);
int Match(const string &src,const string &p,const int q);

int _tmain(int argc, _TCHAR* argv[])
{
	
	//cout<<GetHashValue("c",100);
	string s("dajdahsduiahwjdskjdaoudwiopoahequepoqjeqkjrhweiorieopwrjwkrrhweroiqidsjlchjidfhqwoieipqorheiwqr");
	string p("sdu");
	cout<<Match(s,p,97);
	return 0;
}

/*获取指定字符串的哈希值**/
int GetHashValue( const string& src,const int q )
{
	int w=0;

	for (int i=0;i<src.size();++i)
	{
		w=(w*26+src[i]-'a')%q;
	}
	return w;
}

int Match( const string &src,const string &p,const int q )
{
	int pSize=p.size();//获取模式的大小
	int hp=GetHashValue(p,q);//获取模式的哈希值
	int hw=GetHashValue(src.substr(0,pSize),q);//获取字符串src的起始子字符串

	//求出pow(26,m-1) mod q
	int hb=1;
	for (int i=1;i<pSize;++i)
	{
		hb=(hb*26)%q;
	}

	int j=0;
	while (j<=src.size()-p.size())
	{
		//如果子字符串和模式的哈希值相等,则将子字符串和模式的字符逐个进行比较
		if (hw==hp)
		{
			int i=0;
			for (i=0;i<pSize;++i)
			{
				if (src[j+i]!=p[i])
				{
					break;
				}
			}
			
			//如果全部匹配,则返回匹配位置
			if (i==pSize)
			{
				return j+1;
			}
		}
		hw=((hw-(src[j]-'a')*hb)*26+src[j+pSize]-'a')%q;
		//复数的取模运算一般语言内部没有定义,%是求余运算,和求模运算有区别
		//-3%13=-3而不是我们期望的-3%13=10
		if (hw<0)
		{
			hw=hw+q;
		}
		++j;
	}
	return -1;
}

