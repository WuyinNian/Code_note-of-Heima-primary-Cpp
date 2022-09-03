#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

void test()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    v.push_back(5);
    v.push_back(5);
    // adjacent_find,返回指定元素迭代器，找不到返回结束迭代器
    vector<int>::iterator it;
    it = adjacent_find(v.begin(),v.end());
    cout << *it << endl;
}


int main(int argc, const char *argv[])
{
    test();
    return 0;
}