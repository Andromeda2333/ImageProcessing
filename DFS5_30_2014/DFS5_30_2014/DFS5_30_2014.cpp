// DFS5_30_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Node.h"
#include <iostream>

void DFS(std::vector<Node*> &vec);
void DFS_VIST(Node* u,int &t);

int _tmain(int argc, _TCHAR* argv[])
{
	//建立图的关系
	Node* u=new Node("u");Node* v=new Node("v");Node* w=new Node("w");
	Node* x=new Node("x");Node* y=new Node("y");Node* z=new Node("z");
	u->adj.push_back(v),u->adj.push_back(x);
	v->adj.push_back(y);
	w->adj.push_back(y),w->adj.push_back(z);
	x->adj.push_back(v);
	y->adj.push_back(x);
	z->adj.push_back(z);

	//所有节点存入vec中
	Node* nVec[6]={u,v,w,x,y,z};
	std::vector<Node*> vec(nVec,nVec+6);
	DFS(vec);

	for (size_t i=0;i<vec.size();++i)
	{
		std::cout<<vec[i]->name<<"    "<<vec[i]->d<<"  "<<vec[i]->f<<'\n';
	}

	return 0;
}

/************************************************************************/
/* 深度优先搜索                                                        */
/************************************************************************/
void DFS_VIST( Node* u ,int &t)
{
	Node* v;
	t++;
	u->d=t;
	u->color=Node::GRAY;

	for (size_t i=0;i<u->adj.size();++i)
	{
		v=u->adj[i];
		if (v->color==Node::WHITE)
		{
			v->parent=u;
			DFS_VIST(v,t);
		}
	}
	u->color=Node::BLACK;
	t++;
	u->f=t;
}

void DFS( std::vector<Node*> &vec )
{
	int t=0;

	for (size_t i=0;i<vec.size();++i)
	{
		if (vec[i]->color==Node::WHITE)
		{
			DFS_VIST(vec[i],t);
		}
	}
}

