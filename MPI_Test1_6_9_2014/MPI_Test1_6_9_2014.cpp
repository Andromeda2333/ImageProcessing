// MPI_Test1_6_9_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mpi.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
	char message[20];
	int myrank;
	int getrank;
	MPI_Status status;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);
	if (myrank==0)
	{
		strcpy_s(message,"Hello ,process 1");
		getrank=4156;
		MPI_Send(message,strlen(message),MPI_CHAR,1,99,MPI_COMM_WORLD);
		MPI_Send(&getrank,1,MPI_INTEGER,1,78,MPI_COMM_WORLD);
	}
	else if (myrank==1)
	{
		MPI_Recv(message,20,MPI_CHAR,0,99,MPI_COMM_WORLD,&status);
		MPI_Recv(&getrank,1,MPI_INTEGER,0,78,MPI_COMM_WORLD,&status);
		cout<<"recv :"<<message<<" from "<<getrank<<endl;
	}
	MPI_Finalize();
	return 0;
}

