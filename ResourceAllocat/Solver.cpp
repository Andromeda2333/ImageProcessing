#include "stdafx.h"
#include "Solver.h"


Solver::Solver(void)
{
}


Solver::~Solver(void)
{
}

void Solver::Generatefd()
{
	//�γɸ���f(i)��d(i)
	std::vector<int> f(db.at(0));
	std::vector<int> d(f.size(),0);
	int temp=0;
	std::generate(d.begin(),d.end(),[&](){return temp++;});
	fDb.push_back(f),dDb.push_back(d);

	for (int tag=1;tag<db.size();++tag)
	{
		std::vector<int> f1,d1;
		for (int x=0;x<f.size();++x)
		{
			temp=0;
			int maxZ=0;
			for (int z=0;z<=x;++z)
			{
				if (temp<fDb[tag-1][x-z]+db[tag][z])
				{
					temp=fDb[tag-1][x-z]+db[tag][z];
					maxZ=z;
				}
			}
			f1.push_back(temp);
			d1.push_back(maxZ);
		}

		fDb.push_back(f1);
		dDb.push_back(d1);
	}
}

void Solver::Generategq()
{
	//�γɸ���g(i)��q(i)
	for (int i=0;i<fDb.size();++i)
	{
		auto it=std::max_element(fDb[i].begin(),fDb[i].end());
		gDb.push_back(*it);
		qDb.push_back(it-fDb[i].begin());
	}
}

std::pair<int,std::vector<int>> Solver::Comput()
{
	//�����ѷ���
	auto it=max_element(gDb.begin(),gDb.end());
	int maxVal=*it;//���з��䷽����,�������ֵ
	int k=it-gDb.begin();//�������ʱ,���䵽��Ȼ����Ŀ����k+1

	auto it1=std::find(fDb[k].begin(),fDb[k].end(),maxVal);
	int optx=it1-fDb[k].begin();

	std::vector<int> res(k+1,0);
	for (int i=k;i>-1;--i)
	{
		res[i]=dDb[i][optx];
		optx-=res[i];
	}
	return std::pair<int,std::vector<int>>(maxVal,res);
}

void Solver::Show()
{
	//�������
	this->Generatefd();
	this->Generategq();
	std::pair<int,std::vector<int>> res=this->Comput();
	std::cout<<"�������Ϊ: "<<res.first<<std::endl;
	std::cout<<"��Դ���䷽��Ϊ:\n";

	for (int i=0;i<res.second.size();++i)
	{
		std::cout<<"�� "<<i+1<<" ����Ŀռ����ԴΪ: "<<res.second.at(i)<<std::endl;
	}
}
