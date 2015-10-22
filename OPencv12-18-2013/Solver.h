#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class Solver
{
public:
	Solver(void);
	~Solver(void);

	cv::Mat Process(const cv::Mat& image);
	void SetColorDistanceThreshold(int distance);
	int GetColorDistanceThreshold()const;
	void SetTargetColor(unsigned char red,unsigned char green,unsigned char blue);
	void SetTargetColor(cv::Vec3b color);
	cv::Vec3b GetTargetColor()const;
	int GetDistance(const cv::Vec3b& color)const;
private:
	int minDist;
	cv::Vec3b target;
	cv::Mat result;
	cv::Mat converted;
};

