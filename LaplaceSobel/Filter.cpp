#include "stdafx.h"
#include "Filter.h"


Filter::Filter(void)
{
}


Filter::~Filter(void)
{
}

cv::Mat Filter::Laplace( cv::Mat& image )
{
	double m[3][3]={-1,-1,-1,-1,9,-1,-1,-1,-1};
	cv::Mat filterMat(3,3,CV_64FC1,m);

	int highImage=image.rows;
	int wideImage=image.cols;
	image.convertTo(image,CV_64FC1);
	cv::Mat result(image.size(),CV_64FC1,cv::Scalar(0));
	cv::Mat ROI=cv::Mat(filterMat.size(),CV_64FC1);

	//用拉普拉斯算子逐像素增强
	for (int i=1;i<wideImage-1;++i)
	{
		for (int j=1;j<highImage-1;++j)
		{
			ROI=cv::Mat(image,cv::Rect(i-1,j-1,3,3));
			result.at<double>(j,i)=(cv::sum(ROI.mul(filterMat)))[0];
			//d::cout<<(cv::sum(ROI.mul(filterMat)))[0]<<std::endl;
		}
	}//result拉普莱斯图像
	//result=image-result;//拉普拉斯图像和原图像相加

	//将CV_64FC1转化为CV_64FC1以便于显示
	//d::cout<<result<<std::endl;
	image.convertTo(image,CV_8UC1);
	result.convertTo(result,CV_8UC1);
	return result;
}

cv::Mat Filter::Sobel( cv::Mat&image )
{
	double r[3][3]={{-1,-2,-1},{0,0,0},{1,2,1}};
	double c[3][3]={{-1,0,1},{-2,0,2},{-1,0,1}};
	cv::Mat sobelRow(3,3,CV_64FC1,r);
	cv::Mat sobelCol(3,3,CV_64FC1,c);

	cv::Mat result=cv::Mat(image.size(),CV_64FC1);
	image.convertTo(image,CV_64FC1);
	cv::Mat ROI=cv::Mat(sobelRow.size(),CV_64FC1,cv::Scalar(0));

	int nrow=image.rows;
	int ncol=image.cols;
	int fsize=sobelRow.rows;

	for (int i=1;i<nrow-1;++i)
	{
		for (int j=1;j<ncol-1;++j)
		{
			ROI=cv::Mat(image,cv::Rect(j-1,i-1,3,3));
			cv::Mat xMat=ROI.mul(sobelRow);
			cv::Mat yMat=ROI.mul(sobelCol);
			cv::Scalar x=cv::sum(xMat);
			cv::Scalar y=cv::sum(yMat);
			//std::cout<<xMat<<'\n'<<yMat<<std::endl;
			result.at<double>(i,j)=std::abs(x[0])+std::abs(y[0]);
		}
	}
	image.convertTo(image,CV_8UC1);
	result.convertTo(result,CV_8UC1);
	return result;
}
