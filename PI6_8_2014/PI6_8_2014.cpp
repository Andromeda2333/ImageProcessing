// PI6_8_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "mpi.h"

#include <iostream>

using namespace std;
int main(int argc, char* argv[])
{
	int myid,numprocs;  
	int namelen;  
	char processor_name[MPI_MAX_PROCESSOR_NAME];  

	MPI_Init(&argc, &argv);

	//用MPI_Comm_rank 获得进程的rank，该rank值为0到p-1间的整数,相当于进程的ID  
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);  
	//用MPI_Comm_size 获得进程个数  int MPI_Comm_size(MPI_Comm comm, int *size);  
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);  

	MPI_Get_processor_name(processor_name, &namelen);  

	cout<<"Hello World! by MoreWindows\nProcess "<<myid<<" of "<<numprocs<<" on "<<processor_name<<endl;
	 

	MPI_Finalize();  

	if (myid == 1)  
	{  
		cout<<"\nPress a key and exit.\n";
		
		getchar();  
	}  

	return 0;
}

