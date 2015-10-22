// opencv2-17-14.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
static const int w=300;
void MyLine(cv::Mat img,cv::Point start,cv::Point end);
void MyEllipse(cv::Mat img,double angle);
void MyFilledCircle(cv::Mat img,cv::Point center);
void MyPolygon( cv::Mat img );

int _tmain(int argc, _TCHAR* argv[])
{
	cv::namedWindow("Drawing 1:Atom");
	cv::namedWindow("Drawing 2:Rook");
	cv::Mat atomImage=cv::Mat::zeros(w,w,CV_8UC3);
	cv::Mat rookImage=cv::Mat::zeros(w,w,CV_8UC3);

	MyEllipse( atomImage, 90 );
	MyEllipse( atomImage, 0 );
	MyEllipse( atomImage, 45 );
	MyEllipse( atomImage, -45 );

	/// 1.b. 创建圆
	MyFilledCircle( atomImage, cv::Point( w/2.0, w/2.0) );

	MyPolygon( rookImage );

	/// 2.b. 创建矩形
	rectangle( rookImage,
		cv::Point( 0, 7*w/8.0 ),
		cv::Point( w, w),
		cv::Scalar( 0, 255, 255 ),
		-1,
		8 );

	/// 2.c. 画几条直线
	MyLine( rookImage, cv::Point( 0, 15*w/16 ), cv::Point( w, 15*w/16 ) );
	MyLine( rookImage, cv::Point( w/4, 7*w/8 ), cv::Point( w/4, w ) );
	MyLine( rookImage, cv::Point( w/2, 7*w/8 ), cv::Point( w/2, w ) );
	MyLine( rookImage, cv::Point( 3*w/4, 7*w/8 ), cv::Point( 3*w/4, w ) );

	cv::imshow("Drawing 1:Atom",atomImage);
	cv::imshow("Drawing 2:Rook",rookImage);
	cv::waitKey();
	return 0;
}

void MyLine( cv::Mat img,cv::Point start,cv::Point end )
{
	int thickness=2;
	int lineType=8;
	cv::line(img,
		start,
		end,
		cv::Scalar(0,0,0),
		thickness,
		lineType);
}

void MyEllipse( cv::Mat img,double angle )
{
	int thickness=2;
	int lineType=8;

	cv::ellipse(img,
		cv::Point(w/2,w/2),
		cv::Size(w/4,w/16),
		angle,
		0,
		360,
		cv::Scalar(255,0,0),
		thickness,
		lineType);
}

void MyFilledCircle( cv::Mat img,cv::Point center )
{
	int thickness = -1;
	int lineType = 8;

	circle( img,
		center,
		w/32.0,
		cv::Scalar( 0, 0, 255 ),
		thickness,
		lineType );
}

void MyPolygon( cv::Mat img )
{
	int lineType = 8;

	/** 创建一些点 */
	cv::Point rook_points[1][20];
	rook_points[0][0] = cv::Point( w/4.0, 7*w/8.0 );
	rook_points[0][1] = cv::Point( 3*w/4.0, 7*w/8.0 );
	rook_points[0][2] = cv::Point( 3*w/4.0, 13*w/16.0 );
	rook_points[0][3] = cv::Point( 11*w/16.0, 13*w/16.0 );
	rook_points[0][4] = cv::Point( 19*w/32.0, 3*w/8.0 );
	rook_points[0][5] = cv::Point( 3*w/4.0, 3*w/8.0 );
	rook_points[0][6] = cv::Point( 3*w/4.0, w/8.0 );
	rook_points[0][7] = cv::Point( 26*w/40.0, w/8.0 );
	rook_points[0][8] = cv::Point( 26*w/40.0, w/4.0 );
	rook_points[0][9] = cv::Point( 22*w/40.0, w/4.0 );
	rook_points[0][10] =cv:: Point( 22*w/40.0, w/8.0 );
	rook_points[0][11] = cv::Point( 18*w/40.0, w/8.0 );
	rook_points[0][12] = cv::Point( 18*w/40.0, w/4.0 );
	rook_points[0][13] = cv::Point( 14*w/40.0, w/4.0 );
	rook_points[0][14] = cv::Point( 14*w/40.0, w/8.0 );
	rook_points[0][15] = cv::Point( w/4.0, w/8.0 );
	rook_points[0][16] = cv::Point( w/4.0, 3*w/8.0 );
	rook_points[0][17] = cv::Point( 13*w/32.0, 3*w/8.0 );
	rook_points[0][18] = cv::Point( 5*w/16.0, 13*w/16.0 );
	rook_points[0][19] = cv::Point( w/4.0, 13*w/16.0) ;

	const cv::Point* ppt[1] = { rook_points[0] };
	int npt[] = { 20 };

	cv::fillPoly( img,
		ppt,
		npt,
		1,
		cv::Scalar( 255, 255, 255 ),
		lineType );

}

