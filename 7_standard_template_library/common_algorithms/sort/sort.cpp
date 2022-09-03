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
void test()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(1);
    v.push_back(56);
    v.push_back(5);
    printVector(v);
    sort(v.begin(), v.end());
    printVector(v);
    sort(v.begin(), v.end(), MySort());
    printVector(v);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}