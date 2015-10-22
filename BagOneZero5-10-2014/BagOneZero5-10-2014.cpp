// BagOneZero5-10-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

/*回溯法解决0-1背包问题**/

vector<bool> KnapsackBack(const vector<pair<double,double>>&obj,double bagWeight);
double GetPriceEst(const vector<pair<double,double>>&obj,const int k,const double bagWeight,
	const double pcur,const double wcur);
int _tmain(int argc, _TCHAR* argv[])
{
	double weight[5]={5,15,25,27,30};//物体重量
	double price[5]={12,30,44,46,50};//物体价格
	vector<pair<double,double>> obj(5);//存储物体
	int i=0;
	generate(obj.begin(),obj.end(),[&]()
	{
		auto temp=pair<double,double>(weight[i],price[i]);
		++i;
		return temp;
	});

	//对物体以单价递增的顺序排序
	sort(obj.begin(),obj.end(),[](pair<double,double> lhs,pair<double,double>rhs)
	{
		return lhs.second/lhs.first>rhs.second/rhs.first;
	});

	//输出物体重量和价格数据表
	for each (auto i in obj)
	{
		std::cout<<i.first<<" "<<i.second<<'\n';
	}

	//调用回溯法求解
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
	double wcur=0,pcur=0,ptotal=0,pest=0;//当前重量,当前价格,总价格,总估计价格
	int n=obj.size();
	int k=0;
	vector<bool> tag(n,false);//标记物体是否已被选取
	vector<bool> res;

	while (k>=0)
	{
		pest=GetPriceEst(obj,k,bagWeight,pcur,wcur);//对物体k后面可能取得最大价格进行估计
		if (pest>ptotal)//如果估计价格大于已存在的最优方案的价格
		{
			int i=0;

			//将物体装入背包中直到装完或者装不下
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

			//如果k之后的物体全部装入背包中
			if (i>=n)
			{
				//如果获得总价格大于已有最优价格
				if (pcur>ptotal)
				{
					ptotal=pcur;
					k=n;
					res=tag;
				}
			}
			//如果最后一个物体没有装入背包中
			else
			{
				k=i+1;
			}
		}
		else
		{
			//如果当前估计价格小于最优价格,则开始回溯,直到找到一个节点.此节点为其父节点的做儿子节点
			int j=k;
			if(j==n) j=n-1;//当k为n时要小心越界(书中代码此处未做处理)
			while ((j>=0)&&!tag[j])
			{
				j--;
			}

			//如果找不到这样的一个节点
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

