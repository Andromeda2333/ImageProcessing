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
	std::vector<T> vec;//存储每组数据的f1/f2的值
	double maxValue;//每组数据中f1/f2的最大值
	double minValue;//每组数据中f1/f2的最小值
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


