// DataIN.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <opencv2/core/core.hpp>//����opencv�ĺ��Ĳ���
#include <fstream>
#include <sstream>
#include <vector>
/*Ҫ��������ɲ������ݲ��Ҵ����ı��ļ���*/
/*1.��ô��������?rand()*/
/*2.��ô�洢����ofream*/
/*˼·�����ǶԵ�,ֻ֪������������*/
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

