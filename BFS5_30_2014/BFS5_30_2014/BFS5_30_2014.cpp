// BFS5_30_2014.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <iostream>
#include "Node.h"

void BFS(Node* s );
void ShowPath(const Node* s,const Node* v);

int _tmain(int argc, _TCHAR* argv[])
{
	//建立图的各个节点以及节点之间的关系
	Node* r=new Node("r");Node* s=new Node("s");Node* t=new Node("t");
	Node* u=new Node("u");Node* v=new Node("v");Node* w=new Node("w");
	Node* x=new Node("x");Node* y=new Node("y");
	r->adj.push_back(s);r->adj.push_back(v);
	s->adj.push_back(w);s->adj.push_back(r);
	t->adj.push_back(w);t->adj.push_back(x);t->adj.push_back(u);
	u->adj.push_back(t);u->adj.push_back(x);u->adj.push_back(y);
	v->adj.push_back(r);
	w->adj.push_back(s);w->adj.push_back(t);w->adj.push_back(x);
	x->adj.push_back(w);x->adj.push_back(t);x->adj.push_back(u);x->adj.push_back(y);
	y->adj.push_back(x);y->adj.push_back(u);
	BFS(s);
	ShowPath(s,u);

	return 0;
}

/*广度优先搜索**/
void BFS(Node* s )
{
	Node* u;
	Node* v;

	std::queue<Node*> Q;
	Q.push(s);

	while (!Q.empty())
	{
		u=Q.front();
		Q.pop();

		for (int i=0;i<u->adj.size();++i)
		{
			v=u->adj[i];
			if (v->color==Node::WHITE)
			{
				v->color=Node::GRAY;
				v->d=u->d+1;
				v->parent=u;
				Q.push(v);
			}
		}
		u->color=Node::BLACK;
	}

}


/*输出从点s到点v的路径**/
void ShowPath( const Node* s,const Node* v )
{
	if (s->name==v->name)
	{
		std::cout<<s->name<<std::endl;
	}
	else if (v->parent==nullptr)
	{
		std::cout<<"no path from "<<s->name<<" to "<<v->name<<std::endl;
	} 
	else
	{
		ShowPath(s,v->parent);
		std::cout<<v->name<<std::endl;
	}

}

