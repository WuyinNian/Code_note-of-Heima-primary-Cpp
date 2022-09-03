#include <iostream>
#include <string>
using namespace std;

//类模板做函数参数
template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        pName = name;
        pAge = age;
    }
    void showInfo()
    {
        cout << pName << endl;
        cout << pAge << endl;
    }
    NameType pName;
    AgeType pAge;
};

// 1.指定传入类型
void printPerson1(Person<string, int> &p)
{
    p.showInfo();
}
void test1()
{
    Person<string, int> p1("xjp", 23);
    printPerson1(p1);
}

// 2.参数模板化
template <class T1, class T2>
void printPerson2(Person<T1, T2> &p)
{
    p.showInfo();
    cout << "T1:" << typeid(T1).name() << endl;
    cout << "T2:" << typeid(T2).name() << endl;
}
void test2()
{
    Person<string, int> p2("aaa", 55);
    printPerson2(p2);
}

// 3.整个类模板化
template <class T>
void printPerson3(T &p)
{
    p.showInfo();
    cout << "T:" << typeid(T).name() << endl;
}
void test3()
{
    Person<string, int> p3("ccc", 999);
    printPerson3(p3);
}
int main(int argc, const char *argv[])
{
    test1();
    test2();
    test3();
    return 0;
}