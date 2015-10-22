#include "stdafx.h"
#include "MyThread.h"
#include <iostream>

using namespace std;
MyThread::MyThread(int id, int numberIterator) :mId(id), mNumberIterator(numberIterator)
{

}


MyThread::~MyThread()
{
}

void MyThread::operator()() const
{
	for (int i = 0; i < mNumberIterator;++i)
	{
		cout << "MyThread " << mId << " has value ";
		cout << i << endl;
	}
}
