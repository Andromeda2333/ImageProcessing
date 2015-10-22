#include <QCoreApplication>
#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>

cv::Mat ButFIlt(cv::Mat src);//巴特沃斯同态滤波
cv::Mat dft2Shift(cv::Mat src);//图像中心化
cv::Mat getBLPF(int rows,int cols);//对图像进行频域巴特沃斯同态滤波
cv::Mat getGradImg(cv::Mat src);//获取梯度图像
double Entropy(cv::Mat img);//计算图像信息熵

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cv::Mat img=cv::imread("Fig0635(middle_row_left_chalk ).tif",CV_LOAD_IMAGE_GRAYSCALE);
    cv::Mat result=getGradImg(img);
    cv::imwrite("result.tif",result);
    return a.exec();
}
cv::Mat ButFIlt(cv::Mat src){
    cv::Mat padded;
    int m=cv::getOptimalDFTSize(src.rows);
    int n=cv::getOptimalDFTSize(src.cols);
    cv::copyMakeBorder(src,padded,0,m-src.rows,0,n-src.cols,cv::BORDER_CONSTANT,cv::Scalar::all(0));
    padded=dft2Shift(padded);
    cv::Mat planes[]={padded,cv::Mat::zeros(padded.size(),CV_32F)};
    cv::Mat complexI;
    cv::merge(planes,2,complexI);

    cv::dft(complexI,complexI);
    cv::split(complexI,planes);
//    cv::magnitude(planes[0],planes[1],planes[0]);

    cv::Mat BLPF=getBLPF(m,n);
    cv::multiply(planes[0],BLPF,planes[0]);
    cv::multiply(planes[1],BLPF,planes[1]);

    cv::merge(planes,2,complexI);
    cv::idft(complexI,complexI);

    cv::split(complexI,planes);
    cv::Mat magI=dft2Shift(planes[0]);
    magI+=cv::Scalar::all(1);
    cv::log(magI,magI);
    cv::normalize(magI, magI, 255,0, cv::NORM_MINMAX);
    magI.convertTo(magI,CV_8U);

    cv::Mat timg=magI(cv::Range(0,src.rows),cv::Range(0,src.cols));
    return timg;

}
cv::Mat dft2Shift(cv::Mat src){
    cv::Mat dst;
    src.copyTo(dst);
    dst.convertTo(dst,CV_32F);

     float* p;
    for (int i=0;i<dst.rows;++i){
        p=dst.ptr<float>(i);
        for (int j=0;j<dst.cols;++j){
            p[j]=p[j]*std::pow(-1,i+j);
        }
    }
    return dst;
}

