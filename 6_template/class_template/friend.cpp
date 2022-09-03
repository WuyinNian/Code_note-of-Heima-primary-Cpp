#include <iostream>
#include <string>
using namespace std;

//前置声明Perso类
template <class T1, class T2>
class Person;

//全局函数类外实现
template <class T1, class T2>
void showInfo2(Person<T1, T2> p)
{
    cout << "global func out class" << endl;
    cout << "name:" << p.pName << endl;
    cout << "age:" << p.pAge << endl;
}

template <class T1, class T2>
class Person
{
    //全局函数，类内实现
    friend void showInfo(Person<T1, T2> p)
    {
        cout << "in class" << endl;
        cout << "name:" << p.pName << endl;
        cout << "age:" << p.pAge << endl;
    }

    //全局函数，类外实现
    //需要加一个空模板参数列表,因为定义是模板函数，所以声明也要是模板函数
    friend void showInfo2<>(Person<T1, T2> p);

public:
    Person(T1 name, T2 age)
    {
        pName = name;
        pAge = age;
    }

private:
    T1 pName;
    T2 pAge;
};

void test1()
{
    Person<string, int> p("tom", 20);
    showInfo(p);
    showInfo2(p);
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}