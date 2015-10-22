#include "stdafx.h"
#include "Enhance.h"


Enhance::Enhance(void)
{
}


Enhance::~Enhance(void)
{
}

cv::Mat Enhance::Sobel( cv::Mat&image,cv::Mat&sobelRow,cv::Mat&sobelCol )
{
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
