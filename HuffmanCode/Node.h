#pragma once
class Node
{
public:
	Node(void);
	~Node(void);

	Node(char key,int freq,Node* parent=nullptr,Node* lch=nullptr,Node* rch=nullptr);

	Node* GetParent()const
	{
		return this->parent;
	};

	Node*GetLch()const
	{
		return this->lch;
	};
	Node* GetRch()const
	{
		return this->rch;
	}

	char GetKey()const
	{
		return this->key;
	}
	int GetFreq()const
	{
		return fValue;
	}

	void SetParent(Node* pN);
	void SetLch(Node* pN);
	void SetRch(Node* pN);
	void SetKey(char key);
	void SetFreq(int value);
private:
	Node* parent;
	Node* lch;
	Node* rch;

	char key;
	int fValue;
};

