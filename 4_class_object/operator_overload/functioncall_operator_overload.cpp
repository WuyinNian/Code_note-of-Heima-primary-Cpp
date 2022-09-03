#include <iostream>
#include <string>
using namespace std;
//函数调用运算符重载

class MyPrint{
    public:
    void operator()(string text){
        cout << text << endl; 
    }
};

void test1(){
    MyPrint myprint;
    myprint("hello world!");//因为使用起来像函数调用，所以称为仿函数
    MyPrint()("我是匿名函数对象");
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}