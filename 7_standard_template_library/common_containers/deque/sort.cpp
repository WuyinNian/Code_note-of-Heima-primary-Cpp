#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(deque<int> &d)
{
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
}

void test()
{
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    d.push_back(94);
    d.push_front(20);
    d.push_front(54);
    d.push_back(7);
    printDeque(d);
    //支持随机访问迭代器的容器，都可以直接使用sort排序
    sort(d.begin(),d.end());
    printDeque(d);
    sort(d.rbegin(),d.rend());
    printDeque(d);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}