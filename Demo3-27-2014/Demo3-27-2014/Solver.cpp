#include "stdafx.h"
#include "Solver.h"


Solver::Solver(void)
{
}


Solver::~Solver(void)
{
}

double Solver::Sum( std::vector<double> const &vec )
{
	double temp=0;
	for (size_t i=0;i<vec.size();++i)
	{
		temp+=vec.at(i);
	}
	return temp;
}

void Solver::Print( const std::vector<double>& vec )
{
	for (std::vector<double>::const_iterator it=vec.cbegin();it!=vec.cend();++it)
	{
		std::cout<<*it<<'\t';
	}
	std::cout<<std::endl;
}

double Solver::FuncTwo( const std::vector<double>&instalT,double machinT/*=20*/ )
{
	if (instalT.size()==0)
	{
		std::cerr<<"���ݹ�ģΪ0"<<std::endl;
	}

	std::vector<double> tempVec;
	tempVec.push_back(instalT.at(0)+machinT);//c1
	tempVec.push_back(instalT.at(0)+instalT.at(1)+machinT);//c2

	/*����c(i)���Ҵ���tempVec��*/
	for (size_t i=2;i<instalT.size();++i)
	{
		double temp=std::max(tempVec.at(i-1)-machinT,tempVec.at(i-2))+instalT.at(i)+machinT;
		tempVec.push_back(temp);
	}
	/*�Դ����е�c(i)��Ͳ��ҷ��ؽ��*/
	return Sum(tempVec);
}

double Solver::FuncOne( const std::vector<double>&instalT,double machinT/*=20*/ )
{
	int n=instalT.size();
	int k=n/2;

	if (n%2==0)
	{
		//nΪż��
		double tempSum=0;//tempSum�洢�����ݵĺ�
		for (int i=0;i<n;++i)
		{
			tempSum+=k*(instalT.at(i++)+instalT.at(i)+2*machinT);
			--k;
		}
		return tempSum;
	}
	else
	{
		//nΪ����
		double tempSum=(k+1)*(instalT.at(0)+machinT);//tempSum�洢�����ݵĺ�
		for (size_t i=1;i<instalT.size();++i)
		{
			tempSum+=k*(instalT.at(i++)+instalT.at(i)+2*machinT);
			--k;
		}
		return tempSum;
	}
}

Result<double> Solver::Calculate( const int totalNum/*=20*/, const int startValue/*=0*/,const int endValue/*=40*/,const int times/*=10*/,double machinT/*=20*/ )
{
	std::vector<std::vector<double>> vec=RandomVecGenerate(totalNum,
		startValue,endValue,times);//vecΪ����ÿ�б�ʾһ�������װʱ������
	std::vector<double> tempVec;//�洢ÿ������f2/f1��ֵ
	for (int i=0;i<times;++i)
	{
		double f1=FuncOne(vec.at(i),machinT);
		double f2=FuncTwo(vec.at(i),machinT);
		tempVec.push_back((f2/f1));

		std::cout<<"�� "<<i+1<<" �鰲װʱ��Ϊ"<<std::endl;
		Print(vec.at(i));
	}

	/*���times�������е�f2/f1�����ֵ����Сֵ*/
	std::vector<double> tempVec1=tempVec;
	sort(tempVec1.begin(),tempVec1.end());//��С��������

	/*�������Result�в��ҷ���*/
	return Result<double>(tempVec,tempVec1.at(tempVec1.size()-1),tempVec1.at(0));
}

std::vector<std::vector<double>> Solver::RandomVecGenerate( const int totalNum/*=20*/, const int startValue/*=0*/,const int endValue/*=40*/,const int times/*=10*/ )
{
	int length=endValue-startValue;//�����װʱ�������С

	std::srand((unsigned)time(NULL));//���þ��ȷֲ��������
	std::vector<std::vector<double>> vec;
	std::vector<double> tempVec;
	int tag=0;

	/*����totalNum*times�������װʱ������*/
	for (int i=0;i<totalNum*times;++i)
	{
		tempVec.push_back(std::rand()%length+1);
	}

	/*��ÿ��totalNum���ݶ������������ݽ��з��鲢�Ҵ���vec��*/
	for (int i=0;i<times;++i)
	{
		std::vector<double> vecLocal;
		static int tag=0;
		for (size_t j=0;j<totalNum;++j)
		{
			vecLocal.push_back(tempVec.at(tag++));
		}
		sort(vecLocal.begin(),vecLocal.end());
		vec.push_back(vecLocal);
	}
	/*����һ��times*totalNum�ľ���,ÿ������λһ�������װʱ������*/
	return vec;
}
