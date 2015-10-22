#include "stdafx.h"
#include "Demo.h"

using namespace cv;
using namespace std;

Demo::Demo(void)
{
}


Demo::~Demo(void)
{
}

void Demo::ImReadAndShow() const
{
	Mat img = imread("78.jpg");
	namedWindow("My image");

	imshow("My image", img);
	Mat result;
	flip(img,result,1);
	namedWindow("OutPut");
	imshow("OutPut",result);
	waitKey(50000);
}

void Demo::Salt() const
{
	Mat img=imread("78.jpg");
	namedWindow("1");
	imshow("1",img);
	Mat img1=img.clone();
	for (int k=0;k<3000;++k)
	{
		int i=rand()%img1.rows;
		int j=rand()%img1.cols;
		if (img1.channels()==1)
		{
			img1.at<uchar>(i,j)=255;
		}else
		{
			img1.at<Vec3b>(i,j)[0]=255;
			img1.at<Vec3b>(i,j)[1]=255;
			img1.at<Vec3b>(i,j)[2]=255;
		}
	}
	namedWindow("2");
	imshow("2",img1);
	waitKey(50000);
}

void Demo::ColorReduce() const
{
	int duration=cv::getTickCount();//测试运行时间getTickCount计算周期数，getTickFrequency计算每秒内的周期数
	int div=64;
	Mat img=imread("78.jpg");
	namedWindow("1");
	imshow("1",img);
	int nr=img.rows;
	int n=img.cols*img.channels();

	for (int i=0;i<nr;++i)
	{
		uchar* data_in=img.ptr<uchar>(i);
		for (int j=0;j<n;++j)
		{
			data_in[i]=data_in[i]/div*div+div/2;
		}
	}
	namedWindow("2");
	imshow("2",img);
	duration=cv::getTickCount()-duration;
	double times=duration/cv::getTickFrequency();
	std::cout<<times<<std::endl;
	waitKey(30000);
}

void Demo::Sharpen( const cv::Mat &image,cv::Mat &result ) const
{
	result.create(image.size(),image.type());

	for (int i=1;i<image.rows-1;++i)
	{
		const uchar* previous=image.ptr<const uchar>(i-1);
		const uchar* current=image.ptr<const uchar>(i);
		const uchar* next=image.ptr<const uchar>(i+1);
		uchar* outPut=result.ptr<uchar>(i);

		int nc=image.cols-1;
		for (int j=1;j<nc;++j)
		{
			*outPut++=cv::saturate_cast<uchar>(
				5*current[j]-current[j-1]-current[j+1]-previous[j]-next[j]);
		}
	}

	result.row(0).setTo(Scalar(0));
	result.row(result.rows-1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));
	result.col(result.cols-1).setTo(Scalar(0));
}

void Demo::Add(cv::Mat &image,cv::Mat &fImage) const
{
	Mat imageROT=image(Rect(500,700,fImage.cols,fImage.rows));
	addWeighted(imageROT,1,fImage,0.3,0,imageROT);
	imwrite("23.jpg",image);
}

void Demo::AddOther( cv::Mat &image,cv::Mat &fImage ) const
{
	Mat imageROT=image(Rect(500,700,fImage.cols,fImage.rows));
	fImage.copyTo(imageROT);
	cv::imwrite("23-2.jpg",image);
}


