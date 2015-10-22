// MPI_FDT_6_10_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <mpi.h>
#include <mpicxx.h>

int _tmain(int argc, char* argv[])
{
	int id;
	int p;
	int count;
	cv::Mat dst;
	uchar* src;

	MPI::Init(argc,argv);
	id=MPI::COMM_WORLD.Get_rank();
	p=MPI::COMM_WORLD.Get_size();
	if (id==0)
	{
		dst=cv::imread("E:\\CodeBOX\\VC\\MPI_FDT_6_10_2014\\x64\\Debug\\image.tif",CV_LOAD_IMAGE_GRAYSCALE);
		count=dst.rows*dst.cols;
		src=new uchar[count];

		for (int i=0;i<count;++i)
		{
			*(src+i)=*(dst.data+i);
		}

		MPI::COMM_WORLD.Send(&count,1,MPI::INTEGER,1,345);
		MPI::COMM_WORLD.Send(src,count,MPI::UNSIGNED_CHAR,1,346);
	}
	else if (id==1)
	{
		MPI::COMM_WORLD.Recv(&count,1,MPI::INTEGER,0,345);
		src=new uchar[count];
		MPI::COMM_WORLD.Recv(src,count,MPI::UNSIGNED_CHAR,0,346);
		std::cout<<"process 1 :"<<count;
		dst=cv::Mat(300,300,CV_8UC1,src);
		cv::imwrite("E:\\CodeBOX\\VC\\MPI_FDT_6_10_2014\\x64\\Debug\\result.tif",dst);
	}
	MPI::Finalize();
	return 0;
}

