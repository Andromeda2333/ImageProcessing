#pragma once
#include <vector>
#include<iostream>
#include <algorithm>
class Solver
{
public:
	Solver(void);
	Solver(std::vector<std::vector<int>>db):db(db){};
	~Solver(void);

	void Show();
private:
	std::vector<std::vector<int>>db;
	std::vector<std::vector<int>>fDb;
	std::vector<std::vector<int>> dDb;
	std::vector<int> gDb;
	std::vector<int> qDb;

	void Generatefd();
	void Generategq();
	std::pair<int,std::vector<int>> Comput();
};

