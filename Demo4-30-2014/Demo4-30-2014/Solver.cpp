#include "stdafx.h"
#include "Solver.h"


Solver::Solver(void)
{
}


Solver::~Solver(void)
{
}

std::vector<std::vector<double>> Solver::GenerateMat( int dim )
{
	std::vector<double>* vec=new std::vector<double>(dim,0);
	std::vector<std::vector<double>> mat(dim,std::vector<double>(dim,0));

	time_t t=time(0);
	std::srand((unsigned)(t));

	std::generate(vec->begin(),vec->end(),[]()
	{
		return std::rand()%20-10;
	});

	for (size_t i=0;i<dim;++i)
	{
		for (size_t j=0;j<dim;++j)
		{
			mat[i][j]=(*vec)[i]*(*vec)[j];
		}
	}
	delete vec;
	vec=nullptr;
	return  mat;
}

void Solver::PrintMat( std::vector<std::vector<double>>& mat )
{
	int dim=mat.size();
	for (size_t i=0;i<dim;++i)
	{
		for (size_t j=0;j<dim;++j)
		{
			std::cout<<mat[i][j]<<" ";
		}
		std::cout<<'\n';
	}
}

std::vector<double> Solver::Compute( std::vector<std::vector<double>>& matQ, std::vector<double>& vecB,double alpha,double sigma )
{
	double error=pow(10,-6);
	
	return vecB;
}

std::vector<double> Solver::GenerateB( int dim )
{
	time_t t=time(0);
	std::srand((unsigned)(t));
	std::vector<double> vec(dim,0);

	std::generate(vec.begin(),vec.end(),[]()
	{
		return std::rand()%20-10;
	});
	return vec;
}

double Solver::f( std::vector<std::vector<double>>& matQ, std::vector<double>& vecB,std::vector<double> &vecX )
{
	std::vector<double> vec(vecB.size(),0);
	for (int i=0;i<vecB.size();++i)
	{
		vec[i]=VecMul(vecX,matQ[i]);
	}
	return 0.5*VecMul(vec,vecX)+VecMul(vecB,vecX);
}

double Solver::VecMul( std::vector<double>&lhs,std::vector<double>&rhs )
{
	double sum=0;
	for (int i=0;i<lhs.size();++i)
	{
		sum+=lhs[i]*rhs[i];
	}
	return sum;
}

std::vector<double> Solver::GradientF( std::vector<std::vector<double>>& matQ, std::vector<double>& vecB,std::vector<double> &vecX )
{
	std::vector<double> vec(vecB.size(),0);
	std::vector<double> grad(vecB.size(),0);
	for (int i=0;i<vecB.size();++i)
	{
		vec[i]=VecMul(vecX,matQ[i]);
	}

	int i=0;
	std::generate(grad.begin(),grad.end(),[&]()
	{
		return vec[i]+vecX[i++];
	});
	return grad;
}

std::vector<double> Solver::SubVector( std::vector<double>&lhs,std::vector<double>&rhs )
{
	std::vector<double> vec(lhs.size(),0);
	int i=-1;
	std::generate(vec.begin(),vec.end(),[&]()
	{
		++i;
		return lhs[i]-rhs[i];
	});
	return vec;
}
