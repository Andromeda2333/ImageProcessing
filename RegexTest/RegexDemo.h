#pragma once
#include <regex>
#include <iostream>
#include <string>
#include <vector>
#include <ios>
#include <iomanip>
#include <istream>
#include <sstream>
#include <fstream>
#include <functional>
#include <ratio>
#include <chrono>
#include <time.h>
#include <iomanip>
#include <random>
#include <typeinfo>
#include <algorithm>
#include <numeric>
#include "Pointer.h"
class RegexDemo
{
public:
	RegexDemo();
	virtual ~RegexDemo();

	virtual void RegexMatchDemo()const;
	virtual void RegexSearchDemo()const;
	virtual void RegexIteratorDemo()const;
	virtual void RegexTokenIteratorDemo()const;
	virtual void RegexTokenIteratorDemo1()const;
	virtual void Test()const;
	virtual std::string ReadName(std::istream& inStream)const;
	virtual void StringStream()const;
	virtual void FileStreamDemo(int argc, std::string argv[])const;
	virtual void OutString()const;
	virtual void StreamTie()const;
	virtual int SumValue(int inLValue,int inRValue)const;
	virtual void RatioTest()const;
	virtual void DurationTest()const;
	virtual void ClockTest()const;
	virtual void RandNumber()const;
	virtual void TupleTest()const;
	virtual void IteratorTest()const;
	virtual void PointerTest()const;
};

