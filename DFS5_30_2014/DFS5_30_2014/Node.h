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

	std::string name;//�ڵ�����
	std::vector<Node*> adj;//�����ڵ㼯
	Node* parent;//���ڵ�

	Color color;//�ڵ���ɫ
	int d;//��ʼ������ʱ��
	int f;//�������ʱ��
};

