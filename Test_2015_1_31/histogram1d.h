#ifndef HISTOGRAM1D_H
#define HISTOGRAM1D_H
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class Histogram1D
{
public:
    Histogram1D();
    ~Histogram1D();

    cv::MatND getHistogram(const cv::Mat &image);
    cv::MatND getHistogramImg(const cv::Mat &image);

private:
    int histSize[1];
    float hranges[2];
    const float* ranges[1];
    int channels[1];
};

#endif // HISTOGRAM1D_H
