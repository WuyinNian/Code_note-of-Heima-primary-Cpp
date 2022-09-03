#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
using namespace std;

void printVector(const vector<int> &v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
}
class Print
{
    public:
    void operator()(int val)
    {
        cout<<val<<"\t";
    }
};
class Transform
{
    public:
    int operator()(int v)
    {
        return v+100;
    }
};
void test()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    // for_each
    printVector(v);
    for_each(v.begin(),v.end(),Print());
    cout<<endl;
    // transform
    vector<int> v2;
    v2.resize(v.size());//搬运,目标容器必须提前开辟空间
    transform(v.begin(),v.end(),v2.begin(),Transform());
    for_each(v2.begin(),v2.end(),Print());
    cout<<endl;
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}