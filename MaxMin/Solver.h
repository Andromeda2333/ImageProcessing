#pragma once
#include <vector>
#include <map>
using std::vector;
class Solver
{
public:
	Solver(void);
	~Solver(void);
	virtual void MaxMin(const vector<int> &iVec,int low,int high,int &eMax,int &eMin)const;
	virtual void OutPut(const vector<int> &iVec);
	virtual std::vector<std::vector<int>> Slice(int sliceNum);
private:
	virtual std::vector<int> Connect(const std::vector<int>&vec1,const std::vector<int>&vec2);
};

