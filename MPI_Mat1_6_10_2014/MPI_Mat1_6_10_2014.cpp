// MPI_Mat1_6_10_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mpi.h>
#include <mpicxx.h>
#include <iostream>
#include <random>
void Show(double*Yk,const int wide,const int myid);


int _tmain(int argc, char* argv[])
{	
	const int n=400;
	double* Ak;//进程所分配到矩阵A的n/p行
	double* Xk;//进程所分到的向量x的n/p个值
	double* Yk;//进程需要计算的结果向量y的n/p个值

	int myid;//进程ID
	int p;//工作空间的进程总个数
	double wtime;//记录程序运行时间

	MPI::Init(argc,argv);
	myid=MPI::COMM_WORLD.Get_rank();
	p=MPI::COMM_WORLD.Get_size();

	int wide=n/p;

	//为Ak,Yk,Xk分配内存
	Ak=new double[wide*n];
	Xk=new double[wide];
	Yk=new double[wide];

	//初始化Yk
	for (int i=0;i<wide;++i)
	{
		Yk[i]=0;
	}

/************************************************************************/
/* 1.往各个进程分发数据部分                                           */
/************************************************************************/

	if (myid==0)
	{
		//初始化矩阵A和向量X
		std::srand(10000);
		int A[n][n];
		int X[n];
		for (int i=0;i<n;++i)
		{
			X[i]=std::rand()%5;
			for (int j=0;j<n;++j)
			{
				A[i][j]=std::rand()%20-7;
			}
		}

		//将A的0到wide-1行存入0号进程，X的0到wide-1行存入Xk;
		for (int i=0;i<wide;++i)
		{
			for (int j=0;j<n;++j)
			{
				Ak[i*n+j]=A[i][j];
			}
			Xk[i]=X[i];
		}

		for (int i=1;i<p;++i)
		{
			//产生第i个进程的Ak和Xk
			double* tAk=new double[wide*n];
			double* tXk=new double[wide];
			for (int r=0;r<wide;++r)
			{
				for (int c=0;c<n;++c)
				{
					tAk[r*n+c]=A[i*wide+r][c];
				}
				tXk[r]=X[i*wide+r];
			}

			//发送Ak和Xk到各个进程
			MPI::COMM_WORLD.Send(tAk,wide*n,MPI::DOUBLE,i,i+100);
			MPI::COMM_WORLD.Send(tXk,wide,MPI::DOUBLE,i,i+200);
		}
	}
	else
	{
		//为各个进程接收Ak和Xk
		MPI::COMM_WORLD.Recv(Ak,wide*n,MPI::DOUBLE,0,myid+100);
		MPI::COMM_WORLD.Recv(Xk,wide,MPI::DOUBLE,0,myid+200);
	}

/************************************************************************/
/* 2.并行计算部分                                                       */
/************************************************************************/
	if (myid==0)
	{
		wtime=MPI::Wtime();
	}

	//Yk部分初始值
	for (int k=0;k<wide;++k)
	{
		for (int i=0;i<wide;++i)
		{
			Yk[k]+=Ak[k*n+myid*wide+i]*Xk[i];
		}
	}

	//循环计算p-1轮
	for (int j=1;j<p;++j)
	{
		//每轮计算前发送Xk到前一个进程,接受后一个进程发来的Xk
		MPI::COMM_WORLD.Send(Xk,wide,MPI::DOUBLE,(myid-1+p)%p,3000);
		MPI::COMM_WORLD.Recv(Xk,wide,MPI::DOUBLE,(myid+1)%p,3000);

		//累加Yk
		for (int k=0;k<wide;++k)
		{
			for (int i=0;i<wide;++i)
			{
				Yk[k]+=Ak[k*n+((myid+j)%p)*wide+i]*Xk[i];
			}
		}
	}

	if (myid==0)
	{
		wtime=MPI::Wtime()-wtime;
	}

	MPI::Finalize();//结束并行部分
	
	//输出Yk在各进程上的值
	Show(Yk,wide,myid);

	if (myid==0)
	{
		std::cout<<"The time is "<<wtime<<std::endl;
	}

	return 0;
}

void Show( double *Yk,const int wide,const int myid )
{
	std::cout<<"Process results of "<<myid<<std::endl;
	for (int i=0;i<wide;++i)
	{
		std::cout<<Yk[i]<<'\t';
	}
	std::cout<<"\n***************************************************************\n";
}

