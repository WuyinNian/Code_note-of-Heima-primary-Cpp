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

    l.pop_back();
    l.pop_front();
    printList(l);

    list<int>::iterator it = l.begin();
    l.insert(it,99);
    l.insert(--l.end(),3,-99);
    l.insert(l.begin(),l.begin(),l.end());
    printList(l);

    l.erase(l.begin());
    l.remove(-99);
    printList(l);

    l.erase(l.begin(),l.end());
    l.clear();
    printList(l);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}