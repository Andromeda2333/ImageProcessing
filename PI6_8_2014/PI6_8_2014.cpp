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

	//��MPI_Comm_rank ��ý��̵�rank����rankֵΪ0��p-1�������,�൱�ڽ��̵�ID  
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);  
	//��MPI_Comm_size ��ý��̸���  int MPI_Comm_size(MPI_Comm comm, int *size);  
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

