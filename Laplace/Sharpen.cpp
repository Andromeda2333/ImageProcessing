#include "stdafx.h"
#include "Sharpen.h"


Sharpen::Sharpen(void)
{
}


Sharpen::~Sharpen(void)
{
}

cv::Mat Sharpen::Laplace( cv::Mat& image,cv::Mat& filterMat )
{
	int highImage=image.rows;
	int wideImage=image.cols;
	image.convertTo(image,CV_64FC1);
	cv::Mat result(image.size(),CV_64FC1,cv::Scalar(0));
	cv::Mat ROI=cv::Mat(filterMat.size(),CV_64FC1);

	//��������˹������������ǿ
	for (int i=1;i<wideImage-1;++i)
	{
		for (int j=1;j<highImage-1;++j)
		{
			ROI=cv::Mat(image,cv::Rect(i-1,j-1,3,3));
			result.at<double>(j,i)=LaplaceComput(ROI,filterMat);
		}
	}//result������˹ͼ��
	//result=image-result;//������˹ͼ���ԭͼ�����
	
	//��CV_64FC1ת��ΪCV_64FC1�Ա�����ʾ
	image.convertTo(image,CV_8UC1);
	result.convertTo(result,CV_8UC1);
	return result;
}

double Sharpen::LaplaceComput( cv::Mat& ROI,cv::Mat& filterMat )
{
	double sum=0;
	for (int i=0;i<3;++i)
	{
		for (int j=0;j<3;++j)
		{
			sum+=(ROI.at<double>(i,j))*(filterMat.at<double>(i,j));
		}
	}
	return sum;
}

std::pair<double,double> Sharpen::MaxMinValue( cv::Mat& image )
{
	double maxV=0;
	double minV=0;

	for (int i=0;i<image.rows;++i)
	{
		for (int j=0;j<image.cols;++j)
		{
			double temp=(image.at<double>(i,j));
			if (temp<minV)
			{
				minV=temp;
			}
			else if (temp>maxV)
			{
				maxV=temp;
			}

		}
	}
	return std::pair<double,double>(maxV,minV);

}

cv::Mat Sharpen::LaplaceMore( cv::Mat& image,cv::Mat& filterMat )
{
	int highImage=image.rows;
	int wideImage=image.cols;
	image.convertTo(image,CV_64FC1);
	cv::Mat result(image.size(),CV_64FC1,cv::Scalar(0));
	cv::Mat ROI=cv::Mat(filterMat.size(),CV_64FC1);

	for (int i=1;i<wideImage-1;++i)
	{
		for (int j=1;j<highImage-1;++j)
		{
			ROI=cv::Mat(image,cv::Rect(i-1,j-1,3,3));
			result.at<double>(j,i)=LaplaceComput(ROI,filterMat);
		}
	}

	//ǰ�����ǻ�ȡ������˹ͼ��,�����Ƕ�������˹ͼ����б궨
	double maxV;
	double minV;
	cv::minMaxLoc(result,&minV,&maxV);
	result+=cv::Scalar(-minV);
	cv::minMaxLoc(result,&minV,&maxV);

	double temp=255;
	temp=temp/maxV;
	result=result.mul(temp);
	result.convertTo(result,CV_8UC1);
	image.convertTo(image,CV_8UC1);
	return result;
}
