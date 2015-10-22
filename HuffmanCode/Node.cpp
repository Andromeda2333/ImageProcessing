#include "stdafx.h"
#include "Node.h"


Node::Node(void)
{
	this->fValue=-1;
	this->key=NULL;
	this->lch=nullptr;
	this->rch=nullptr;
	this->parent=nullptr;
}

Node::Node( char key,int freq,Node* parent/*=nullptr*/,Node* lch/*=nullptr*/,Node* rch/*=nullptr*/ )
{
	this->key=key;
	this->fValue=freq;
	this->parent=parent;
	this->lch=lch;
	this->rch=rch;
}


Node::~Node(void)
{
}

void Node::SetParent( Node* pN )
{
	this->parent=pN;
}

void Node::SetLch( Node* pN )
{
	this->lch=pN;
}

void Node::SetRch( Node* pN )
{
	this->rch=pN;
}

void Node::SetKey( char key )
{
	this->key=key;
}

void Node::SetFreq( int value )
{
	this->fValue=value;
}
