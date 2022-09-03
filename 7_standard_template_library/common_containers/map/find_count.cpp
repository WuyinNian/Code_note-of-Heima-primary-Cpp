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
    m.insert(make_pair(1, 2));
    m.insert(map<int, int>::value_type(2, 4));
    m[3] = 8; //不建议使用插入数据，[]一般用来访问
    m.insert(pair<int, int>(4, 16));
    printMap(m);

    cout << m.find(3)->second << endl;
    cout << m.count(3) << endl;
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}