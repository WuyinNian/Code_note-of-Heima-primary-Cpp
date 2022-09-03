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
    map<int, int> m1(m);
    printMap(m1);
    map<int, int> m2 = m;
    printMap(m2);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}