#pragma once
#include <opencv2/core/core.hpp>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
class Histogram
{
public:
	Histogram(void);
	~Histogram(void);

	virtual void Traditional(cv::Mat &image)const;
	
};

