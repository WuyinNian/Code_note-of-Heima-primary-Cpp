#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age);

    T1 pName;
    T2 pAge;

    void showInfo();
};
template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    pName = name;
    pAge = age;
}

template <class T1, class T2>
void Person<T1, T2>::showInfo()
{
    cout<<"member function in outclass!"<<endl;
}

void test()
{
    Person<string,int>p("xjp",23);
    p.showInfo();
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}