#include <iostream>
#include <fstream>

using namespace std;

//函数模板
template <typename T> //声明模板，T是一个通用数据类型
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void func()
{
    cout << "func()" << endl;
}

void test()
{
    //两种方式使用模板
    //法一 自动类型推导,必须推导出一致的数据类型T，才可以使用
    int a = 10;
    int b = 20;
    mySwap(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    //法二 显式使用类型
    mySwap<int>(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}

void test2()
{
    func<int>(); //模板要确定出T的数据类型才可以使用
}

//普通函数和函数模板的区别
// 1.普通函数调用可以发生隐式类型转换
// 2.函数模板用自动类型推到，不可以发生隐式类型转换
//  函数模板显示指定类型，可以发生隐式类型转换
void test3()
{
}
int main(int argc, const char *argv[])
{
    test();
    return 0;
}