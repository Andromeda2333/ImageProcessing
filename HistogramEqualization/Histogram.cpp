#include "stdafx.h"
#include "Histogram.h"


Histogram::Histogram(void)
{
}


Histogram::~Histogram(void)
{
}

void Histogram::Traditional( cv::Mat &image ) const
{
	//��ʼ��
	int height=image.size().height;
	int width=image.size().width;
	int n=height*width;
	std::vector<int> numberTotal(256,0);
	std::vector<double> c(256,0);

	//ͳ�Ƹ��Ҷȼ�����Ӧ��������Ŀ
	for (int i=0;i<height;++i)
	{
		for (int j=0;j<width;++j)
		{
			numberTotal.at(image.at<uchar>(i,j))++;
		}
	}

	//��һ������
	/*
	for (int i=0;i<256;++i)
	{
		p.at(i)=numberTotal.at(i)/n;
	}
	*/

	//�ۼƹ�һ��ֱ��ͼ
	for (int i=0;i<256;++i)
	{
		for (int j=0;j<=i;++j)
		{
			c.at(i)+=numberTotal.at(j);
		}
		c.at(i)/=n;
	}

	//���������С����ֵ
	uchar maxV=image.at<uchar>(0,0);
	uchar minV=image.at<uchar>(0,0);

	for (int i=0;i<height;++i)
	{
		for (int j=0;j<width;++j)
		{
			if (maxV<image.at<uchar>(i,j))
			{
				maxV=image.at<uchar>(i,j);
			}else if (minV>image.at<uchar>(i,j))
			{
				minV=image.at<uchar>(i,j);
			}
		}
	}

	//���⻯
	for (int i=0;i<height;++i)
	{
		for (int j=0;j<width;++j)
		{
			int temp=static_cast<int>(image.at<uchar>(i,j));
			image.at<uchar>(i,j)=static_cast<uchar>(c.at(temp)*(maxV-minV)+minV);
		}
	}
}
