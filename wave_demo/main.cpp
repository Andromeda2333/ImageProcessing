#include <QCoreApplication>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
using namespace cv;

Mat WDT( const Mat &_src, const string _wname, const int _level );
Mat IWDT( const Mat &_src, const string _wname, const int _level );
void wavelet( const string _wname, Mat &_lowFilter, Mat &_highFilter );
Mat waveletDecompose( const Mat &_src, const Mat &_lowFilter, const Mat &_highFilter );
Mat waveletReconstruct( const Mat &_src, const Mat &_lowFilter, const Mat &_highFilter );

void enhance(Mat &src);
void enhance_h_freq(Mat &src);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Mat img=cv::imread("lena512.bmp",CV_LOAD_IMAGE_GRAYSCALE);

    cv::namedWindow("src");
    cv::imshow("src",img);
    Mat dst=WDT(img,"haar",3);
//    enhance(dst);
    dst=IWDT(dst,"haar",3);
    cv::normalize(dst,dst,255,0,cv::NORM_MINMAX);
    dst.convertTo(dst,CV_8U);
    cv::namedWindow("dst");
    cv::imshow("dst",dst);
    cv::waitKey();

    return a.exec();
}


///  小波变换
Mat WDT( const Mat &_src, const string _wname, const int _level )
{
//    int reValue = THID_ERR_NONE;
    Mat src = Mat_<float>(_src);
    Mat dst = Mat::zeros( src.rows, src.cols, src.type() );
    int N = src.rows;
    int D = src.cols;

    /// 高通低通滤波器
    Mat lowFilter;
    Mat highFilter;
    wavelet( _wname, lowFilter, highFilter );

    /// 小波变换
    int t=1;
    int row = N;
    int col = D;

    while( t<=_level )
    {
        ///先进行行小波变换
        for( int i=0; i<row; i++ )
        {
            /// 取出src中要处理的数据的一行
            Mat oneRow = Mat::zeros( 1,col, src.type() );
            for ( int j=0; j<col; j++ )
            {
                oneRow.at<float>(0,j) = src.at<float>(i,j);
            }
            oneRow = waveletDecompose( oneRow, lowFilter, highFilter );
            /// 将src这一行置为oneRow中的数据
            for ( int j=0; j<col; j++ )
            {
                dst.at<float>(i,j) = oneRow.at<float>(0,j);
            }
        }

#if 0
        //normalize( dst, dst, 0, 255, NORM_MINMAX );
        IplImage dstImg1 = IplImage(dst);
        cvSaveImage( "dst.jpg", &dstImg1 );
#endif
        /// 小波列变换
        for ( int j=0; j<col; j++ )
        {
            /// 取出src数据的一行输入
            Mat oneCol = Mat::zeros( row, 1, src.type() );
            for ( int i=0; i<row; i++ )
            {
                oneCol.at<float>(i,0) = dst.at<float>(i,j);
            }
            oneCol = ( waveletDecompose( oneCol.t(), lowFilter, highFilter ) ).t();

            for ( int i=0; i<row; i++ )
            {
                dst.at<float>(i,j) = oneCol.at<float>(i,0);
            }
        }

#if 0
        //normalize( dst, dst, 0, 255, NORM_MINMAX );
        IplImage dstImg2 = IplImage(dst);
        cvSaveImage( "dst.jpg", &dstImg2 );
#endif

        /// 更新
        row /= 2;
        col /=2;
        t++;
        src = dst;
    }

    return dst;
}


