#include "stdafx.h"
#include "Solver.h"
#include <iostream>
#include <vector>

using namespace std;


Solver::Solver(void)
{
}


Solver::~Solver(void)
{
}

void Solver::MaxMin( const vector<int> &iVec,int low,int high,int &eMax,int &eMin )const
{
	if(high-low<=1){
		if(iVec.at(low)>iVec.at(high)){
			eMax=iVec.at(low);
			eMin=iVec.at(high);
		}else{
			eMax=iVec.at(high);
			eMin=iVec.at(low);
		}
	}else{
		/*若元素个数>3个,则运用分治法把原数组从中间一分为二分别自调用,直到数组中元素个数少于3 */
		int mid=(low+high)/2;
		int tempMaxL,tempMinL,
			tempMaxR,tempMinR;

		MaxMin(iVec,low,mid,tempMaxL,tempMinL);
		MaxMin(iVec,mid,high,tempMaxR,tempMinR);

		if(tempMinL<tempMinR)
			eMin=tempMinL;
		else
			eMin=tempMinR;

		if(tempMaxL<tempMaxR)
			eMax=tempMaxR;
		else
			eMax=tempMaxL;


	}
}

void Solver::OutPut( const vector<int> &iVec )
{
	for (vector<int>::const_iterator it=iVec.begin();it!=iVec.end();++it)
	{
		cout<<*it<<"\t";
	}
	cout<<endl;

}

std::vector<std::vector<int>> Solver::Slice( int sliceNum )
{
	/*最小子问题规模为1,该问题也是递归终止条件*/
	static std::map<int,vector<vector<int>>> localMap;
	for (int i=1;i<=sliceNum;++i)
	{
		vector<vector<int>> localList;
		localList.push_back(vector<int>(i,-1));
		
		localMap[i]=localList;
	}

	if (sliceNum==1)
	{
		if (localMap.at(1).at(0).at(0)==-1)
		{
			localMap.at(1).at(0).at(0)=1;
		}
		return localMap[1];
	}

	if (localMap.at(sliceNum).at(0).at(0)!=-1)
	{
		return localMap.at(sliceNum);
	}

	std::vector<std::vector<int>> result;
	std::vector<int> tempVec;
	tempVec.push_back(sliceNum);
	result.push_back(tempVec);

	for (int leftDiv=1;leftDiv<=sliceNum/2;++leftDiv)
	{
	
	int rightDiv=sliceNum-leftDiv;
	std::vector<std::vector<int>> leftRes;
	std::vector<std::vector<int>> rightRes;
	if (localMap[leftDiv].at(0).at(0)==-1)
	{
		leftRes=Slice(leftDiv);
	}else{
		leftRes=localMap.at(leftDiv);
	}

	if (localMap[rightDiv].at(0).at(0)==-1)
	{
		rightRes=Slice(rightDiv);
	}else{
		rightRes=localMap.at(rightDiv);
	}
	

	for (int i=0;i<leftRes.size();++i)
	{
		for (int j=0;j<rightRes.size();++j)
		{
			result.push_back(Connect(leftRes.at(i),rightRes.at(j)));
		}
	}
	}
	localMap[sliceNum]=result;
	return result;
}

std::vector<int> Solver::Connect( const std::vector<int>&vec1,const std::vector<int>&vec2 )
{
	std::vector<int> tempVec(vec1);
	for (int i=0;i<vec2.size();++i)
	{
		tempVec.push_back(vec2.at(i));
	}
	return tempVec;
}
