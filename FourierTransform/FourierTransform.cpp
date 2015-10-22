// FourierTransform.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <string>
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string fileName;
	fileName="image56.jpg";
	cv::Mat image=cv::imread(fileName,CV_LOAD_IMAGE_GRAYSCALE);

	if (image.empty())
	{
		return -1;
	}
	
	cv::Mat padded;
	int m=cv::getOptimalDFTSize(image.rows);
	int n=cv::getOptimalDFTSize(image.cols);
	cv::copyMakeBorder(image,padded,0,m-image.rows,0,n-image.cols,cv::BORDER_CONSTANT,cv::Scalar::all(0));
	cv::Mat planes[]={cv::Mat_<float>(padded),cv::Mat::zeros(padded.size(),CV_32F)};
	cv::Mat complexI;

	cv::merge(planes,2,complexI);
	cv::dft(complexI,complexI);
	cv::split(complexI,planes);
	cv::magnitude(planes[0],planes[1],planes[0]);
	cv::Mat magI=planes[0];
	magI+=cv::Scalar::all(1);
	cv::log(magI,magI);

	//magI=magI(cv::Rect(0,0,magI.cols&-2,magI.rows&-2));
	//int cx=magI.cols/2;
	//int cy=magI.rows/2;
	//cv::Mat q0(magI,cv::Rect(0,0,cx,cy));
	//cv::Mat q1(magI,cv::Rect(cx,0,cx,cy));
	//cv::Mat q2(magI,cv::Rect(0,cy,cx,cy));
	//cv::Mat q3(magI,cv::Rect(cx,cy,cx,cy));

	//cv::Mat tmp;
	//q0.copyTo(tmp);
	//q3.copyTo(q0);
	//tmp.copyTo(q3);

	//q1.copyTo(tmp);
	//q2.copyTo(q0);
	//tmp.copyTo(q2);

	int m1=magI.rows;
	int n1=magI.cols;
	cv::Mat res=magI.clone();
	for (int i=0;i<m1;++i)
	{
		for (int j=0;j<n1;++j)
		{
			res.at<float>((i+m1/2)%m1,(j+n1/2)%n1)=magI.at<float>(i,j);
		}
	}


	cv::normalize(res,res,0,1,CV_MINMAX);

	cv::imshow("Input Image",image);
	cv::imshow("spectrum magnitude",res);

	cv::waitKey();
	return 0;
}

