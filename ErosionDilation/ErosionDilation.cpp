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
	namedWindow("ͼ��",CV_WINDOW_AUTOSIZE);

	createTrackbar("�˲�����С","ͼ��",&alphaSlider,50,MyBlur);

	namedWindow("��ʴͼ��",CV_WINDOW_AUTOSIZE);
	createTrackbar("��̬ѧ\n 0:����\n 1:ʮ�ֲ�\n 2:��Բ:",
		"��ʴͼ��",&erosionElem,maxElem,Erosion);
	createTrackbar("ģ���С:\n 2n+1",
		"��ʴͼ��",&erosionSize,maxkernelSize,Erosion);

	namedWindow("����ͼ��",CV_WINDOW_AUTOSIZE);
	createTrackbar("��̬ѧ\n 0:����\n 1:ʮ�ֲ�\n 2:��Բ:",
		"����ͼ��",&dilationElem,maxElem,Dilation);
	createTrackbar("ģ���С:\n 2n+1",
		"����ͼ��",&dilationSize,maxkernelSize,Dilation);

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
	imshow("ͼ��",dst);
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
	imshow("��ʴͼ��",erosionDst);
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
	imshow("����ͼ��",dilationDst);
}

