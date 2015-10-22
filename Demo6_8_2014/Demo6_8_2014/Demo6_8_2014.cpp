// Demo6_8_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
void Show(int** p)
{
	for (int i=0;i<2;++i)
		for (int j=0;j<2;++j)
			cout<<p[i][j]<<'\t';
	cout<<'\n';
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[2][2]={1,1,46,4};
	int** p=(int**)a;
	for (int i=0;i<4;++i)
		cout<<p[i]<<'\t';
	cout<<'\n';
	cout<<**p;
	return 0;
}
