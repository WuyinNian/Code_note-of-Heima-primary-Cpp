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
    // at(int idx);
    cout << d.at(5) << endl;
    // operator[];
    cout << d[5] << endl;
    // front();
    cout << d.front() << endl;
    // back();
    cout << d.back() << endl;
}
int main(int argc, const char *argd[])
{
    test();
    return 0;
}