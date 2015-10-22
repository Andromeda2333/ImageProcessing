#include "stdafx.h"
#include "ConjugateGra.h"

ConjugateGra::ConjugateGra( cv::Mat inQ,cv::Mat inb ):Q(inQ*(inQ.t())),b(inb),A(inQ)
{
	this->f=[&](cv::Mat x)->double
	{
		return 0.5*(x.dot(Q*x))-b.dot(x);
	};
	this->df=[&](cv::Mat x)->cv::Mat
	{
		return Q*x-b;
	};
}


ConjugateGra::~ConjugateGra(void)
{
}

cv::Mat ConjugateGra::GetNextPoint( const cv::Mat x,const cv::Mat d ) const
{
	double alpha=(d.dot(b-Q*x))/(d.dot(Q*d));
	//std::cout<<"alpha=="<<alpha<<'\n';
	return x+alpha*d;
}

double ConjugateGra::Func(const cv::Mat x ) const
{
	return f(x);
}

cv::Mat ConjugateGra::Dfunc( const cv::Mat x ) const
{
	return df(x);
}

cv::Mat ConjugateGra::Compute( const cv::Mat x0 ) const
{
	cv::Mat x1(x0.clone()),x2;
	cv::Mat d1=-1*Dfunc(x0),d2;
	cv::Mat g1=Dfunc(x0),g2;
	double beta=0;
	int n=0;
	do 
	{
		x2=GetNextPoint(x1,d1);
		g2=Dfunc(x2);

		beta=(g2.dot(g2))/(g1.dot(g1));
		std::cout<<"beta=="<<beta<<'\n';
		d2=-1*g2+beta*d1;

		x1=x2;
		d1=d2;
		g1=g2;
	} while (g2.dot(g2)>pow(10,-4));

	return A.t()*x1;
}

cv::Mat ConjugateGra::operator()(const cv::Mat x)const
{
	return Compute(x);
}
