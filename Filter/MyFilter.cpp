#include "stdafx.h"
#include "MyFilter.h"


MyFilter::MyFilter(void)
{
}


MyFilter::~MyFilter(void)
{
}

cv::Mat MyFilter::MidFilter( const cv::Mat& image,const cv::Mat& modeMat )
{
	/*中值滤波*/

	cv::Mat resultImage(image.size(),image.type(),cv::Scalar(0));//初始化输出图像
	int modeHigh=modeMat.rows;//获取掩膜高度
	int modeWide=modeMat.cols;//获取掩膜宽度
	int nHighImage=image.rows;//待处理图像高度
	int nWideImage=image.cols;//待处理图像宽度

	if (modeHigh%2==0&&modeWide%2==0)//检查掩膜长宽是否为基数
	{
		std::cerr<<"The modeHigh or modeWide is not 2n+1"<<std::endl;
		return image;
	}

	int startHigh=(modeHigh+1)/2;//起始迭代行数
	int startWide=(modeWide+1)/2;//起始迭代列数
	int tHigh=nHighImage-startHigh;//终止迭代行数
	int tWide=nWideImage-startWide;//终止迭代列数
	for (int high=startHigh-1;high<tHigh;++high)//计算机计数特性故减一
	{
		for (int wide=startWide-1;wide<tWide;++wide)//计算机计数特性故减一
		{
			cv::Mat localImage=cv::Mat(image,cv::Rect(wide-startWide+1,high-startHigh+1,modeWide,modeHigh));
								//cv::Rect(i,j,n1,n2)其中i为列数,j为行数n1,n2为邻域宽度和高度,此处特别要注意
			//std::cout<<localImage<<std::endl;
			uchar mid=MideValue(localImage);//获取邻域中指
			//std::cout<<static_cast<int>(mid)<<'\t';
			resultImage.at<uchar>(high,wide)=mid;
		}
	}

	return resultImage;

}

cv::Mat MyFilter::AverFilter( const cv::Mat& image,const cv::Mat& modeMat )
{
	/*均值滤波*/
	cv::Mat resultImage(image.size(),image.type(),cv::Scalar(0));//初始化输出图像
	int modeHigh=modeMat.rows;//获取掩膜高度
	int modeWide=modeMat.cols;//获取掩膜宽度
	int nHighImage=image.rows;//待处理图像高度
	int nWideImage=image.cols;//待处理图像宽度

	if (modeHigh%2==0&&modeWide%2==0)//检查掩膜长宽是否为基数
	{
		std::cerr<<"The modeHigh or modeWide is not 2n+1"<<std::endl;
		return image;
	}

	int startHigh=(modeHigh+1)/2;//起始迭代行数
	int startWide=(modeWide+1)/2;//起始迭代列数
	int tHigh=nHighImage-startHigh;//终止迭代行数
	int tWide=nWideImage-startWide;//终止迭代列数
	for (int high=startHigh-1;high<tHigh;++high)//计算机计数特性故减一
	{
		for (int wide=startWide-1;wide<tWide;++wide)//计算机计数特性故减一
		{
			cv::Mat localImage=cv::Mat(image,cv::Rect(wide-startWide+1,high-startHigh+1,modeWide,modeHigh));
			//cv::Rect(i,j,n1,n2)其中i为列数,j为行数n1,n2为邻域宽度和高度,此处特别要注意
		
			uchar mid=Average(localImage,modeMat);//获取邻域均值
			
			resultImage.at<uchar>(high,wide)=mid;
		}
	}

	return resultImage;//返回处理后的图像
}

uchar MyFilter::MideValue( const cv::Mat& ROIImage )
{
	/*返回掩膜范围内像素值得中值*/
	std::vector<uchar> vec;

	for (int i=0;i<ROIImage.rows;++i)
	{
		for (int j=0;j<ROIImage.cols;++j)
		{
			vec.push_back(ROIImage.at<uchar>(i,j));
		}
	}

	//排序并返回结果
	std::sort(vec.begin(),vec.end());
	return vec.at((ROIImage.rows*ROIImage.cols+1)/2);
}

uchar MyFilter::Average( const cv::Mat& ROIImage,const cv::Mat& modeMat )
{
	int sum=0;
	int sumMode=0;//通知掩内像素值之和
	int r=ROIImage.rows;
	int c=ROIImage.cols;

	/*对两个矩阵求和*/
	for (int i=0;i<r;++i)
	{
		for (int j=0;j<c;++j)
		{
			/*因uchar类型表示上限不足以满足需求,故转为int型进行计算*/
			int roi=static_cast<int>(ROIImage.at<uchar>(i,j));
			int mod=static_cast<int>(modeMat.at<uchar>(i,j));
			sum+=roi*mod;
			sumMode+=mod;
		}
	}

	/*求均值并返回*/
	return static_cast<uchar>(sum/sumMode);
}
