#include <QCoreApplication>
#include<iostream>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int x=0;
    for(int i=1;i<=100;++i){
        x=x+i;
    }
    std::cout<<x;
    return a.exec();
}
