#include "stdafx.h"
#include "VSolver.h"


CVSolver::CVSolver(void)
{
}


CVSolver::~CVSolver(void)
{
}

cv::Mat CVSolver::GetQ( int dim )
{
	//time_t t=time(0);
	std::srand(100);
	cv::Mat rMat(dim,1,CV_64F);
	for (int i=0;i<dim;++i)
	{
		rMat.at<double>(i,0)=static_cast<double>(std::rand()%10);
	}

	return rMat*rMat.t(); 
}

double CVSolver::f( cv::Mat& startIndex,cv::Mat& Q,cv::Mat& b )
{
	cv::Mat x(startIndex.clone());
	return ((x.t()*Q).t()).dot(x)*0.5+b.dot(x);
}

cv::Mat CVSolver::Getb( int dim )
{
	std::srand(100);
	cv::Mat rMat(dim,1,CV_64F);
	for (int i=0;i<dim;++i)
	{
		rMat.at<double>(i,0)=std::rand()%100;
	}
	return rMat;
}

double CVSolver::ComputeConst( cv::Mat& x,cv::Mat& Q,cv::Mat& b )
{
	cv::Mat x1(x.clone()),x2,d;
	double f1=0,f2=0;
	int tag=0;
	for (int i=0;i<100;++i)
	{
		x2.release();

		d=Getd(x1,Q,b);
		double md=d.dot(d);
		x2=x1+(d/pow(md,0.5));
		f1=f(x1,Q,b);
		f2=f(x2,Q,b);

		std::cout<<"****************"<<std::endl;
		std::cout<<"次数:"<<i<<'\n'<<f1<<'\n'<<f2<<'\n';
		if (abs(f1-f2)<0.2)
		{
			break;
		}
		else
		{
			x1.release();
			x1=x2;
		}
		tag=i;
	}
	std::cout<<tag<<std::endl;
	return f2;
}

cv::Mat CVSolver::Getd( cv::Mat& x,cv::Mat& Q,cv::Mat& b )
{
	return -1*(Q*x+b);
}

double CVSolver::ComputeVar( cv::Mat& x,cv::Mat& Q,cv::Mat& b )
{
	cv::Mat x1(x.clone()),x2,d;
	double f1=0.0,f2=0.0;

	for (int i=0;i<1000;++i)
	{
		x2.release();
		x2=GetPointAmj(x1,Q,b);
		d=Getd(x1,Q,b);
		f1=f(x1,Q,b);
		f2=f(x2,Q,b);

		//std::cout<<"****************"<<std::endl;
		//std::cout<<"次数:"<<i<<'\n'<<f1<<'\n'<<f2<<'\n';

		if (abs(f1-f2)<0.09)
		{
			break;
		}
		else
		{
			x1.release();
			x1=x2;
		}

		std::cout<<"****************"<<std::endl;
		std::cout<<"次数:"<<i<<'\n'<<f1<<'\n'<<f2<<'\n';
		//std::cout<<"x1="<<x1<<std::endl;	
		
	}
	return f1;
}

cv::Mat CVSolver::GetPointAmj( cv::Mat& x,cv::Mat& Q,
							  cv::Mat& b,double sigma,double beta )
{
	double s=1;
	double m=0.0;
	double tag=0.0;

	cv::Mat x1=x.clone(),x2;
	cv::Mat d=Getd(x,Q,b);
	double md=d.dot(d);
	do 
	{
		x2=x1+s*pow(beta,m)*d;
		tag=f(x1,Q,b)-f(x2,Q,b)-sigma*s*pow(beta,m)*md;
		++m;
	} while (tag<0);
	return x2;
}

bool CVSolver::IsNonegtive( cv::Mat& x )
{

	int n=x.rows;
	for (int i=0;i<n;++i)
	{
		if (x.at<double>(i,0)<0)
		{
			return false;
		}
	}
	return true;
}

double CVSolver::ComputeProj( cv::Mat& x,cv::Mat& Q,cv::Mat& b )
{
	cv::Mat x1=x.clone(),x2;
	double f1=0.0,f2=0.0;
	double s=0.6,alpha=0.7;
	int times=0;

	for (int i=0;i<10000;++i)
	{
		x2.release();
		x2=(GetProj(x1,Q,b,s)-x1)*alpha+x1;
		f1=f(x1,Q,b);
		f2=f(x2,Q,b);
		cv::Mat d=Getd(x2,Q,b);
		if (abs(d.dot(x2))<pow(10,-4))
		{
			break;
		}
		x1.release();
		x1=x2;
		//if (true)
		//{
		//	std::cout<<"****************"<<std::endl;
		//	std::cout<<"x2="<<x2<<std::endl;
		//	std::cout<<"次数:"<<i<<'\n'<<"f1="<<f1<<'\n'<<"f2="<<f2<<'\n';
		//}
		times=i;
	}
	std::cout<<"次数:"<<times<<'\n'<<"f1="<<f1<<'\n'<<"f2="<<f2<<'\n';
	std::cout<<"极值点 x="<<x2<<std::endl;
	return f2;
}

cv::Mat CVSolver::GetProj( cv::Mat& x,cv::Mat& Q,cv::Mat& b,double s )
{
	cv::Mat x1=GetPointAmj(x,Q,b);
	for (int i=0;i<x.rows;++i)
	{
		if (x1.at<double>(i,0)<0)
		{
			x1.at<double>(i,0)=0;
		}
	}
	//std::cout<<"x1="<<x1<<std::endl;
	return x1;
}
