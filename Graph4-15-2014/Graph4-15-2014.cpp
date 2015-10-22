// Graph4-15-2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<Node*> BuildDb();
Node* BuildList(const std::vector<int>& vecIndex,
				const std::vector<int>& vecCost);
void Print(Node *p);
std::pair<int,std::vector<int>> Fgraph(std::vector<Node*>db);
std::pair<int,int> MinDistance(std::vector<int>& cost,Node* p);
int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<Node*> db(BuildDb());
	std::pair<int,std::vector<int>> res(Fgraph(db));
	std::cout<<"the point 0 to 9 :"<<std::endl<<"route: "<<res.first
		<<std::endl<<"path:"<<'\t';
	std::for_each(res.second.begin(),res.second.end(),[](int n)
	{
		std::cout<<n<<'\t';
	});
	std::cout<<std::endl;
	return 0;
}

/*用节点构造多段图**/
std::vector<Node*> BuildDb()
{
	std::vector<Node*> tempDb;//存放每个链表的表头
	std::vector<int>* index,*cost;

	//节点0和它的邻接点1,2,3组成的链表
	int ind1[4]={0,1,2,3};
	int cost1[4]={0,4,1,3};
	index=new std::vector<int>(ind1,ind1+4);
	cost=new std::vector<int>(cost1,cost1+4);
	tempDb.push_back(BuildList(*index,*cost));//表头放入tempDb中
	delete index,delete cost;
	//Print(tempDb[0]);

	//节点1和它的邻接点4,5组成的链表
	int ind2[3]={1,4,5};
	int cost2[3]={0,9,8};
	index=new std::vector<int>(ind2,ind2+3);
	cost=new std::vector<int>(cost2,cost2+3);
	tempDb.push_back(BuildList(*index,*cost));//表头放入tempDb中
	delete index,delete cost;
	//Print(tempDb[1]);

	//和前面类似
	int ind3[5]={2,3,4,5,6};
	int cost3[5]={0,1,6,7,8};
	index=new std::vector<int>(ind3,ind3+5);
	cost=new std::vector<int>(cost3,cost3+5);
	tempDb.push_back(BuildList(*index,*cost));
	delete index,delete cost;

	//和前面类似
	int ind4[3]={3,5,6};
	int cost4[3]={0,4,7};
	index=new std::vector<int>(ind4,ind4+3);
	cost=new std::vector<int>(cost4,cost4+3);
	tempDb.push_back(BuildList(*index,*cost));
	delete index,delete cost;

	//和前面类似
	int ind5[3]={4,7,8};
	int cost5[3]={0,5,6};
	index=new std::vector<int>(ind5,ind5+3);
	cost=new std::vector<int>(cost5,cost5+3);
	tempDb.push_back(BuildList(*index,*cost));
	delete index,delete cost;

	//和前面类似
	int ind6[3]={5,7,8};
	int cost6[3]={0,8,6};
	index=new std::vector<int>(ind6,ind6+3);
	cost=new std::vector<int>(cost6,cost6+3);
	tempDb.push_back(BuildList(*index,*cost));
	delete index,delete cost;

	//和前面类似
	int ind7[3]={6,7,8};
	int cost7[3]={0,6,5};
	index=new std::vector<int>(ind7,ind7+3);
	cost=new std::vector<int>(cost7,cost7+3);
	tempDb.push_back(BuildList(*index,*cost));
	delete index,delete cost;

	//和前面类似
	int ind8[2]={7,9};
	int cost8[2]={0,7};
	index=new std::vector<int>(ind8,ind8+2);
	cost=new std::vector<int>(cost8,cost8+2);
	tempDb.push_back(BuildList(*index,*cost));
	delete index,delete cost;

	//和前面类似
	int ind9[2]={8,9};
	int cost9[2]={0,3};
	index=new std::vector<int>(ind9,ind9+2);
	cost=new std::vector<int>(cost9,cost9+2);
	tempDb.push_back(BuildList(*index,*cost));
	delete index,delete cost;
	return tempDb;
}

/*以一个节点为起点和它的所有邻接点构建链表**/
Node* BuildList( const std::vector<int>& vecIndex, const std::vector<int>& vecCost )
{
	Node* head;
	head=new Node(vecIndex[0],vecCost[0]);
	Node* tail=head;
	Node* temp=nullptr;
	for (int i=1;i<vecIndex.size();++i)
	{
		temp=new Node(vecIndex[i],vecCost[i]);
		tail->SetChild(temp);
		temp->SetParent(tail);
		tail=temp;
	}
	return head;
}

/*输出没个链表的内容**/
void Print( Node *p )
{
	Node* temp=p;
	while (temp->GetChild()!=nullptr)
	{
		std::cout<<temp->GetKey()<<'\t'<<temp->GetCost()<<'\n';
		temp=temp->GetChild();
	}
	std::cout<<temp->GetKey()<<'\t'<<temp->GetCost()<<'\n';
}

/*求解多段图中起点和终点的最短路径**/
std::pair<int,std::vector<int>> Fgraph( std::vector<Node*>db )
{
	std::vector<int> cost(db.size()+1);//各节点到终点的花费

	//初始化cost
	std::generate(cost.begin(),cost.end()-1,[](){return 1000;});
	cost[cost.size()-1]=0;

	//path[i]存放的是i到终点的最短路径上,i的前一个节点
	std::vector<int> path(db.size()+1,-1);//初始化path

	//求解最优cost和path
	for (int i=cost.size()-2;i>-1;--i)
	{
		std::pair<int,int> temp=MinDistance(cost,db[i]);
		cost[i]=temp.first;
		path[i]=temp.second;
	}
	
	//求解起点到终点的最短路径
	std::vector<int> route(1,0);
	int i=0;
	while (path[i]!=-1)
	{
		i=path[i];
		route.push_back(i);
	}

	//返回最短距离及其路径
	return std::pair<int,std::vector<int>>(cost[0],route);
}

/*求解任意给定点到终点的最短距离**/
std::pair<int,int> MinDistance( std::vector<int>& cost,Node* p )
{
	std::vector<std::pair<int,int>> tempCost;

	//c(i,j)+cost(j)
	do
	{
		p=p->GetChild();
		int c=p->GetCost();
		int j=p->GetKey();
		tempCost.push_back(std::pair<int,int>(c+cost[j],j));
	}while (p->GetChild()!=nullptr);

	//min(c(i,j)+cost(j)),i<=i<n
	auto it=std::min_element(tempCost.begin(),tempCost.end(),
		[](std::pair<int,int>& i,std::pair<int,int>& j)
	{
		return i.first<j.first;
	});
	return *it;	
}

