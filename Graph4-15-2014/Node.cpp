#include "stdafx.h"
#include "Node.h"


Node::Node(void)
{
	this->key=-1;
	this->cost=-1;
	this->parent=nullptr;
	this->child=nullptr;
}

Node::Node( int key,int cost )
{
	this->key=key;
	this->cost=cost;
	this->parent=nullptr;
	this->child=nullptr;
}


Node::~Node(void)
{
}
