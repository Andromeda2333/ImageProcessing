#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
class Histogram1D
{
public:
	Histogram1D(void);
	~Histogram1D(void);
	cv::MatND GetHistogram(const cv::Mat &image);
	cv::Mat GetHistogramImage(const cv::Mat &image);
private:
	int histSize[1];
	float hranges[2];
	const float* ranges[1];
	int channels[1];
};

