#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
int main()
{
	Mat img = imread("78.jpg");
	namedWindow("My image");

	imshow("My image", img);
	waitKey(5000);

	return 0;
}