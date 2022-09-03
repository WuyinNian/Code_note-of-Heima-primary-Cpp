#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
void printVector(vector<int> v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
}
void myprint(int v)
{
    cout << v << "\t";
}
void test()
{
    vector<int> v;
    vector<int> v2;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
        v2.push_back(i+5);
    }
    printVector(v);
    printVector(v2);

    vector<int> v3;
    v3.resize(min(v.size(), v2.size()));
    //有序序列的交集
    vector<int>::iterator itEnd = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), itEnd, myprint);
    cout << endl;
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}