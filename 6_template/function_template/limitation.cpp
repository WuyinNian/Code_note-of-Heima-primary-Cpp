#include <iostream>
#include <fstream>
using namespace std;

//模板的局限性
//模板不是万能的，有些特定的数据类型，需要具体化方式做特殊实现
template <class T>
bool f(T &a, T &b)
{
    return a == b;
}
class Person
{
public:
    int pAge;
    Person(int age)
    {
        pAge = age;
    }
};

void test1()
{
    int a = 1, b = 2;
    bool flag = f(a, b);
    if (flag)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

//具体化Person版本代码实现，具体化优先调用
template <>
bool f(Person &a, Person &b)
{
    if (a.pAge == b.pAge)
        return 1;
    else
        return 0;
}
void test2()
{
    Person p1(20);
    Person p2(20);
    bool flag = f(p1, p2);
    if (flag)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}
int main(int argc, const char *argv[])
{
    test2();
    return 0;
}