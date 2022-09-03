#include <iostream>
#include <deque>
using namespace std;

void printfDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
}

void test()
{
    deque<int> d;
    for (int i = 0; i < 10; i++)
    {
        d.push_back(i);
    }
    printfDeque(d);
    
    //两端插入操作
    d.push_back(99);
    d.push_front(99);
    printfDeque(d);
    d.pop_back();
    d.pop_front();
    printfDeque(d);

    //指定位置操作
    d.insert(d.begin()+1,123);
    d.insert(d.end(),5,99);
    d.insert(d.begin(),d.begin()+8, d.end());
    printfDeque(d);


    d.erase(d.begin(),d.begin()+10);
    d.erase(d.end());
    printfDeque(d);
    d.clear();
    
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}