// RegexTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "RegexDemo.h"
#include <iostream>
#include <string>
#include <functional>
#include <limits>
#include <thread>
#include "MyThread.h"
#include <exception>

void Sum(int value1,int value2){
	for (int i = 0; i < value2;++i)
	{
		std::cout << "id=" << value1;
		std::cout << " has value " << i << std::endl;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	RegexDemo r;
	/*r.Test();*/
	//r.RegexMatchDemo();
	//r.RegexSearchDemo();
	//r.RegexIteratorDemo();
	//r.RegexTokenIteratorDemo();
	//r.RegexTokenIteratorDemo1();
	/*r.StringStream();*/
	//std::string arr[2] = {"hello","world!"};
	//r.FileStreamDemo(2,arr);
	/*r.OutString();*/
	/*r.StreamTie();*/
	//std::function<int(int, int)> f1 = RegexDemo::SumValue;
	//std::cout << f1(13, 12) << std::endl;
	/*r.DurationTest();*/
	/*r.ClockTest();*/
	/*r.RandNumber();*/
	/*r.IteratorTest();*/
	//std::cout <<"int " <<std::numeric_limits<int>::max() 
	//	<< "  "<<std::numeric_limits<int>::min() << std::endl;
	//std::cout << "long " << std::numeric_limits<long>::max() 
	//	<< "  " << std::numeric_limits<long>::min() << std::endl;
	//std::cout << "double " << std::numeric_limits<double>::max()
	//	<< "  " << std::numeric_limits<double>::min() << std::endl;
	//std::cout << "float " << std::numeric_limits<float>::max()
	//	<< "  " << std::numeric_limits<float>::min() << std::endl;
	/*std::cout.sync_with_stdio(true);
	std::thread t1{MyThread(1,123)};
	MyThread mth(2,13);
	std::thread t2(mth);
	std::thread t3(MyThread(3,132));

	std::thread t4{ [](int mId, int mNumberIterator)
	{for (int i = 0; i < mNumberIterator; ++i)
		{
		std::cout << "MyThread " << mId << " has value ";
		std::cout << i << std::endl;
		}
	},4,230
	};
	t1.join();
	t2.join();
	t3.join();
	t4.join();*/
	std::thread t1(Sum,1,23);
	std::thread t2(Sum, 2, 33);
	t1.join();
	t2.join();
	return 0;
}

