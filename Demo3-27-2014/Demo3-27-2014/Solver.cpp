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
		std::cerr<<"数据规模为0"<<std::endl;
	}

	std::vector<double> tempVec;
	tempVec.push_back(instalT.at(0)+machinT);//c1
	tempVec.push_back(instalT.at(0)+instalT.at(1)+machinT);//c2

	/*计算c(i)并且存入tempVec中*/
	for (size_t i=2;i<instalT.size();++i)
	{
		double temp=std::max(tempVec.at(i-1)-machinT,tempVec.at(i-2))+instalT.at(i)+machinT;
		tempVec.push_back(temp);
	}
	/*对穿所有的c(i)求和并且返回结果*/
	return Sum(tempVec);
}

double Solver::FuncOne( const std::vector<double>&instalT,double machinT/*=20*/ )
{
	int n=instalT.size();
	int k=n/2;

	if (n%2==0)
	{
		//n为偶数
		double tempSum=0;//tempSum存储个数据的和
		for (int i=0;i<n;++i)
		{
			tempSum+=k*(instalT.at(i++)+instalT.at(i)+2*machinT);
			--k;
		}
		return tempSum;
	}
	else
	{
		//n为奇数
		double tempSum=(k+1)*(instalT.at(0)+machinT);//tempSum存储个数据的和
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
		startValue,endValue,times);//vec为矩阵每行表示一组零件安装时间数据
	std::vector<double> tempVec;//存储每组数据f2/f1的值
	for (int i=0;i<times;++i)
	{
		double f1=FuncOne(vec.at(i),machinT);
		double f2=FuncTwo(vec.at(i),machinT);
		tempVec.push_back((f2/f1));

		std::cout<<"第 "<<i+1<<" 组安装时间为"<<std::endl;
		Print(vec.at(i));
	}

	/*求出times组数据中的f2/f1的最大值和最小值*/
	std::vector<double> tempVec1=tempVec;
	sort(tempVec1.begin(),tempVec1.end());//从小到大排序

	/*结果存入Result中并且返回*/
	return Result<double>(tempVec,tempVec1.at(tempVec1.size()-1),tempVec1.at(0));
}

std::vector<std::vector<double>> Solver::RandomVecGenerate( const int totalNum/*=20*/, const int startValue/*=0*/,const int endValue/*=40*/,const int times/*=10*/ )
{
	int length=endValue-startValue;//零件安装时间区间大小

	std::srand((unsigned)time(NULL));//设置均匀分布随机种子
	std::vector<std::vector<double>> vec;
	std::vector<double> tempVec;
	int tag=0;

	/*生产totalNum*times个零件安装时间数据*/
	for (int i=0;i<totalNum*times;++i)
	{
		tempVec.push_back(std::rand()%length+1);
	}

	/*以每组totalNum数据对以生产的数据进行分组并且存入vec中*/
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
	/*返回一个times*totalNum的矩阵,每行数据位一组零件安装时间数据*/
	return vec;
}
