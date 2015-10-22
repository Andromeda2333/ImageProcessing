#pragma once
class Node
{
public:
	Node(void);
	~Node(void);
	Node(int key,int cost);

	int GetKey()const{return this->key;};
	int GetCost()const{return this->cost;};
	Node* GetParent()const{return this->parent;};
	Node* GetChild()const{return this->child;};

	void SetKey(const int key){this->key=key;};
	void SetCost(const int cost){this->cost=cost;};
	void SetParent(Node* p){this->parent=p;};
	void SetChild(Node* p){this->child=p;}

private:
	int key;//�ڵ���
	int cost;//�õ㵽�����ڵ�Ļ���
	Node* parent; //���ڵ�
	Node* child;//���ӽڵ�
};

