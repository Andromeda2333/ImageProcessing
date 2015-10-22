// ResourceAllocat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include "Solver.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int g1[]={0,4,26,40,45,50,51,52,53};
	int g2[]={0,5,15,40,60,70,73,74,75};
	int g3[]={0,5,15,40,80,90,95,98,100};

	std::vector<std::vector<int>> db;
	db.push_back(std::vector<int>(g1,g1+9));
	db.push_back(std::vector<int>(g2,g2+9));
	db.push_back(std::vector<int>(g3,g3+9));
	Solver s(db);
	s.Show();
	return 0;
}

