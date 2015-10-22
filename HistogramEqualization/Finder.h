#pragma once
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
class Finder
{
public:
	Finder(void);
	~Finder(void);

	std::string TextLine(int lineIndex)const;
	std::set<int> RunQuery(const std::string& str)const;
	void ReadFile(std::ifstream& is);
private:
	void StoreFile(std::ifstream& inStrream);
	void BuildMap();

	std::vector<std::string> lineOfText;
	std::map<std::string,std::set<int>> wordMap;
};

