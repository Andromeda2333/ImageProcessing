// NoiseRemove.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::Mat Filt(const cv::Mat src,const int ksize);
cv::Mat GetImage(const cv::Mat src,int maxsize);

uchar GetDstPoint(const cv::Mat src,int i,int j,int maxsize);

int _tmain(int argc, _TCHAR* argv[])
{
	cv::Mat image=cv::imread("Fig0514(a)(ckt_saltpep_prob_pt25).tif",CV_LOAD_IMAGE_GRAYSCALE);
	cv::namedWindow("Miaomiao");
	cv::imshow("Miaomiao",image);
	//cv::Mat dst=Filt(image,7);
	//cv::imshow("自适应局部噪声消除滤波器",dst);
	cv::Mat dst=GetImage(image,7);
	cv::imshow("自适应均值滤波器",dst);
	cv::waitKey();
	return 0;
}

cv::Mat Filt( const cv::Mat src,const int ksize )
{
	cv::Mat dst(src.size(),CV_64F,cv::Scalar(0));

	int nrow=src.rows;
	int ncol=src.cols;
	double sigma=1000;//高斯噪声的方差
	double meanValue=0;
	double sigmaLocal=0;

	for (int i=ksize;i<nrow-ksize;++i)
	{
		for (int j=ksize;j<ncol-ksize;++j)
		{
			cv::Mat ROI(src,cv::Rect(j-ksize,i-ksize,ksize,ksize));
			cv::Scalar meanV,var;
			cv::meanStdDev(src,meanV,var);//获取制定区域的均值和标准差
			meanValue=meanV[0];
			sigmaLocal=pow(var[0],2);
			double alpha=sigma/sigmaLocal;
			
			//计算降噪后心的像素值
			dst.at<double>(i,j)=src.at<uchar>(i,j)-alpha*(src.at<uchar>(i,j)-meanValue);	
		}
	}
	cv::normalize(dst,dst,1,0,CV_MINMAX);
	
	cv::convertScaleAbs(dst,dst,255,0);
	return dst;
}

uchar GetDstPoint( const cv::Mat src,int i,int j,int maxsize )
{
	double vMedian=0;
	double vMin=0;
	double vMax=0;
	int ksize=1;

	while (vMedian<=vMin||vMedian>=vMax)
	{
		cv::Mat ROI(src,cv::Rect(j,i,ksize,ksize));
		cv::minMaxIdx(ROI,&vMin,&vMax);
		cv::Mat temp(ROI.clone());
		std::sort(temp.begin<uchar>(),temp.end<uchar>());
		vMedian=temp.at<uchar>(ksize/2,ksize/2);
		ksize+=2;
		if (ksize>maxsize)
		{
			return vMedian;
		}
	}

	if (src.at<uchar>(i,j)>vMin&&src.at<uchar>(i,j)<vMax)
	{
		return src.at<uchar>(i,j);
	}
	else
	{
		return vMedian;
	}
}

cv::Mat GetImage( const cv::Mat src,int maxsize )
{
	cv::Mat dst=cv::Mat::zeros(src.size(),src.type());

	for (int i=0;i<src.rows-maxsize;++i)
	{
		for (int j=0;j<src.cols-maxsize;++j)
		{
			dst.at<uchar>(i,j)=GetDstPoint(src,i,j,maxsize);
		}
	}
	return dst;
}


