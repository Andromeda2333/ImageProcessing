// MPI_Test2_6_9_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <mpi.h>
#include <mpicxx.h>
#include <iostream>
#include <string>
using namespace std;
int _tmain(int argc, char* argv[])
{
	int id ;
	int p;

	int temp;
	double wtime;
	char str[20];
	int* v;


	MPI::Init(argc,argv);
	p=MPI::COMM_WORLD.Get_size();
	id=MPI::COMM_WORLD.Get_rank();

	if (id==0)
	{
		temp=13465;
		strcpy_s(str,"Hello ,process 1");
		int a[6]={23,31,32,3,23,2};
		v=new int[6];
		memcpy(v,a,sizeof(a));

				for (int i=0;i<6;++i)
		{
			cout<<v[i]<<'\t';
		}
		cout<<'\n';

		MPI::COMM_WORLD.Send(str,strlen(str),MPI_CHAR,1,77);
		MPI::COMM_WORLD.Send(v,6,MPI_INTEGER,1,88);
		MPI::COMM_WORLD.Send(&temp,1,MPI_INTEGER,1,123);
	}
	else if (id==1)
	{
		v=new int[6];
		MPI::COMM_WORLD.Recv(str,20,MPI_CHAR,0,77);
		MPI::COMM_WORLD.Recv(v,6,MPI_INTEGER,0,88);
		MPI::COMM_WORLD.Recv(&temp,1,MPI_INTEGER,0,123);
		cout<<"recv :"<<str<<endl;
		cout<<"recv  temp :"<<temp<<endl;
		for (int i=0;i<6;++i)
		{
			cout<<v[i]<<'\t';
		}
		cout<<'\n';
	}
	MPI::Finalize();


	//if (id==0)
	//{
	//	wtime=MPI::Wtime();
	//	cout << "\n";
	//	cout << "HELLO_MPI - Master process:\n";
	//	cout << "  C++/MPI version\n";
	//	cout << "  An MPI example program.\n";
	//	cout << "\n";
	//	cout << "  The number of processes is " << p << "\n";
	//	cout << "\n";
	//}
	//cout << "  Process " << id << " says 'Hello, world!'\n";
	//
	//if (id==0)
	//{
	//	wtime=MPI::Wtime()-wtime;
	//	cout << "  Elapsed wall clock time = " << wtime << " seconds.\n";
	//}
	//MPI::Finalize();
	//if (id==0)
	//{
	//	cout << "\n";
	//	cout << "HELLO_MPI:\n";
	//	cout << "  Normal end of execution.\n";
	//	cout << "\n";
	//}

	return 0;
}

