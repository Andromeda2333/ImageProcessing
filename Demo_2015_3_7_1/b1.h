#ifndef B1_H
#define B1_H
#include<iostream>
class B1
{
public:
    B1(int a){
        std::cout<<"B1::construct  "<<a<<std::endl;
    }
    void show(){
        std::cout<<"B1::show()"<<std::endl;
    }
};
class B2{
public:
    B2(int b){
        std::cout<<"B2::construct   "<<b<<std::endl;
    }
    void show(){
        std::cout<<"B2::show()"<<std::endl;
    }
};

#endif // B1_h


