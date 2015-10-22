#include "stdafx.h"
#include "Node.h"


Node::Node( std::string const name )
{
	this->name=name;
	this->d=0;
	this->f=0;
	this->color=WHITE;
}


Node::~Node(void)
{
}
