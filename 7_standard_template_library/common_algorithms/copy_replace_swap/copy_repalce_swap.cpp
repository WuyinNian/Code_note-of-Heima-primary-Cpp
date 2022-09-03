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
class MySort
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};
class RePlace5
{
public:
    bool operator()(int v)
    {
        return v > 5;
    }
};
void test()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(1);
    v.push_back(56);
    v.push_back(5);
    vector<int> v2;
    v2.resize(v.size());
    copy(v.begin(), v.end(), v2.begin());
    printVector(v2);
    replace(v2.begin(), v2.end(), 1, 2);
    printVector(v2);
    replace_if(v2.begin(), v2.end(), RePlace5(), 99);
    printVector(v2);
    swap(v, v2);
    cout << "---------" << endl;
    printVector(v);
    printVector(v2);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}