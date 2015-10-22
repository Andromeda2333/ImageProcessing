#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "Demo.h"
#include "Solver.h"
#include "Histogram1D.h"
int main()
{
	Demo d;
	//d.ImReadAndShow();
	//d.Salt();
	//d.ColorReduce();


	//cv::Mat image1=cv::imread("1.jpg");
	//cv::Mat image;
	//cv::cvtColor(image1,image,CV_BGR2GRAY);
	//cv::namedWindow("1");
	//cv::imshow("1",image);
	//cv::imwrite("previous.jpg",image);
	//cv::Mat result;
	//d.Sharpen(image,result);
	//cv::imwrite("next.jpg",result);
	//cv::namedWindow("2");
	//cv::imshow("2",result);
	//cv::waitKey(40000);

	//cv::Mat image;
	//cv::cvtColor(cv::imread("1.jpg"),image,CV_BGR2GRAY);
	//cv::Mat fImage;
	//cv::cvtColor(cv::imread("add.jpg"),fImage,CV_BGR2GRAY);
	////d.Add(image,fImage);
	//d.AddOther(image,fImage);

	//Solver cdetect;
	//cv::Mat image=cv::imread("182.jpg");
	//if (!image.data)
	//{
	//	return 0;
	//}
	//cv::namedWindow("previous");
	//cv::imshow("previous",image);
	//cdetect.SetTargetColor(130,190,230);
	//cv::namedWindow("result");
	//cv::Mat result=cdetect.Process(image);
	//cv::imwrite("1822.jpg",result);
	//cv::imshow("result",result);
	//cv::waitKey();

	Histogram1D h;
	cv::Mat image=cv::imread("182.jpg",0);
	cv::MatND histo=h.GetHistogram(image);
	for (size_t i=0;i<256;++i)
	{
		std::cout<<"Value "<<i<<" ="<<histo.at<float>(i)<<std::endl;
	}
	cv::Mat resultImg=h.GetHistogramImage(image);
	cv::Mat thresholded;
	cv::threshold(image,thresholded,60,255,cv::THRESH_BINARY);

	cv::namedWindow("1");
	cv::imshow("1",image);
	cv::namedWindow("2");
	cv::imshow("2",resultImg);
	cv::namedWindow("3");
	cv::imshow("3",thresholded);
	cv::waitKey();
	return 0;
}