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
    //有序序列中 返回true or false
    bool it = binary_search(v.begin(),v.end(),4);
    cout << it << endl;
}

int main(int argc, const char *argv[])
{
    test();
    return 0;
}