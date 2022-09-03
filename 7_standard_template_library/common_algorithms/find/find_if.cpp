#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

class GreatFive
{
public:
    bool operator()(int v)
    {
        return v > 5;
    }
};
void test()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    v.push_back(35);
    v.push_back(87);
    v.push_back(44);
    v.push_back(22);
    // find_if,返回指定元素迭代器，找不到返回结束迭代器
    vector<int>::iterator it;
    it = find_if(v.begin(), v.end(), GreatFive());
    cout << *it << endl;
}

class Person
{
public:
    string name;
    int age;
    Person(string n, int a)
    {
        name = n;
        age = a;
    }
    //重载==号，让底层知道如何对比Person
    bool operator==(const Person &p) //需要const
    {
        if (name == p.name && age == p.age)
            return 1;
        else
            return 0;
    }
};
class Greater3
{
public:
    bool operator()(Person &p)
    {
        return p.age > 3;
    }
};
//自定义数据类型
void test2()
{
    vector<Person> v;
    Person p1("aaa", 1);
    Person p2("bbb", 2);
    Person p3("ccc", 3);
    Person p4("ddd", 4);
    Person p5("ddd", 4);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    vector<Person>::iterator it;
    it = find_if(v.begin(), v.end(), Greater3());
    if (it == v.end())
        cout << "not found" << endl;
    else
        cout << (*it).name << endl;
}
int main(int argc, const char *argv[])
{
    test2();
    return 0;
}