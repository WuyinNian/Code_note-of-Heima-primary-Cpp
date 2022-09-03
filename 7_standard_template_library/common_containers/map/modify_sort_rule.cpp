#include <iostream>
#include <map>
using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2) const//需要加const
    {
        return v1 > v2;
    }
};

void printMap(const map<int, int, MyCompare> &m) 
{
    for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "<" << it->first << "," << it->second << ">"
             << "\t";
    }
    cout << endl;
}

void test()
{
    map<int, int, MyCompare> m;
    m.insert(pair<int, int>(0, 1));
    m.insert(make_pair(1, 2));
    m.insert(map<int, int>::value_type(2, 4));
    m[3] = 8; //不建议使用插入数据，[]一般用来访问
    m.insert(pair<int, int>(4, 16));

    printMap(m);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}