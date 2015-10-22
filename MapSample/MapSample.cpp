// MapSample.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
int _tmain(int argc, _TCHAR* argv[])
{
	std::map<std::string,std::string> map1;
	map1.insert(std::pair<std::string,std::string>("miaomiao1","苗苗"));
	map1.insert(std::pair<std::string,std::string>("miaomiao2","小苗苗"));
	map1.insert(std::pair<std::string,std::string>("miaomiao3","苗苗"));
	map1.insert(std::pair<std::string,std::string>("miaomiao4","中苗苗"));
	map1.insert(std::pair<std::string,std::string>("miaomiao5","苗苗"));
	map1.insert(std::pair<std::string,std::string>("miaomiao6","大苗苗"));

	std::map<std::string,std::string>::iterator it;
	for (it=map1.begin();it!=map1.end();++it)
	{
		std::cout<<it->first<<" "<<it->second<<std::endl;
	}
	std::cout<<map1["miaomiao2"]<<std::endl;
	return 0;
}

