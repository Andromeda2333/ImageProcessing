// Dijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>
#include <vector>
#include <math.h>

//Dijkstra�㷨
std::pair<std::vector<double>,std::vector<double>> Dijkstra(const cv::Mat& table,const int sIndex);

//��⼯��T�е���u������С�ĵ�
int MinDistance(const std::vector<double>& d,const std::vector<bool>&s);

//������
void Print(std::pair<std::vector<double>,std::vector<double>>&res);
int _tmain(int argc, _TCHAR* argv[])
{
	//��ʼ������
	cv::Mat table(8,8,CV_64F,cv::Scalar(100));
	table.at<double>(0,0)=0;table.at<double>(0,1)=1;table.at<double>(0,2)=4;table.at<double>(0,3)=4;
	table.at<double>(1,1)=0;table.at<double>(1,2)=2;table.at<double>(1,4)=9;
	table.at<double>(2,2)=0;table.at<double>(2,3)=3;table.at<double>(2,4)=6;table.at<double>(2,5)=3;table.at<double>(2,6)=4;
	table.at<double>(3,3)=0;table.at<double>(3,6)=7;
	table.at<double>(4,4)=0;table.at<double>(4,7)=1;
	table.at<double>(5,5)=0;table.at<double>(5,4)=2;table.at<double>(5,7)=5;
	table.at<double>(6,6)=0;table.at<double>(6,5)=1;table.at<double>(6,7)=3;
	table.at<double>(7,7)=0;

	//�����ʼ����ľ���
	std::cout<<"ԭʼ���ݱ�Ϊ:"<<'\n'<<table<<std::endl;
	
	//��Dijkstra�㷨����
	std::cout<<'\n'<<'\n'<<"�����Ľ��Ϊ"<<'\n';
	std::pair<std::vector<double>,std::vector<double>> res=
		Dijkstra(table,0);
	
	//������
	Print(res);
	system("pause");

	return 0;
}

std::pair<std::vector<double>,std::vector<double>> Dijkstra( const cv::Mat& table,const int sIndex )
{
		/*�����ݳ�ʼ��*/
		const int n=table.rows;
		std::vector<bool> s(n,false);//�Ը�����б��:true---�õ��ڼ���S��,false--�õ���T��
		std::vector<double> p(n,0);//p[i]��ʾ��i����u�����·���ϵ�ǰ��������
		std::vector<double> d;

		//��ʼ��d
		for (int i=0;i<n;++i)
		{
			d.push_back(table.at<double>(sIndex,i));
		}

		for (int i=1;i<n;++i)
		{
			////��⵱ǰ����T�е���u������С�ĵ�
			int t=MinDistance(d,s);
			
			if (t==-1)
			{
				break;
			}
			
			s.at(t)=true;//��t����S��
			for (int x=0;x<n;++x)
			{
				if (s.at(x)==false&&
					d.at(x)>d.at(t)+table.at<double>(t,x))
				{
					d.at(x)=d.at(t)+table.at<double>(t,x);
					p.at(x)=t;
				}
			}

		}
		return std::pair<std::vector<double>,std::vector<double>>(d,p);
		
}

int MinDistance( const std::vector<double>& d,const std::vector<bool>&s)
{
	double temp=100;
	int index=-1;
	for (int i=0;i<d.size();++i)
	{
		if (d.at(i)<temp&&s.at(i)==false)
		{
			temp=d.at(i);
			index=i;
		}
	}
	//std::cout<<temp<<std::endl;
	return index;
}

void Print( std::pair<std::vector<double>,std::vector<double>>&res )
{
	std::string lab("abcdefgh");

	for (size_t i=0;i<res.first.size();++i)
	{
		std::cout<<"�� a �� "<<lab.at(i)<<" ����̾���Ϊ: "<<res.first.at(i)<<std::endl
			<<"���·��Ϊ:";

		int tag=i;
		int temp=0;
		std::vector<int> tempVec(1,i);
		for (;;)
		{
			temp=res.second.at(tag);
			if (temp==0)
			{
				tempVec.push_back(0);
				break;
			}
			tempVec.push_back(temp);
			tag=temp;
		}

		for (size_t i=0;i<tempVec.size()-1;++i)
		{
			std::cout<<lab.at(tempVec.at(i))<<" -> ";
		}
		std::cout<<lab.at(*(tempVec.end()-1))<<'\n';
		std::cout<<"************************************************"<<'\n';
	}
}

