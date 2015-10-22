#pragma once
#include <vector>
#include <string>
class Node
{
public:
	Node(std::string const name);
	~Node(void);

	enum Color
	{
		WHITE,GRAY,BLACK
	};

	std::string name;//节点名称
	std::vector<Node*> adj;//相连节点集
	Node* parent;//父节点

	Color color;//节点颜色
	int d;//开始被处理时间
	int f;//处理结束时间
};

