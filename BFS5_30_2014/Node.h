#pragma once
#include <string>
#include <vector>

/************************************************************************/
/* ͼ�Ľڵ�                                                             */
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
	std::string name;//�ڵ�����
	std::vector<Node*> adj;//��ڵ������������ڵ�
	Node* parent;//�ڵ�ĸ��ڵ�
	NodeColor color;//�ڵ���ɫ
	int d;//�ڵ�����ʼ�ڵ�ľ���

};

