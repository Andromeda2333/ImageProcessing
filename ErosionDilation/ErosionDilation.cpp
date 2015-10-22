// ErosionDilation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;

Mat src,dst,erosionDst,dilationDst;
int alphaSlider=0;
int erosionElem=0;
int erosionSize=0;
int dilationElem=0;
int dilationSize=0;
int const maxElem=2;
int const maxkernelSize=21;

void Erosion(int,void*);
void Dilation(int,void*);
void MyBlur(int,void*);

int _tmain(int argc, _TCHAR* argv[])
{
	src=imread("image.tif",CV_LOAD_IMAGE_GRAYSCALE);
	alphaSlider=0;
	namedWindow("Í¼Ïñ",CV_WINDOW_AUTOSIZE);

	createTrackbar("ÂË²¨Æ÷´óÐ¡","Í¼Ïñ",&alphaSlider,50,MyBlur);

	namedWindow("¸¯Ê´Í¼Ïñ",CV_WINDOW_AUTOSIZE);
	createTrackbar("ÐÎÌ¬Ñ§\n 0:¾ØÐÎ\n 1:Ê®×Ö²æ\n 2:ÍÖÔ²:",
		"¸¯Ê´Í¼Ïñ",&erosionElem,maxElem,Erosion);
	createTrackbar("Ä£°å´óÐ¡:\n 2n+1",
		"¸¯Ê´Í¼Ïñ",&erosionSize,maxkernelSize,Erosion);

	namedWindow("ÅòÕÍÍ¼Ïñ",CV_WINDOW_AUTOSIZE);
	createTrackbar("ÐÎÌ¬Ñ§\n 0:¾ØÐÎ\n 1:Ê®×Ö²æ\n 2:ÍÖÔ²:",
		"ÅòÕÍÍ¼Ïñ",&dilationElem,maxElem,Dilation);
	createTrackbar("Ä£°å´óÐ¡:\n 2n+1",
		"ÅòÕÍÍ¼Ïñ",&dilationSize,maxkernelSize,Dilation);

	waitKey();
	return 0;
}

void MyBlur( int,void* )
{
	int i=alphaSlider%49;
	if (i%2==0)
	{
		i++;
	}
	blur(src,dst,Size(i,i),Point(-1,-1));
	imshow("Í¼Ïñ",dst);
}

void Erosion( int,void* )
{
	int erosionType;
	switch (erosionElem)
	{
	case 0:
		erosionType=MORPH_RECT;break;
	case 1:
		erosionType=MORPH_CROSS;break;
	case 2:
		erosionType=MORPH_ELLIPSE;
		break;
	}

	Mat element=getStructuringElement(
		erosionType,Size(2*erosionSize+1,2*erosionSize+1),
		Point(erosionSize,erosionSize));
	erode(src,erosionDst,element);
	imshow("¸¯Ê´Í¼Ïñ",erosionDst);
}

void Dilation( int,void* )
{
	int dilationType;
	switch (dilationElem)
	{
	case 0:
		dilationType=MORPH_RECT;break;
	case 1:
		dilationType=MORPH_CROSS;break;
	case 2:
		dilationType=MORPH_ELLIPSE;break;
	default:
		break;
	}

	Mat element=getStructuringElement(dilationType,
		Size(dilationSize*2+1,dilationSize*2+1),
		Point(dilationSize,dilationSize));
	dilate(src,dilationDst,element);
	imshow("ÅòÕÍÍ¼Ïñ",dilationDst);
}