///  小波逆变换
Mat IWDT( const Mat &_src, const string _wname, const int _level )
{
//    int reValue = THID_ERR_NONE;
    Mat src = Mat_<float>(_src);
    Mat dst = Mat::zeros( src.rows, src.cols, src.type() );
    int N = src.rows;
    int D = src.cols;

    /// 高通低通滤波器
    Mat lowFilter;
    Mat highFilter;
    wavelet( _wname, lowFilter, highFilter );

    /// 小波变换
    int t=1;
    int row = N/std::pow( 2., _level-1);
    int col = D/std::pow(2., _level-1);

    while ( row<=N && col<=D )
    {
        /// 小波列逆变换
        for ( int j=0; j<col; j++ )
        {
            /// 取出src数据的一行输入
            Mat oneCol = Mat::zeros( row, 1, src.type() );
            for ( int i=0; i<row; i++ )
            {
                oneCol.at<float>(i,0) = src.at<float>(i,j);
            }
            oneCol = ( waveletReconstruct( oneCol.t(), lowFilter, highFilter ) ).t();

            for ( int i=0; i<row; i++ )
            {
                dst.at<float>(i,j) = oneCol.at<float>(i,0);
            }
        }

#if 0
        //normalize( dst, dst, 0, 255, NORM_MINMAX );
        IplImage dstImg2 = IplImage(dst);
        cvSaveImage( "dst.jpg", &dstImg2 );
#endif
        ///行小波逆变换
        for( int i=0; i<row; i++ )
        {
            /// 取出src中要处理的数据的一行
            Mat oneRow = Mat::zeros( 1,col, src.type() );
            for ( int j=0; j<col; j++ )
            {
                oneRow.at<float>(0,j) = dst.at<float>(i,j);
            }
            oneRow = waveletReconstruct( oneRow, lowFilter, highFilter );
            /// 将src这一行置为oneRow中的数据
            for ( int j=0; j<col; j++ )
            {
                dst.at<float>(i,j) = oneRow.at<float>(0,j);
            }
        }

#if 0
        //normalize( dst, dst, 0, 255, NORM_MINMAX );
        IplImage dstImg1 = IplImage(dst);
        cvSaveImage( "dst.jpg", &dstImg1 );
#endif

        row *= 2;
        col *= 2;
        src = dst;
    }

    return dst;
}


////////////////////////////////////////////////////////////////////////////////////////////

/// 调用函数

/// 生成不同类型的小波，现在只有haar，sym2
void wavelet( const string _wname, Mat &_lowFilter, Mat &_highFilter )
{
    if ( _wname=="haar" || _wname=="db1" )
    {
        int N = 2;
        _lowFilter = Mat::zeros( 1, N, CV_32F );
        _highFilter = Mat::zeros( 1, N, CV_32F );

        _lowFilter.at<float>(0, 0) = 1/sqrtf(N);
        _lowFilter.at<float>(0, 1) = 1/sqrtf(N);

        _highFilter.at<float>(0, 0) = -1/sqrtf(N);
        _highFilter.at<float>(0, 1) = 1/sqrtf(N);
    }
    if ( _wname =="sym2" )
    {
        int N = 4;
        float h[] = {-0.483, 0.836, -0.224, -0.129 };
        float l[] = {-0.129, 0.224,    0.837, 0.483 };

        _lowFilter = Mat::zeros( 1, N, CV_32F );
        _highFilter = Mat::zeros( 1, N, CV_32F );

        for ( int i=0; i<N; i++ )
        {
            _lowFilter.at<float>(0, i) = l[i];
            _highFilter.at<float>(0, i) = h[i];
        }

    }
}

