#include <iostream>
#include <deque>
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
    printDeque(d);
    // empty();
    // size();
    if (d.empty())
    {
        cout << "deque empty" << endl;
    }
    else
    {
        cout << "deque not empty" << endl;
        cout << "size:" << d.size() << endl;
    }
    // resize(int num);
    d.resize(15);
    printDeque(d);
    cout << "size:" << d.size() << endl;
    // resize(int num,elem);
    d.resize(16,-1);
    printDeque(d);
    cout << "size:" << d.size() << endl;
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}