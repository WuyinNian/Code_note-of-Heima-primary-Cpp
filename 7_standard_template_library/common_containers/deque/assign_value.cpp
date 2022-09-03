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
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    printfDeque(d);
    
    deque<int> d1 = d;
    printfDeque(d1);

    d1.assign(d1.begin(),d1.end());
    printfDeque(d1);

    d1.assign(10,-1);
    printfDeque(d1);
    
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}