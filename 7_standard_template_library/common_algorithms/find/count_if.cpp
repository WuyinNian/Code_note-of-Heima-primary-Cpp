#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

class Greater5
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
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    v.push_back(5);
    v.push_back(5);
    // count
    int it;
    it = count_if(v.begin(), v.end(), Greater5());
    cout << it << endl;
}

int main(int argc, const char *argv[])
{
    test();
    return 0;
}