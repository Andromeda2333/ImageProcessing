#include <iostream>
#include<sstream>
using namespace std;

struct Score{
    double math;
    double english;
    string toString(){
        string str,tmp;
        stringstream s;
        s<<this->math;
        s>>tmp;
        s.clear();
        str="math="+tmp+"   ";

        s<<this->english;
        s>>tmp;
        str+="english="+tmp;
        return str;
    }
};

struct Student{
    int id;
    string name;
    struct Score s;
};

int main()
{
    struct Student s={21,"zhangsan",{56,79}};
    int a=2131;
    char* str;
    itoa(a,str,2);
    cout<<str<<endl;
    cout << s.id << endl;

    double d=45.56465746;
    stringstream sstr;
    sstr<<d;
    sstr>>str;
    cout<<str<<endl;

    cout<<s.s.toString()<<endl;
    return 0;
}

