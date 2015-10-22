// openv2-18-14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
static const int windowHeight=400;
static const int windowWide=400;
static const int NUMBER=99;
static const int x1=0;
static const int x2=400;
static const int y_1=0;
static const int y2=400;
static const int DELAY=10;
int DrawingRandomLines(cv::Mat image,std::string windowName,cv::RNG rng);
int DrawingRandomRectangles(cv::Mat image,std::string windowName,cv::RNG rng);
int DrawingRandomEllipses(cv::Mat image,std::string windowName,cv::RNG rng);
int DrawingRandomPolylines(cv::Mat image,std::string windowName,cv::RNG rng);
int DisplayRandomText(cv::Mat image,std::string windowName,cv::RNG rng);
static cv::Scalar RandomColor(cv::RNG& rng);
int _tmain(int argc, _TCHAR* argv[])
{
	cv::RNG rng(0xFFFFFFFF);
	cv::Mat image=cv::Mat::zeros(windowHeight,windowWide,CV_8UC3);
	std::string windowName="Random";
	cv::namedWindow(windowName);
	cv::imshow(windowName,image);

	//画直线
	int c=DrawingRandomLines(image,windowName,rng);
	if (c!=0)
	{
		return 0;
	}

	//画矩形
	c=DrawingRandomRectangles(image,windowName,rng);
	if (c!=0)
	{
		return 0;
	}

	//画椭圆
	c=DrawingRandomEllipses(image,windowName,rng);
	if (c!=0)
	{
		return 0;
	}

	//画折线
	c=DrawingRandomPolylines(image,windowName,rng);
	if (c!=0)
	{
		return 0;
	}

	//标记上字
	c=DisplayRandomText(image,windowName,rng);
	if (c!=0)
	{
		return 0;
	}
	cv::waitKey();
	return 0;
}

int DrawingRandomLines( cv::Mat image,std::string windowName,cv::RNG rng )
{
	int lineType=8;
	cv::Point pt1,pt2;

	for (int i=0;i<NUMBER;++i)
	{
		pt1.x=rng.uniform(x1,x2);
		pt2.x=rng.uniform(x1,x2);
		pt1.y=rng.uniform(y_1,y2);
		pt2.y=rng.uniform(y_1,y2);
		cv::line(image,pt1,pt2,RandomColor(rng),rng.uniform(1,10),lineType);
		cv::imshow(windowName,image);
		if (cv::waitKey(DELAY)>0)
		{
			return -1;
		}
	}
	return 0;
}

cv::Scalar RandomColor( cv::RNG& rng )
{
	int icolor=(unsigned)rng;
	return cv::Scalar(icolor&255,(icolor>>8)&255, (icolor>>16)&255);
}

int DrawingRandomRectangles( cv::Mat image,std::string windowName,cv::RNG rng )
{
	int lineType=8;
	cv::Point pt1,pt2;
	for (int i=0;i<NUMBER;++i)
	{
		pt1.x=rng.uniform(0,windowHeight);
		pt2.x=rng.uniform(0,windowHeight);
		pt1.y=rng.uniform(0,windowHeight);
		pt2.y=rng.uniform(0,windowHeight);

		cv::rectangle(image,pt1,pt2,RandomColor(rng),rng.uniform(1,10),lineType);
		cv::imshow(windowName,image);
		if (cv::waitKey(DELAY)>0)
		{
			return -1;
		}
	}
	return 0;
}

int DrawingRandomEllipses( cv::Mat image,std::string windowName,cv::RNG rng )
{
	cv::Point pt;
	int lineType=8;
	cv::Size s;
	for (int i=0;i<NUMBER;++i)
	{
		pt.x=rng.uniform(0,windowHeight);
		pt.y=rng.uniform(0,windowWide);
		s.width=rng.uniform(10,80);
		s.height=rng.uniform(10,90);
		cv::ellipse(image,pt,s,rng.uniform(-90,90),0,360,RandomColor(rng),rng.uniform(1,10),lineType);
		cv::imshow(windowName,image);
		if (cv::waitKey(DELAY)>0)
		{
			return -1;
		}
	}
	return 0;
}

int DrawingRandomPolylines( cv::Mat image,std::string windowName,cv::RNG rng )
{
	for (int i=0;i<NUMBER;++i)
	{
		cv::Point pt[2][3];
		pt[0][0].x = rng.uniform( 0, windowWide );
		pt[0][0].y = rng.uniform( 0, windowHeight );
		pt[0][1].x = rng.uniform( 0, windowWide );
		pt[0][1].y = rng.uniform( 0, windowHeight );
		pt[0][2].x = rng.uniform( 0, windowWide );
		pt[0][2].y = rng.uniform( 0, windowHeight );
		pt[1][0].x = rng.uniform( 0, windowWide );
		pt[1][0].y = rng.uniform( 0, windowHeight );
		pt[1][1].x = rng.uniform( 0, windowWide );
		pt[1][1].y = rng.uniform( 0, windowHeight );
		pt[1][2].x = rng.uniform( 0, windowWide );
		pt[1][2].y = rng.uniform( 0, windowHeight );

		const cv::Point* pts[2]={pt[0],pt[1]};
		const int npts[]={3,3};
		cv::polylines(image,pts,npts,2,1,RandomColor(rng),rng.uniform(1,10),8);
		cv::imshow(windowName,image);
		if (cv::waitKey(DELAY)>0)
		{
			return -1;
		}
	}
	return 0;
}

int DisplayRandomText( cv::Mat image,std::string windowName,cv::RNG rng )
{
	int lineType=8;
	for (int i=1;i<NUMBER;++i)
	{
		cv::Point org;
		org.x=rng.uniform(0,windowHeight);
		org.y=rng.uniform(0,windowWide);


		cv::putText(image,"dsdhau",org,rng.uniform(0,8),
			rng.uniform(0,50)*0.05+0.1,RandomColor(rng),rng.uniform(1,8),lineType);
		cv::imshow(windowName,image);
		if (cv::waitKey(DELAY)>0)
		{
			return -1;
		}
	}
	return 0;
}

