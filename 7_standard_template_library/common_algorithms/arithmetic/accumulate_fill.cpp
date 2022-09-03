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
    int value;
    value = accumulate(v.begin(), v.end(), 0);
    cout << value << endl;
    fill(v.begin(),v.end(),-1);
    printVector(v);
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}