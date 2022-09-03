#include <iostream>
#include <fstream>
using namespace std;

//普通函数和函数模板的调用规则
void myprint(int a,int b)
{
    cout<<"ordinary func"<<endl;
}

template<typename T>
void myprint(T a,T b)
{
    cout<<"template func"<<endl;
}
template<typename T>
void myprint(T a)
{
    cout <<"overload tempate func"<<endl;
}


//1.如果二者都可以调用，优先调用普通函数
void test1()
{
    int a = 10;
    int b=20;
    myprint(a,b);
}

//2.可以通过空模板参数列表 强制调用 模板函数
void test2()
{
    int a=10;
    int b=20;
    myprint<>(a,b);
}

//3.函数模板可以发生函数重载
void test3()
{
    int a=10,b=20;
    myprint(a);
}

//4.如果函数模板可以产生更好的匹配，优先调用函数模板
void test4()
{
    char a='a',b='b';
    myprint(a,b);

}
int main(int argc, const char * argv[]){
    test1();
    test2();
    test3();
    test4();
    return 0;
}