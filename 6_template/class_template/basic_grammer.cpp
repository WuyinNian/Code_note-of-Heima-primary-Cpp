#include <iostream>
using namespace std;

template <class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        pName = name;
        pAge = age;
    }
    NameType pName;
    AgeType pAge;
};
void test1()
{
    Person<string, int> p1("xjp", 23);
}
//类模板和函数模板的区别
// 1.类模板没有自动类型推导的使用方式
// 2.类模板在模板参数列表中可以有默认参数
void test2()
{
    Person<string> p1("jjj", 99);
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}