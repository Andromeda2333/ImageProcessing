#include "stdafx.h"
#include "Solver.h"


Solver::Solver(void):minDist(90)
{
	target[0]=target[1]=target[2]=0;
}


Solver::~Solver(void)
{
}

void Solver::SetColorDistanceThreshold( int distance )
{
	if (distance<0)
	{
		distance=0;
	}
	minDist=distance;
}

int Solver::GetColorDistanceThreshold() const
{
	return minDist;
}

void Solver::SetTargetColor( unsigned char red,unsigned char green,unsigned char blue )
{
	//target[2]=red;
	//target[1]=green;
	//target[0]=blue;
	cv::Mat tmp(1,1,CV_8UC3);
	tmp.at<cv::Vec3b>(0,0)[0]=blue;
	tmp.at<cv::Vec3b>(0,0)[1]=green;
	tmp.at<cv::Vec3b>(0,0)[0]=red;
	cv::cvtColor(tmp,tmp,CV_BGR2Lab);
	target=tmp.at<cv::Vec3b>(0,0);
}

void Solver::SetTargetColor( cv::Vec3b color )
{
	target=color;
}

cv::Vec3b Solver::GetTargetColor() const
{
	return target;
}

int Solver::GetDistance( const cv::Vec3b& color ) const
{
	return abs(color[0]-target[0])+abs(color[1]-target[1])+abs(color[2]-target[2]);
}

cv::Mat Solver::Process( const cv::Mat& image )
{
	result.create(image.rows,image.cols,CV_8U);
	converted.create(image.rows,image.cols,image.type());
	cv::cvtColor(image,converted,CV_BGR2Lab);
	cv::Mat_<cv::Vec3b>::const_iterator it=converted.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itend=converted.end<cv::Vec3b>();
	cv::Mat_<uchar>::iterator itout=result.begin<uchar>();

	for (;it!=itend;++it,++itout)
	{
		if (GetDistance(*it)<minDist)
		{
			*itout=255;
		}
		else
		{
			*itout=0;
		}
	}
	return result;
}
