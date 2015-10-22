#include <QCoreApplication>
#include"a.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    A* p=new A(2,3);
    p->show();
    p->show();

    return a.exec();
}
