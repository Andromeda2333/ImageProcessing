#include "stdafx.h"
#include "Finder.h"


Finder::Finder(void)
{
}


Finder::~Finder(void)
{
}

void Finder::ReadFile( std::ifstream& is )
{
	StoreFile(is);
	BuildMap();
}

void Finder::StoreFile( std::ifstream& inStrream )
{
	std::string text;
	while (std::getline(inStrream,text));
	{
		lineOfText.push_back(text);
		std::cout<<text<<std::endl;
	}
}

void Finder::BuildMap()
{
	for (int i=0;i!=lineOfText.size();++i)
	{
		std::istringstream lineValue(lineOfText.at(i));
		std::string word;
		while (lineValue>>word)
		{
			wordMap[word].insert(i);
		}
	}
}

std::set<int> Finder::RunQuery( const std::string& str ) const
{
	std::map<std::string,std::set<int>>::const_iterator loc
		=wordMap.find(str);
	if (loc==wordMap.cend())
	{
		return std::set<int>();
	}
	else
	{
		return loc->second;
	}

}

std::string Finder::TextLine( int lineIndex ) const
{
	if (lineIndex<lineOfText.size())
	{
		return lineOfText.at(lineIndex);
	}
	return NULL;
}
