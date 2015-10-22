// HuffmanCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Heap.h"
#include <vector>

int _tmain(int argc, _TCHAR* argv[])
{
	char a[8]={'a','b','c','d','e','f','g','h'};
	int b[8]={212,334,432,634,65,76,690,341};
	std::vector<char> keyValue(a,a+8);
	std::vector<int> freqValue(b,b+8);

	Heap* h=new Heap(keyValue,freqValue);
	h->HuffManCode();
	return 0;
}

