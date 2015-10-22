// Pollard.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

int Ecliud(int m,int n);//求最大公约数
void PollardInt(int value);  //求value的因子
 


int _tmain(int argc, _TCHAR* argv[])
{
	cout<<Ecliud(3,9)<<endl;
    PollardInt(111);
	cout<<(7^2)<<endl;
	return 0;
}

int Ecliud(int m,int n )
{
	int r;
	do 
	{
		r=m%n;
		m=n;n=r;
	
	} while (r);
	
	return m;
}

void PollardInt( int value )  
{
	srand(unsigned(time(0)));
	int x=rand()%(value-1)+1;
	int i=1,k=2;
	int y;
	y=x;
	while (true)
	{
		i++;
		x=(x*x-1)%value;

		int fac=Ecliud(value,x-y);
		if (fac>1&&fac<value){
			cout<<fac<<endl;
			break;
		}
		else if (i==k)
		{
			y=x;
			k=2*k;
		}
	}


}

