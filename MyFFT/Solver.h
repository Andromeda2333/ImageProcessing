#pragma once
#include <opencv2/core/core.hpp>
#include <complex>
#include <iostream>
#include <math.h>
#include <complex>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

typedef std::vector<std::complex<double>> myVector;

class Solver
{
public:
	Solver(void);
	~Solver(void);
	
	static cv::Mat Fft1(cv::Mat&vec);
	static cv::Mat Fft2(cv::Mat image);
private:
	static myVector FFT(myVector& vec);
};

