// MapSample.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
int _tmain(int argc, _TCHAR* argv[])
{
	std::map<std::string,std::string> map1;
	map1.insert(std::pair<std::string,std::string>("miaomiao1","����"));
	map1.insert(std::pair<std::string,std::string>("miaomiao2","С����"));
	map1.insert(std::pair<std::string,std::string>("miaomiao3","����"));
	map1.insert(std::pair<std::string,std::string>("miaomiao4","������"));
	map1.insert(std::pair<std::string,std::string>("miaomiao5","����"));
	map1.insert(std::pair<std::string,std::string>("miaomiao6","������"));

	std::map<std::string,std::string>::iterator it;
	for (it=map1.begin();it!=map1.end();++it)
	{
		std::cout<<it->first<<" "<<it->second<<std::endl;
	}
	std::cout<<map1["miaomiao2"]<<std::endl;
	return 0;
}

