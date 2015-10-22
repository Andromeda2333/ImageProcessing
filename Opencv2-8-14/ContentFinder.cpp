#include "stdafx.h"
#include "ContentFinder.h"


ContentFinder::ContentFinder(void):threshold(-1.0f)
{
	ranges[0]=hranges;
	ranges[1]=hranges;
	ranges[2]=hranges;
}


ContentFinder::~ContentFinder(void)
{
}

void ContentFinder::SetThreshold( float t )
{
	threshold=t;
}

float ContentFinder::GetThreshold()
{
	return threshold;
}

void ContentFinder::SetHistogram( const cv::MatND &h )
{
	histogram=h;
	cv::normalize(histogram,histogram,1);
}

cv::Mat ContentFinder::Find( const cv::Mat &image,float minValue,float maxValue,int* channels,int dim )
{
	cv::Mat result;
	hranges[0]=minValue;
	hranges[1]=maxValue;
	for (int i=0;i<dim;++i)
	{
		this->channels[i]=channels[i];
	}
	cv::calcBackProject(&image,1,
		channels,
		histogram,
		result,
		ranges,
		255);
	if (threshold>0)
	{
		cv::threshold(result,result,255*threshold,255,cv::THRESH_BINARY);
	}
	return result;
}