cv::Mat getBLPF(int rows,int cols){
    cv::Mat tmp=cv::Mat::zeros(rows,cols,CV_32F);
    float d_0=6,n=2,h_l=0.5,h_h=2;
    float h=h_h-h_l;
    float cent_x=rows/2,cent_y=cols/2;


    float* p;
    for (int i=0;i<rows;++i){
        p=tmp.ptr<float>(i);
        for (int j=0;j<cols;++j){
            p[j]=h/(1+std::pow(d_0/(std::sqrt((i-cent_x)*(i-cent_x)+
                                              (j-cent_y)*(j-cent_y))),2*n))+h_l;
        }
    }
    return tmp;
}
cv::Mat getGradImg(cv::Mat src){
    double b_11[9]={0,1,0,1,1,1,0,1,0};
    double b_12[9]={1,0,1,0,1,0,1,0,1};
    double b_21[9]={0,1,0,0,1,0,0,1,0};
    double b_22[9]={0,0,0,1,1,1,0,0,0};
    double b_23[9]={1,0,0,0,1,0,0,0,1};
    double b_24[9]={0,0,1,0,1,0,1,0,0};

    cv::Mat mask_11(3,3,CV_64F,b_11);mask_11.convertTo(mask_11,CV_8U);
    cv::Mat mask_12(3,3,CV_64F,b_12);mask_12.convertTo(mask_12,CV_8U);
    cv::Mat mask_21(3,3,CV_64F,b_21);mask_21.convertTo(mask_21,CV_8U);
    cv::Mat mask_22(3,3,CV_64F,b_22);mask_22.convertTo(mask_22,CV_8U);
    cv::Mat mask_23(3,3,CV_64F,b_23);mask_23.convertTo(mask_23,CV_8U);
    cv::Mat mask_24(3,3,CV_64F,b_24);mask_24.convertTo(mask_24,CV_8U);

    cv::Mat img,img_erod,img_dila;
    cv::Mat grad_11,grad_12,grad_21,grad_22,grad_23,grad_24;
    img=ButFIlt(src);

    cv::imwrite("src_gray.tif",src);
    cv::imwrite("src_butfile.tif",img);

    cv::erode(img,img_erod,mask_11);
    cv::dilate(img,img_dila,mask_11);
    cv::absdiff(img_dila,img_erod,grad_11);

    cv::erode(img,img_erod,mask_12);
    cv::dilate(img,img_dila,mask_12);
    cv::absdiff(img_dila,img_erod,grad_12);

    cv::erode(img,img_erod,mask_21);
    cv::dilate(img,img_dila,mask_21);
    cv::absdiff(img_dila,img_erod,grad_21);

    cv::erode(img,img_erod,mask_22);
    cv::dilate(img,img_dila,mask_22);
    cv::absdiff(img_dila,img_erod,grad_22);

    cv::erode(img,img_erod,mask_23);
    cv::dilate(img,img_dila,mask_23);
    cv::absdiff(img_dila,img_erod,grad_23);

    cv::erode(img,img_erod,mask_24);
    cv::dilate(img,img_dila,mask_24);
    cv::absdiff(img_dila,img_erod,grad_24);

    cv::imwrite("grad_11.tif",grad_11);
    cv::imwrite("grad_12.tif",grad_12);
    cv::imwrite("grad_21.tif",grad_21);
    cv::imwrite("grad_22.tif",grad_22);
    cv::imwrite("grad_23.tif",grad_23);
    cv::imwrite("grad_24.tif",grad_24);

    std::vector<double> h(6,0);
    std::vector<double> w(6,0);

    h[0]=Entropy(grad_11);
    h[1]=Entropy(grad_12);
    h[2]=Entropy(grad_21);
    h[3]=Entropy(grad_22);
    h[4]=Entropy(grad_23);
    h[5]=Entropy(grad_24);

    grad_11.convertTo(grad_11,CV_64F);grad_12.convertTo(grad_12,CV_64F);
    grad_21.convertTo(grad_21,CV_64F);grad_22.convertTo(grad_22,CV_64F);
    grad_23.convertTo(grad_23,CV_64F);grad_24.convertTo(grad_24,CV_64F);

    double sum_1=h[0]+h[1];
    double sum_2=h[2]+h[3]+h[4]+h[5];
    w[0]=h[0]/sum_1;
    w[1]=h[1]/sum_1;
    w[2]=h[2]/sum_2;
    w[3]=h[3]/sum_2;
    w[4]=h[4]/sum_2;
    w[5]=h[5]/sum_2;

    cv::Mat grad_1=w[0]*grad_11+w[1]*grad_12;
    cv::Mat grad_2=w[2]*grad_21+w[3]*grad_22+w[4]*grad_23+w[5]*grad_24;
    cv::Mat grad=grad_1+grad_2;

    cv::normalize(grad,grad,255,0,CV_MINMAX);
    grad.convertTo(grad,CV_8U);
    return grad;
}

// calculate entropy of an image
double Entropy(cv::Mat img){
 // 将输入的矩阵为图像
 double temp[256];
 // 清零
 for(int i=0;i<256;i++){
  temp[i] = 0.0;
 }

 // 计算每个像素的累积值
 for(int m=0;m<img.rows;m++){// 有效访问行列的方式
  const uchar* t = img.ptr<uchar>(m);
  for(int n=0;n<img.cols;n++){
   int i = t[n];
   temp[i] = temp[i]+1;
  }
 }
 // 计算每个像素的概率
 for(int i=0;i<256;i++){
  temp[i] = temp[i]/(img.rows*img.cols);
 }
 double result = 0;
 // 根据定义计算图像熵
 for(int i =0;i<256;i++) {
  if(temp[i]==0.0)
   result = result;
  else
   result = result-temp[i]*(log(temp[i])/log(2.0));
 }
 return result;
}
