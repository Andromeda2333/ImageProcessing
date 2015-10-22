// quick_sort2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <mpi.h>
#include"mpicxx.h"
//#include<iostream>
#define  TRUE 1
 using namespace MPI;
/*
	* ������: main
	* ���ܣ�ʵ�ֿ��������������
	* ���룺argcΪ�����в���������
	*       argvΪÿ�������в�����ɵ��ַ������顣
	* ��������ش��������������
*/
int GetDataSize();
void  para_QuickSort(int *data,int start,int end,int m,int id,int MyID);
int QuickSort(int *data,int start,int end);
int Partition(int *data,int start,int end);
int exp2(int num);
int log2(int num);
void  ErrMsg(char *msg);
int main(int argc,char *argv[])
{
	int DataSize;
	int *data=nullptr;
	/*MyID��ʾ���̱�־����SumID��ʾ���ڽ�����*/
	int	MyID, SumID;
	int i, j;
	int m, r;
	MPI_Status status;
	/*����MPI����*/
	MPI_Init(&argc,&argv);
	/*MPI_COMM_WORLD��ͨ����*/
	/*ȷ���Լ��Ľ��̱�־��MyID*/
	MPI_Comm_rank(MPI_COMM_WORLD,&MyID);	
	/*���ڽ�������SumID*/
	MPI_Comm_size(MPI_COMM_WORLD,&SumID);		
	/*�������(MyID=0)��ȡ��Ҫ��Ϣ�����������������й���*/
	if(MyID==0)
	{
		/*��ȡ����������ĳ���*/		
		DataSize=GetDataSize();
		data=(int *)malloc(DataSize*sizeof(int));
		/*�ڴ�������*/
		if(data==0) 
			ErrMsg("Malloc memory error!");
		/*��̬���ɴ���������*/
		srand(396);
		for(i=0;i<DataSize;i++)
		{
			data[i]=(int)rand();
			printf("%10d",data[i]);
		}
		printf("\n");
	}
	m=log2(SumID);   //���ú���:����Ϊ�׵�SumID�Ķ���

	/* �Ӹ����������������й㲥������������*/
	/*{"1"��ʾ���͵����뻺���е�Ԫ�صĸ���,	   */
	/* "MPI_INT"��ʾ����Ԫ�ص�����,			   */ 
	/* "0"��ʾroot processor��ID  }			   */
	MPI_Bcast(&DataSize,1,MPI_INT,0,MPI_COMM_WORLD);
	
	/*ID��Ϊ�Ĵ���������ִ������*/
	para_QuickSort(data,0,DataSize-1,m,0,MyID);
    
	/*ID��Ϊ�Ĵ�������ӡ���������������*/
	if(MyID==0)
	{
       printf("ʵ��Ӧ�ô���������%d\n ",exp2(m-1));
		for(i=0;i<DataSize;i++)
		{
			printf("%10d",data[i]);
		}
		printf("\n");
	}
	MPI_Finalize();		//��������
	//system("pause");
	return 0;
}/*
	* ������: para_QuickSort
	* ���ܣ����п������򣬶���ֹλ��Ϊstart��end�����У�ʹ�õ�m���ݸ���������������
	* ���룺��������data[1,n]��ʹ�õĴ���������^m
	* �������������data[1,n]
*/
void para_QuickSort(int *data,int start,int end,int m,int id,int MyID)
{
	int i, j;
	int r;
	int MyLength;
	int *tmp=nullptr;
	MPI_Status status;

	MyLength=-1;

	/*����ɹ�ѡ��Ĵ�����ֻ��һ������ô�ɴ�����id���ô������򣬶�Ӧ���㷨����(1.1)*/
	/*(1.1)	Pid call quicksort(data,i,j) */
	if(m==0)
	{
		if(MyID==id)
			QuickSort(data,start,end);
		return;
	}	

	/*�ɵ�id�Ŵ������������ݣ�������һ�������ݷ��͵�������id+exp2(m-1)����Ӧ���㷨����(1.2,1.3)*/
	/*(1.2) Pid: r=patrition(data,i,j)*/	
	if(MyID==id)
	{
		/*����ǰ��������R[1��n]���ֳ������������������R[1��i-1]��R[i��n](1��i��n)*/
		r=Partition(data,start,end);	
		MyLength=end-r;	
		
        /*(1.3)	Pid send data[r+1,m-1] to P(id+2m-1) */
		/* {MyLength��ʾ���ͻ�������ַ��*/
		/*  ����Ԫ����ĿΪ;		   */
		/*  MyID����Ϣ��ǩ}		   */
         /* ���������һ�����  ���ͳ���  */
        
		MPI_Send(&MyLength,1,MPI_INT,id+exp2(m-1),MyID,MPI_COMM_WORLD);
		/*�����������գ����id+2m-1�Ŵ�����ȡ���ݵ���ַ��data[r+1]*/
		if(MyLength!=0)
                     /* ���������һ�����			   */
	
	MPI_Send(data+r+1,MyLength ,MPI_INT,id+exp2(m-1),MyID,MPI_COMM_WORLD);
	}

	/*������id+exp2(m-1)���ܴ�����id���͵���Ϣ*/
	if(MyID==id+exp2(m-1))
	{         /* ���������һ�����			   */
        	MPI_Recv(&MyLength,1,MPI_INT,id,id,MPI_COMM_WORLD,&status);
		if(MyLength!=0)
		{
			tmp=(int *)malloc(MyLength*sizeof(int));
			if(tmp==0) ErrMsg("Malloc memory error!");
             /* ���������һ�����			   */
				MPI_Recv(tmp,MyLength,MPI_INT,id,id,MPI_COMM_WORLD,&status);
		}
	}

	/*�ݹ���ò������򣬶�Ӧ���㷨����(1.4��.5)*/

	/*��^m-1����������start--(r-1)�����ݽ��еݹ�����*/
	j=r-1-start;	
	MPI_Bcast(&j,1,MPI_INT,id,MPI_COMM_WORLD);
	/*(1.4)	para_quicksort(data,i,r-1,m-1,id)*/
	if(j>0)
         /* ���������һ�����			   */
     para_QuickSort(data,start,r-1,m-1,id,MyID);
		

	/*��^m-1����������(r+1)--end�����ݽ��еݹ�����*/
	j=MyLength;	
	MPI_Bcast(&j,1,MPI_INT,id,MPI_COMM_WORLD);
	/*(1.5)	para_quicksort(data,r+1,j,m-1,id+2m-1)*/
	if(j>0)
		/* ���������һ�����			   */
      	para_QuickSort(tmp,0,MyLength-1,m-1,id+exp2(m-1),MyID);

	/*������õ������ɴ�����id+exp2(m-1)����id�Ŵ���������Ӧ���㷨����(1.6)*/
	/*(1.6)	P(id+2m-1) send data[r+1,m-1] back to Pid */
	if((MyID==id+exp2(m-1)) && (MyLength!=0))
		MPI_Send(tmp,MyLength,MPI_INT,id,id+exp2(m-1),MPI_COMM_WORLD);

	if((MyID==id) && (MyLength!=0))
		MPI_Recv(data+r+1,MyLength,MPI_INT,id+exp2(m-1),id+exp2(m-1),MPI_COMM_WORLD,&status);
}

