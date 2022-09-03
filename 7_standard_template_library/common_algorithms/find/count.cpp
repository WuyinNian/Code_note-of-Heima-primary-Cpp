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
    // count
    int it;
    it = count(v.begin(),v.end(),5);
    cout << it << endl;
}


int main(int argc, const char *argv[])
{
    test();
    return 0;
}