#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
class ColorHistogram
{
public:
	ColorHistogram(void);
	~ColorHistogram(void);

	cv::MatND GetHistogram(const cv::Mat& image);
	cv::SparseMat GetSparseHitogram(const cv::Mat& image);
	cv::MatND GetHueHistogram(const cv::Mat& image,int minSaturation=0);
private:
	int histSize[3];
	float hranges[2];
	const float* ranges[3];
	int channels[3];
};