/*
	* ������: QuickSort
	* ���ܣ�����ֹλ��Ϊstart��end���������У����д��п�������
	* ���룺��������data[1,n]
	* ���أ���������data[1,n]
*/
int QuickSort(int *data,int start,int end)
{
	int r;
	int i;

	if(start<end)
	{
		r=Partition(data,start,end);
		QuickSort(data,start,r-1);
		QuickSort(data,r+1,end);
	}
	return 0;
}

/*
	* ������: Partition
	* ���ܣ�����ֹλ��Ϊstart��end���������У�����ֳ������ǿ������У�
	*		����ǰһ���������е�����Ԫ��С�ں�������е�Ԫ�ء�
	* ���룺��������data[1,n]
	* ����: �����ǿ������еķֽ��±�
*/
int Partition(int *data,int start,int end)
{
	int pivo;
	int i, j;
	int tmp;

	pivo=data[end];			
	i=start-1;				/*i(�ָ��)*/

	for(j=start;j<end;j++)
		if(data[j]<=pivo)
		{
			i++;			/*i��ʾ��pivoС��Ԫ�صĸ���*/
			tmp=data[i];
			data[i]=data[j];
			data[j]=tmp;
		}
	
	tmp=data[i+1];
	data[i+1]=data[end];
	data[end]=tmp;			/*��pivoΪ�ֽ磬data[i+1]=pivo*/

	return i+1;
}

/*
	* ������: exp2
	* ���ܣ����num����
	* ���룺int������num
	* ����: 2��num����
*/
int exp2(int num)
{
	int i;

	i=1;

	while(num>0)
	{
		num--;
		i=i*2;
	}
	
	return i;
}
/*
	* ������: log2
	* ���ܣ�����Ϊ�׵�num�Ķ���
	* ���룺int������num
	* ����: ��Ϊ�׵�num�Ķ���
*/
int log2(int num)
{
	int i, j;

	i=1;	
	j=2;

	while(j<num)
	{
		j=j*2;
		i++;
	}

	if(j>num)
		i--;

	return i;
}

/*
	* ������: GetDataSize
	* ���ܣ�������������г���
*/
int GetDataSize()
{
	int i;

	while(TRUE)
	{
		printf("Input the Data Size :");
		scanf_s("%d",&i);
		/*������ȷ��i�����أ����򣬼���Ҫ������*/
		if((i>0) && (i<=65535))		

			break;
		ErrMsg("Wrong Data Size, must between [1..65535]");
	}
	return i;
}
/*���������Ϣ*/
void ErrMsg(char *msg)
{
	printf("Error: %s \n",msg);
}