/// 小波分解
Mat waveletDecompose( const Mat &_src, const Mat &_lowFilter, const Mat &_highFilter )
{
    assert( _src.rows==1 && _lowFilter.rows==1 && _highFilter.rows==1 );
    assert( _src.cols>=_lowFilter.cols && _src.cols>=_highFilter.cols );
    Mat &src = Mat_<float>(_src);

    int D = src.cols;

    Mat &lowFilter = Mat_<float>(_lowFilter);
    Mat &highFilter = Mat_<float>(_highFilter);


    /// 频域滤波，或时域卷积；ifft( fft(x) * fft(filter)) = cov(x,filter)
    Mat dst1 = Mat::zeros( 1, D, src.type() );
    Mat dst2 = Mat::zeros( 1, D, src.type()  );

    filter2D( src, dst1, -1, lowFilter );
    filter2D( src, dst2, -1, highFilter );


    /// 下采样
    Mat downDst1 = Mat::zeros( 1, D/2, src.type() );
    Mat downDst2 = Mat::zeros( 1, D/2, src.type() );

    resize( dst1, downDst1, downDst1.size(), 0, 0, INTER_CUBIC );
    resize( dst2, downDst2, downDst2.size(), 0, 0, INTER_CUBIC );


    /// 数据拼接
    for ( int i=0; i<D/2; i++ )
    {
        src.at<float>(0, i) = downDst1.at<float>( 0, i );
        src.at<float>(0, i+D/2) = downDst2.at<float>( 0, i );
    }

    return src;
}

/// 小波重建
Mat waveletReconstruct( const Mat &_src, const Mat &_lowFilter, const Mat &_highFilter )
{
    assert( _src.rows==1 && _lowFilter.rows==1 && _highFilter.rows==1 );
    assert( _src.cols>=_lowFilter.cols && _src.cols>=_highFilter.cols );
    Mat &src = Mat_<float>(_src);

    int D = src.cols;

    Mat &lowFilter = Mat_<float>(_lowFilter);
    Mat &highFilter = Mat_<float>(_highFilter);

    /// 插值;
    Mat Up1 = Mat::zeros( 1, D, src.type() );
    Mat Up2 = Mat::zeros( 1, D, src.type() );

    /// 插值为0
    //for ( int i=0, cnt=1; i<D/2; i++,cnt+=2 )
    //{
    //    Up1.at<float>( 0, cnt ) = src.at<float>( 0, i );     ///< 前一半
    //    Up2.at<float>( 0, cnt ) = src.at<float>( 0, i+D/2 ); ///< 后一半
    //}

    /// 线性插值
    Mat roi1( src, Rect(0, 0, D/2, 1) );
    Mat roi2( src, Rect(D/2, 0, D/2, 1) );
    resize( roi1, Up1, Up1.size(), 0, 0, INTER_CUBIC );
    resize( roi2, Up2, Up2.size(), 0, 0, INTER_CUBIC );

    /// 前一半低通，后一半高通
    Mat dst1 = Mat::zeros( 1, D, src.type() );
    Mat dst2= Mat::zeros( 1, D, src.type() );
    filter2D( Up1, dst1, -1, lowFilter );
    filter2D( Up2, dst2, -1, highFilter );

    /// 结果相加
    dst1 = dst1 + dst2;

    return dst1;

}

void enhance( Mat &src){
    int n_r=src.rows/4;
    int n_c=src.rows/4;

    cv::Mat tmp_ll_2,tmp_hl_2,tmp_lh_2,tmp_hh_2;
    tmp_ll_2=src(cv::Range(0,n_r),cv::Range(0,n_c));//.copyTo(tmp_ll_2);
    tmp_lh_2=src(cv::Range(n_r,2*n_r),cv::Range(0,n_c));//.copyTo(tmp_lh_2);
    tmp_hl_2=src(cv::Range(0,n_r),cv::Range(n_c,n_c*2));//.copyTo(tmp_hl_2);
    tmp_hh_2=src(cv::Range(n_r,2*n_r),cv::Range(n_c,n_c*2));//.copyTo(tmp_hh_2);
    enhance_h_freq(tmp_ll_2);
    enhance_h_freq(tmp_lh_2);
    enhance_h_freq(tmp_hl_2);
    enhance_h_freq(tmp_hh_2);
}
void enhance_h_freq( Mat &src){
//    cv::Mat tmp=cv::Mat_<float>(src);
    float n=src.rows*src.cols;
    double min=0,max=0,k=1;
    cv::minMaxIdx(src,&min,&max);
    float T=(max+min)/2*std::sqrt(2*std::log(n));

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
