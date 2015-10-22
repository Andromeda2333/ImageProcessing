#pragma once
#include <vector>
template<class T>
class Result{
public:
	Result();
	~Result();
	Result(const std::vector<T> vec1,const double maxValue1,const double minValue1);
	std::vector<T> GetVector()const;
	double GetMaxValue()const;
	double GetMinValue()const;
private:
	std::vector<T> vec;//�洢ÿ�����ݵ�f1/f2��ֵ
	double maxValue;//ÿ��������f1/f2�����ֵ
	double minValue;//ÿ��������f1/f2����Сֵ
};

template<class T>
Result<T>::Result( const std::vector<T> vec1,const double maxValue1,const double minValue1 )
{
	vec=vec1;
	maxValue=maxValue1;
	minValue=minValue1;
}

template<class T>
double Result<T>::GetMinValue() const
{
	return minValue;
}

template<class T>
double Result<T>::GetMaxValue() const
{
	return maxValue;
}

template<class T>
std::vector<T> Result<T>::GetVector() const
{
	return vec;
}

template<class T>
Result<T>::~Result()
{

}

template<class T>
Result<T>::Result()
{

}


