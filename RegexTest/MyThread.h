#pragma once
class MyThread 
{
public:
	MyThread(int id,int numberIterator);
	~MyThread();

	void  operator()()const;
protected:
	int mId;
	int mNumberIterator;
};

