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
	/*��ֵ�˲�*/

	cv::Mat resultImage(image.size(),image.type(),cv::Scalar(0));//��ʼ�����ͼ��
	int modeHigh=modeMat.rows;//��ȡ��Ĥ�߶�
	int modeWide=modeMat.cols;//��ȡ��Ĥ���
	int nHighImage=image.rows;//������ͼ��߶�
	int nWideImage=image.cols;//������ͼ����

	if (modeHigh%2==0&&modeWide%2==0)//�����Ĥ�����Ƿ�Ϊ����
	{
		std::cerr<<"The modeHigh or modeWide is not 2n+1"<<std::endl;
		return image;
	}

	int startHigh=(modeHigh+1)/2;//��ʼ��������
	int startWide=(modeWide+1)/2;//��ʼ��������
	int tHigh=nHighImage-startHigh;//��ֹ��������
	int tWide=nWideImage-startWide;//��ֹ��������
	for (int high=startHigh-1;high<tHigh;++high)//������������Թʼ�һ
	{
		for (int wide=startWide-1;wide<tWide;++wide)//������������Թʼ�һ
		{
			cv::Mat localImage=cv::Mat(image,cv::Rect(wide-startWide+1,high-startHigh+1,modeWide,modeHigh));
								//cv::Rect(i,j,n1,n2)����iΪ����,jΪ����n1,n2Ϊ�����Ⱥ͸߶�,�˴��ر�Ҫע��
			//std::cout<<localImage<<std::endl;
			uchar mid=MideValue(localImage);//��ȡ������ָ
			//std::cout<<static_cast<int>(mid)<<'\t';
			resultImage.at<uchar>(high,wide)=mid;
		}
	}

	return resultImage;

}

cv::Mat MyFilter::AverFilter( const cv::Mat& image,const cv::Mat& modeMat )
{
	/*��ֵ�˲�*/
	cv::Mat resultImage(image.size(),image.type(),cv::Scalar(0));//��ʼ�����ͼ��
	int modeHigh=modeMat.rows;//��ȡ��Ĥ�߶�
	int modeWide=modeMat.cols;//��ȡ��Ĥ���
	int nHighImage=image.rows;//������ͼ��߶�
	int nWideImage=image.cols;//������ͼ����

	if (modeHigh%2==0&&modeWide%2==0)//�����Ĥ�����Ƿ�Ϊ����
	{
		std::cerr<<"The modeHigh or modeWide is not 2n+1"<<std::endl;
		return image;
	}

	int startHigh=(modeHigh+1)/2;//��ʼ��������
	int startWide=(modeWide+1)/2;//��ʼ��������
	int tHigh=nHighImage-startHigh;//��ֹ��������
	int tWide=nWideImage-startWide;//��ֹ��������
	for (int high=startHigh-1;high<tHigh;++high)//������������Թʼ�һ
	{
		for (int wide=startWide-1;wide<tWide;++wide)//������������Թʼ�һ
		{
			cv::Mat localImage=cv::Mat(image,cv::Rect(wide-startWide+1,high-startHigh+1,modeWide,modeHigh));
			//cv::Rect(i,j,n1,n2)����iΪ����,jΪ����n1,n2Ϊ�����Ⱥ͸߶�,�˴��ر�Ҫע��
		
			uchar mid=Average(localImage,modeMat);//��ȡ�����ֵ
			
			resultImage.at<uchar>(high,wide)=mid;
		}
	}

	return resultImage;//���ش�����ͼ��
}

uchar MyFilter::MideValue( const cv::Mat& ROIImage )
{
	/*������Ĥ��Χ������ֵ����ֵ*/
	std::vector<uchar> vec;

	for (int i=0;i<ROIImage.rows;++i)
	{
		for (int j=0;j<ROIImage.cols;++j)
		{
			vec.push_back(ROIImage.at<uchar>(i,j));
		}
	}

	//���򲢷��ؽ��
	std::sort(vec.begin(),vec.end());
	return vec.at((ROIImage.rows*ROIImage.cols+1)/2);
}

uchar MyFilter::Average( const cv::Mat& ROIImage,const cv::Mat& modeMat )
{
	int sum=0;
	int sumMode=0;//֪ͨ��������ֵ֮��
	int r=ROIImage.rows;
	int c=ROIImage.cols;

	/*�������������*/
	for (int i=0;i<r;++i)
	{
		for (int j=0;j<c;++j)
		{
			/*��uchar���ͱ�ʾ���޲�������������,��תΪint�ͽ��м���*/
			int roi=static_cast<int>(ROIImage.at<uchar>(i,j));
			int mod=static_cast<int>(modeMat.at<uchar>(i,j));
			sum+=roi*mod;
			sumMode+=mod;
		}
	}

	/*���ֵ������*/
	return static_cast<uchar>(sum/sumMode);
}
