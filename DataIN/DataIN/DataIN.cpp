// DataIN.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>//这是opencv的核心部分
#include <fstream>
#include <sstream>
#include <vector>
/*要求随机生成部分数据并且存于文本文件中*/
/*1.怎么生成数据?rand()*/
/*2.怎么存储数据ofream*/
/*思路大致是对的,只知道这两个函数*/
int _tmain(int argc, _TCHAR* argv[])
{
	cv::RNG rng(100);
	std::fstream fileOut;
	fileOut.open("date.txt",std::ios_base::out);
	if (!fileOut.is_open())
	{
		std::cout<<"Error!!"<<std::endl;
		return 0;
	}
	
	
	std::string str;


	int flag=0;
	for (int i=0;i<1000;++i)
	{
		std::ostringstream strOut;
		strOut<<rng.uniform(0,1000);
		str=strOut.str()+std::string("\t");
		strOut.clear();
		fileOut.write(str.c_str(),str.size());
		
		if (++flag==10)
		{
			fileOut.write("\n",1);
			flag=0;
		}
	}

	fileOut.close();
	//return 0;
	std::ifstream readIn;
	readIn.open("date.txt");
	if (!readIn)
	{
		std::cout<<"Success!!!"<<std::endl;
	}

	while (std::getline(readIn,str))
	{
		std::cout<<str<<std::endl;
	}
	return 0;
}

