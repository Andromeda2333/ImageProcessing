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

/*��ȡָ���ַ����Ĺ�ϣֵ**/
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
	int pSize=p.size();//��ȡģʽ�Ĵ�С
	int hp=GetHashValue(p,q);//��ȡģʽ�Ĺ�ϣֵ
	int hw=GetHashValue(src.substr(0,pSize),q);//��ȡ�ַ���src����ʼ���ַ���

	//���pow(26,m-1) mod q
	int hb=1;
	for (int i=1;i<pSize;++i)
	{
		hb=(hb*26)%q;
	}

	int j=0;
	while (j<=src.size()-p.size())
	{
		//������ַ�����ģʽ�Ĺ�ϣֵ���,�����ַ�����ģʽ���ַ�������бȽ�
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
			
			//���ȫ��ƥ��,�򷵻�ƥ��λ��
			if (i==pSize)
			{
				return j+1;
			}
		}
		hw=((hw-(src[j]-'a')*hb)*26+src[j+pSize]-'a')%q;
		//������ȡģ����һ�������ڲ�û�ж���,%����������,����ģ����������
		//-3%13=-3����������������-3%13=10
		if (hw<0)
		{
			hw=hw+q;
		}
		++j;
	}
	return -1;
}

