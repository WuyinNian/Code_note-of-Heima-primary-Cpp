#include <iostream>
#include <list>
using namespace std;

void printList(const list<int> &l)
{
    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
    {
        cout << (*it) << "\t";
    }
    cout << endl;
}
void test()
{
    list<int> l;
    for (int i = 0; i < 5; i++)
    {
        l.push_back(2 * i);
        l.push_front(i);
    }
    printList(l);
    //构造函数
    list<int> l1(l.begin(), l.end());
    printList(l1);
    list<int> l2(10, -1);
    printList(l2);
    list<int> l3(l2);
    printList(l3);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}