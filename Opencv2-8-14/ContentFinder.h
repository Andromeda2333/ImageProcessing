#pragma once
#include<opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
class ContentFinder
{
public:
	ContentFinder(void);
	virtual ~ContentFinder(void);

	void SetThreshold(float t);
	float GetThreshold();
	void SetHistogram(const cv::MatND &h);
	cv::Mat Find(const cv::Mat &image,float minValue,float maxValue,int* channels,int dim);
private:
	float hranges[2];
	const float* ranges[3];
	int channels[3];
	float threshold;
	cv::MatND histogram;
};

