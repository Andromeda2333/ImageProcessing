#include "stdafx.h"
#include "Node.h"



Node::Node( std::string const name )
{
	this->name=name;
	this->color=WHITE;
	this->parent=nullptr;
	this->d=-1;
}


Node::~Node(void)
{
}

