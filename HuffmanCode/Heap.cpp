#include "stdafx.h"
#include "Heap.h"


Heap::Heap( std::vector<char>&keyValue,std::vector<int>&feqValue )
{
	for (size_t i=0;i<keyValue.size();++i)
	{
		db.push_back(new Node(keyValue.at(i),feqValue.at(i)));
	}
	this->head=nullptr;
}


Heap::~Heap(void)
{
}

bool Compare( Node* lhs,Node* rhs )
{
	return lhs->GetFreq()>=rhs->GetFreq();
}

void Heap::Build()
{
	while (db.size()>1)
	{
		std::sort(db.begin(),db.end(),Compare);

		//for (int i=0;i<db.size();++i)
		//{
		//	std::cout<<db[i]->GetKey()<<'\t'<<db[i]->GetFreq()<<std::endl;
		//}
		//std::cout<<"*************"<<std::endl;
		int times=db.size();

		int ferq=db.at(times-1)->GetFreq()+db.at(times-2)->GetFreq();

		head=new Node('h',ferq);
		head->SetLch(db[times-1]);
		head->SetRch(db[times-2]);
		db[times-1]->SetParent(head);
		db[times-2]->SetParent(head);

		db.pop_back();
		db.pop_back();
		db.push_back(head);
	}
}

void Heap::Print(std::vector<int> &vec) const
{
	for (int i=0;i<vec.size();++i)
	{
		std::cout<<vec.at(i)<<'\t';
	}
	std::cout<<std::endl;
}

void Heap::Show( Node* p,std::vector<int>res ) const
{
	if (p->GetLch()!=nullptr)
	{
		std::vector<int> temp(res);
		temp.push_back(0);
		Show(p->GetLch(),temp);
	}
	if (p->GetRch()!=nullptr)
	{
		std::vector<int> temp(res);
		temp.push_back(1);
		Show(p->GetRch(),temp);
	}
	if (p->GetLch()==nullptr||p->GetRch()==nullptr)
	{
		std::cout<<p->GetKey()<<":";
		Print(res);
	}
}

void Heap::HuffManCode()
{
	this->Build();
	//std::cout<<head->GetFreq()<<std::endl;
	std::vector<int> res;
	Show(this->head,res);
}