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
//将两个有序序列merge到一个新的容器中且是有序序列
void test()
{
    vector<int> v;
    v.push_back(9);
    v.push_back(1);
    v.push_back(56);
    v.push_back(5);
    sort(v.begin(),v.end());
    vector<int> v2;
    v2.push_back(11);
    v2.push_back(112);
    v2.push_back(113);
    printVector(v);
    printVector(v2);
    vector<int> v3;
    v3.resize(v.size()+v2.size());
    merge(v.begin(),v.end(),v2.begin(),v2.end(),v3.begin());
    printVector(v3);
    
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}