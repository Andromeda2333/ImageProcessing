// BagOneZero5-10-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*���ݷ����0-1��������**/

vector<bool> KnapsackBack(const vector<pair<double,double>>&obj,double bagWeight);
double GetPriceEst(const vector<pair<double,double>>&obj,const int k,const double bagWeight,
	const double pcur,const double wcur);
int _tmain(int argc, _TCHAR* argv[])
{
	double weight[5]={5,15,25,27,30};//��������
	double price[5]={12,30,44,46,50};//����۸�
	vector<pair<double,double>> obj(5);//�洢����
	int i=0;
	generate(obj.begin(),obj.end(),[&]()
	{
		auto temp=pair<double,double>(weight[i],price[i]);
		++i;
		return temp;
	});

	//�������Ե��۵�����˳������
	sort(obj.begin(),obj.end(),[](pair<double,double> lhs,pair<double,double>rhs)
	{
		return lhs.second/lhs.first>rhs.second/rhs.first;
	});

	//������������ͼ۸����ݱ�
	for each (auto i in obj)
	{
		std::cout<<i.first<<" "<<i.second<<'\n';
	}

	//���û��ݷ����
	vector<bool> tag=KnapsackBack(obj,50);
	for each (auto var in tag)
	{
		static int i=1;
		std::cout<<i<<"****"<<var<<'\n';
	}
	return 0;
}

vector<bool> KnapsackBack( const vector<pair<double,double>>&obj ,double bagWeight)
{
	double wcur=0,pcur=0,ptotal=0,pest=0;//��ǰ����,��ǰ�۸�,�ܼ۸�,�ܹ��Ƽ۸�
	int n=obj.size();
	int k=0;
	vector<bool> tag(n,false);//��������Ƿ��ѱ�ѡȡ
	vector<bool> res;

	while (k>=0)
	{
		pest=GetPriceEst(obj,k,bagWeight,pcur,wcur);//������k�������ȡ�����۸���й���
		if (pest>ptotal)//������Ƽ۸�����Ѵ��ڵ����ŷ����ļ۸�
		{
			int i=0;

			//������װ�뱳����ֱ��װ�����װ����
			for (i=k;i<n;++i)
			{
				if (wcur+obj[i].first<=bagWeight)
				{
					wcur+=obj[i].first;
					pcur+=obj[i].second;
					tag[i]=true;
				} 
				else
				{
					tag[i]=false;
					break;
				}
			}

			//���k֮�������ȫ��װ�뱳����
			if (i>=n)
			{
				//�������ܼ۸�����������ż۸�
				if (pcur>ptotal)
				{
					ptotal=pcur;
					k=n;
					res=tag;
				}
			}
			//������һ������û��װ�뱳����
			else
			{
				k=i+1;
			}
		}
		else
		{
			//�����ǰ���Ƽ۸�С�����ż۸�,��ʼ����,ֱ���ҵ�һ���ڵ�.�˽ڵ�Ϊ�丸�ڵ�������ӽڵ�
			int j=k;
			if(j==n) j=n-1;//��kΪnʱҪС��Խ��(���д���˴�δ������)
			while ((j>=0)&&!tag[j])
			{
				j--;
			}

			//����Ҳ���������һ���ڵ�
			if (j<0)
			{
				break;
			}
			else
			{
				wcur-=obj[j].first;
				pcur-=obj[j].second;
				tag[j]=false;
				k=j+1;
			}

			//for (int j=i;j>=0;--j)
			//{
			//	if (j<0)
			//	{
			//		break;
			//	}

			//	if (tag[j]==true)
			//	{
			//		tag[j]=false;
			//		k=j+1;
			//		wcur-=obj[j].first;
			//		pcur-=obj[j].second;
			//		break;
			//	}
			//}
		}
	}
	return res;
}

double GetPriceEst( const vector<pair<double,double>>&obj,const int k,
	const double bagWeight,const double pcur,const double wcur)
{
	int i=0;
	double tempW=wcur,tempP=pcur;
	for (i=k;i<obj.size();++i)
	{
		tempW+=obj[i].first;
		if (tempW<bagWeight)
		{
			tempP+=obj[i].second;
		} 
		else
		{
			tempP+=(bagWeight-tempW+obj[i].first)*obj[i].second/obj[i].first;
			break;
		}
	}
	return tempP;
}

