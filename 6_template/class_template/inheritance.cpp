#include <iostream>
#include <string>
using namespace std;

//类模板与继承
template <class T>
class Base
{
public:
    T m;
};

class Son : public Base<int> //必须知道父类的T类型才能继承给子类
{
};

//如果想灵活指定父亲中的T类型，子类也需要变为模板
template <class T1, class T2>
class Son2 : public Base<T2>
{
public:
    T1 objl
};

int main(int argc, const char *argv[])
{

    return 0;
}