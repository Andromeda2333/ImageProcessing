#pragma once
#include <string>
#include <vector>

/************************************************************************/
/* 图的节点                                                             */
/************************************************************************/
class Node
{
public:
	Node(std::string const name);
	~Node(void);
	static enum NodeColor
	{
		WHITE,GRAY,BLACK
	};
	std::string name;//节点名称
	std::vector<Node*> adj;//与节点相连的其他节点
	Node* parent;//节点的父节点
	NodeColor color;//节点颜色
	int d;//节点与起始节点的距离

};

