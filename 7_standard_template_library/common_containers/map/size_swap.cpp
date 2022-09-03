#include <iostream>
#include <map>
using namespace std;

void printMap(const map<int, int> &m)
{
    for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "<" << it->first << "," << it->second << ">"
             << "\t";
    }
    cout << endl;
}

void test()
{
    map<int, int> m;
    m.insert(pair<int, int>(0, 1));
    m.insert(pair<int, int>(1, 2));
    m.insert(pair<int, int>(2, 4));
    m.insert(pair<int, int>(3, 8));
    m.insert(pair<int, int>(4, 16));
    printMap(m);
    if (m.empty())
        cout << "map empty" << endl;
    else
        cout << "size:" << m.size() << endl;

    map<int, int> m1;
    m1.insert(pair<int, int>(0, 1));
    m1.insert(pair<int, int>(1, 2));
    printMap(m1);

    m.swap(m1);
    printMap(m);
    printMap(m1);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}