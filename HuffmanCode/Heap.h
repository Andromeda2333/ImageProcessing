#pragma once
#include "Node.h"
#include <vector>
#include <algorithm>
#include <iostream>
class Heap
{
public:
	Heap(std::vector<char>&keyValue,std::vector<int>&feqValue);
	~Heap(void);

	void HuffManCode();
private:
	void Show(Node* p,std::vector<int>res)const;
	void Build();
	void Print(std::vector<int> &vec)const;
	Node* head;
	std::vector<Node*> db;
};

