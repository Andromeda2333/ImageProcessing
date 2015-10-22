#ifndef A_H
#define A_H
#include"b1.h"

class A:public B1,public B2
{
public:
    A(int x, int y);
    ~A();

    void show();
};

#endif // A_H
