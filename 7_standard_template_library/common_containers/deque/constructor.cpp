#include <iostream>
#include <deque>
using namespace std;

void printfDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
}

void test()
{
    //默认构造
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    printfDeque(d);
    // [beg,end)区间元素拷贝给自身
    deque<int> d1(d.begin(), d.end());
    printfDeque(d1);
    // n个elem拷贝给自身
    deque<int> d2(10, -1);
    printfDeque(d2);
    //拷贝构造
    deque<int> d3(d2);
    printfDeque(d3);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}