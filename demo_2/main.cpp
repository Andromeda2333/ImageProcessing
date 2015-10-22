#include <QCoreApplication>
#include<opencv2/opencv.hpp>

using namespace cv;
Mat DWT(Mat pImage, int nLayer);
Mat IDWT(Mat pImage, int nLayer);
void enhance_h_freq( Mat &src);
void enhance( Mat &src);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // 小波变换层数
    int nLayer = 2;
    // 输入彩色图像

    cv::Mat img=cv::imread("edge_2.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    cv::namedWindow("src");
    cv::imshow("src",img);

    img.convertTo(img,CV_32F);
    img=DWT(img,nLayer);
    enhance(img);
    img=IDWT(img,nLayer);
    cv::normalize(img,img,0,255,cv::NORM_MINMAX);
    img.convertTo(img,CV_8U);;
    cv::namedWindow("2");
    cv::imshow("2",img);

    return a.exec();
}

 //二维离散小波恢复（单通道浮点图像）
Mat IDWT(Mat pImage, int nLayer)
{
   // 执行条件
   if (!pImage.empty())
   {
      if (pImage.channels() == 1 &&
              pImage.depth() == CV_32F &&
              ((pImage.cols >> nLayer) << nLayer) == pImage.cols &&
              ((pImage.rows >> nLayer) << nLayer) == pImage.rows)
      {
         int     i, x, y, n;
         float   fValue   = 0;
         float   fRadius  = sqrt(2.0f);
         int     nWidth   = pImage.cols >> (nLayer - 1);
         int     nHeight  = pImage.rows >> (nLayer - 1);
         int     nHalfW   = nWidth / 2;
         int     nHalfH   = nHeight / 2;
         cv::Mat pData;
         pImage.copyTo(pData);
         float  *pRow     = new float[pImage.cols];
         float  *pColumn  = new float[pImage.rows];

         // 多层小波恢复
         for (n = 0; n < nLayer; n++, nWidth *= 2, nHeight *= 2, nHalfW *= 2, nHalfH *= 2)
         {
            // 垂直恢复
            for (x = 0; x < nWidth; x++)
            {
               // 频带系数
               for (i = 0; i < nHalfH; i++)
               {
                  pData.at<float>(i,x) /= fRadius;
                  pData.at<float>(nHalfH + i,x) *= fRadius;
               }
               // 提升小波恢复
               fValue = (pData.at<float>(nHalfH,x) + pData.at<float>(nHalfH + 1,x)) / 4;
               pData.at<float>(0,x) -= fValue;
               for (i = 1; i < nHalfH; i++)
               {
                  fValue = (pData.at<float>(nHalfH + i,x) + pData.at<float>(nHalfH + i - 1,x)) / 4;
                  pData.at<float>(i,x) -= fValue;
               }
               for (i = 0; i < nHalfH - 1; i++)
               {
                  fValue = (pData.at<float>(i,x) + pData.at<float>(i + 1,x)) / 2;
                  pData.at<float>(nHalfH + i,x) += fValue;
               }
               fValue = (pData.at<float>(nHalfH - 1,x) + pData.at<float>(nHalfH - 2,x)) / 2;
               pData.at<float>(nHeight - 1,x) += fValue;
               // 奇偶合并
               for (i = 0; i < nHalfH; i++)
               {
                  y = i * 2;
                  pColumn[y] = pData.at<float>(i,x);
                  pColumn[y + 1] = pData.at<float>(nHalfH + i,x);
               }
               for (i = 0; i < nHeight; i++)
               {
                  pData.at<float>(i,x) = pColumn[i];
               }
            }
            // 水平恢复
            for (y = 0; y < nHeight; y++)
            {
               // 频带系数
               for (i = 0; i < nHalfW; i++)
               {
                  pData.at<float>(y,i) /= fRadius;
                  pData.at<float>(y,nHalfW + i) *= fRadius;
               }
               // 提升小波恢复
               fValue = (pData.at<float>(y,nHalfW) + pData.at<float>(y,nHalfW + 1)) / 4;
               pData.at<float>(y,0) -= fValue;
               for (i = 1; i < nHalfW; i++)
               {
                  fValue = (pData.at<float>(y,nHalfW + i)+ pData.at<float>(y,nHalfW + i - 1)) / 4;
                  pData.at<float>(y,i) -= fValue;
               }
               for (i = 0; i < nHalfW - 1; i++)
               {
                  fValue = (pData.at<float>(y,i) + pData.at<float>(y,i + 1)) / 2;
                  pData.at<float>(y,nHalfW + i) += fValue;
               }
               fValue = (pData.at<float>(y,nHalfW - 1) + pData.at<float>(y,nHalfW - 2)) / 2;
               pData.at<float>(y,nWidth - 1) += fValue;
               // 奇偶合并
               for (i = 0; i < nHalfW; i++)
               {
                  x = i * 2;
                  pRow[x] = pData.at<float>(y,i);
                  pRow[x + 1] = pData.at<float>(y,nHalfW + i);
               }

               for(int k=0;k<nWidth;++k){
                   pData.at<float>(y,k)=pRow[k];
               }
            }
         }
         delete[] pRow;
         delete[] pColumn;
         return pData;
      }
   }
}
void enhance( Mat &src){
    int n_r=src.rows/4;
    int n_c=src.rows/4;

    cv::Mat tmp_ll_2,tmp_hl_2,tmp_lh_2,tmp_hh_2,tmp_hl_1,tmp_lh_1,tmp_hh_1;
    tmp_ll_2=src(cv::Range(0,n_r),cv::Range(0,n_c));//.copyTo(tmp_ll_2);
    tmp_lh_2=src(cv::Range(n_r,2*n_r),cv::Range(0,n_c));//.copyTo(tmp_lh_2);
    tmp_hl_2=src(cv::Range(0,n_r),cv::Range(n_c,n_c*2));//.copyTo(tmp_hl_2);
    tmp_hh_2=src(cv::Range(n_r,2*n_r),cv::Range(n_c,n_c*2));//.copyTo(tmp_hh_2);
    tmp_hl_1=src(cv::Range(0,2*n_r),cv::Range(2*n_c,src.cols));
    tmp_lh_1=src(cv::Range(2*n_r,src.rows),cv::Range(0,n_c*2));
    tmp_hh_1=src(cv::Range(2*n_r,src.rows),cv::Range(2*n_c,src.cols));

//    cv::Mat tmp;
//    cv::GaussianBlur(tmp_ll_2,tmp,cv::Size(3,3),1);
//    tmp.copyTo(src(cv::Range(0,n_r),cv::Range(0,n_c)));
    enhance_h_freq(tmp_ll_2);
    enhance_h_freq(tmp_lh_2);
    enhance_h_freq(tmp_hl_2);
    enhance_h_freq(tmp_hh_2);
    enhance_h_freq(tmp_hl_1);
    enhance_h_freq(tmp_lh_1);
    enhance_h_freq(tmp_hh_1);
}
void enhance_h_freq( Mat &src)
{
    float n=src.rows*src.cols;
    double min=0,max=0,k=45;
    cv::minMaxIdx(src,&min,&max);
    float T=(max+min)*0.5*std::sqrt(2*std::log(n));

    float* p;
    for(int i=0;i<src.rows;++i){
        p=src.ptr<float>(i);
        for(int j=0;j<src.cols;++j){
            if(p[j]>T){
                p[j]+=k*T;
            }
            else if(p[j]<-T){
                p[j]-=k*T;
            }else{
                p[j]=(k+1)*p[j]-T;
            }
        }
    }
}
// 二维离散小波变换（单通道浮点图像）
cv::Mat DWT(cv::Mat pImage, int nLayer)
{
   // 执行条件
   if (!pImage.empty())
   {
      if (pImage.channels() == 1 &&
         pImage.depth() == CV_32F &&
         ((pImage.cols >> nLayer) << nLayer) == pImage.cols &&
         ((pImage.rows >> nLayer) << nLayer) == pImage.rows)
      {

          std::cout<<"********************";
         int     i, x, y, n;
         float   fValue   = 0;
         float   fRadius  = sqrt(2.0f);
         int     nWidth   = pImage.cols;
         int     nHeight  = pImage.rows;
         int     nHalfW   = nWidth / 2;
         int     nHalfH   = nHeight / 2;

         cv::Mat pData;
         pImage.copyTo(pData);

         float  *pColumn  = new float[pImage.rows];

         float* p;
         // 多层小波变换
         for (n = 0; n < nLayer; n++, nWidth /= 2, nHeight /= 2, nHalfW /= 2, nHalfH /= 2)
         {
            // 水平变换
            for (y = 0; y < nHeight; y++)
            {
               // 奇偶分离
               p=pData.ptr<float>(y);
               cv::Mat row_data=pData.row(y).clone();
               for (i = 0; i < nHalfW; i++)
               {
                  x = i * 2;
                  p[i] = row_data.at<float>(0,x);
                  p[nHalfW + i] = row_data.at<float>(0,x + 1);
               }
               // 提升小波变换
               for (i = 0; i < nHalfW - 1; i++)
               {
                  fValue = (p[i] + p[i + 1]) / 2;
                  p[nHalfW + i] -= fValue;
               }
               fValue = (p[nHalfW - 1] + p[nHalfW - 2]) / 2;
               p[nWidth - 1] -= fValue;
               fValue = (p[nHalfW] + p[nHalfW + 1]) / 4;
               p[0] += fValue;
               for (i = 1; i < nHalfW; i++)
               {
                  fValue = (p[nHalfW + i] + p[nHalfW + i - 1]) / 4;
                  p[i] += fValue;
               }
               // 频带系数
               for (i = 0; i < nHalfW; i++)
               {
                  p[i] *= fRadius;
                  p[nHalfW + i] /= fRadius;
               }
            }
            // 垂直变换
            for (x = 0; x < nWidth; x++)
            {
               // 奇偶分离
               for (i = 0; i < nHalfH; i++)
               {
                  y = i * 2;
                  pColumn[i] = pData.at<float>(y,x);
                  pColumn[nHalfH + i] = pData.at<float>(y+1,x);
               }
               for (i = 0; i < nHeight; i++)
               {
                  pData.at<float>(i,x) = pColumn[i];
               }
               // 提升小波变换
               for (i = 0; i < nHalfH - 1; i++)
               {
                  fValue = (pData.at<float>(i,x) + pData.at<float>(i+1,x)) / 2;
                  pData.at<float>(nHalfH + i,x) -= fValue;
               }
               fValue = (pData.at<float>(nHalfH - 1,x) + pData.at<float>(nHalfH - 2,x)) / 2;
               pData.at<float>(nHeight - 1,x) -= fValue;
               fValue = (pData.at<float>(nHalfH,x) + pData.at<float>(nHalfH+1,x)) / 4;
               pData.at<float>(0,x) += fValue;
               for (i = 1; i < nHalfH; i++)
               {
                  fValue = (pData.at<float>(nHalfH+i,x) + pData.at<float>(nHalfH+i-1,x)) / 4;
                  pData.at<float>(i,x) += fValue;
               }
               // 频带系数
               for (i = 0; i < nHalfH; i++)
               {
                  pData.at<float>(i,x) *= fRadius;
                  pData.at<float>(nHalfH+i,x) /= fRadius;
               }
            }
         }
         delete[] pColumn;
         return pData;
      }
   }
}
