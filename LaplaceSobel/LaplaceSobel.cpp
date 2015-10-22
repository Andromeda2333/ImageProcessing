// LaplaceSobel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "Filter.h"
int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("image.tif",CV_LOAD_IMAGE_GRAYSCALE);//ԭʼͼ��
	cv::Mat imageLaplace;
	cv::Laplacian(image,imageLaplace,CV_8UC1,3);//������˹ͼ��
	cv::Mat imageLaplace1=image-imageLaplace;//������˹ͼ���ԭͼ��ӵ�ͼ��

	/*Sobel����*/
	cv::Mat imageSobel,gradx,grady;
	cv::Mat absGradx,absGrady;

	cv::Sobel(image,gradx,CV_16S,1,0,3);
	cv::Sobel(image,grady,CV_16S,0,1,3);

	cv::convertScaleAbs(gradx,absGradx);
	cv::convertScaleAbs(grady,absGrady);
	cv::addWeighted(absGradx,0.5,absGrady,0.5,0,imageSobel);

	/*��Sobel������ͼ����о�ֵƽ������*/
	cv::Mat imageAver;
	cv::blur(imageSobel,imageAver,cv::Size(3,3),cv::Point(-1,-1));

	cv::Mat imageLapSobel=imageLaplace1.mul(imageAver);
	cv::imshow("ԭʼͼ��",image);
	cv::imshow("������˹ͼ��",imageLaplace);
	cv::imshow("������˹+ԭͼ",imageLaplace1);
	cv::imshow("Sobelͼ��",imageSobel);
	cv::imshow("Sobel��ֵͼ��",imageAver);
	cv::imshow("lap��sobel",imageLapSobel);

	cv::waitKey();
	return 0;
}

