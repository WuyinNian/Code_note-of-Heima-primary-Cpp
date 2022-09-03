#include <iostream>
#include <string>
using namespace std;

class Person1
{
public:
    void show1()
    {
        cout << "Person1" << endl;
    }
};
class Person2
{
public:
    void show2()
    {
        cout << "Person2" << endl;
    }
};
template <class T>
class MyClass
{
public:
    T obj;
    void func1()
    {
        obj.show1();
    }
    void func2()
    {
        obj.show2();
    }
};
void test1()
{
    MyClass<Person1> m;
    m.func1();
    // m.func2();//函数调用才会去创建成员函数
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}