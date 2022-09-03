#include <iostream>
using namespace std;

//函数重载满足的条件
//同一个作用域下；函数名称相同；函数参数类型不同，或者个数不同，或者顺序不同
void func(){}
void func(int a){}
void func(int a, bool b){}

//返回值不能作为函数重载的条件
// int func(int a){}//无法重载仅按返回类型区分的函数

//引用作为重载的条件
void func1(int &a){//int &a = 10;不合法
    cout << "func1(int &a)" << endl;
}
void func1(const int &a){//const int &a = 10;
    cout << "func1(const int &a)" << endl;
}

//函数重载碰到默认参数
void func2(int a,int b = 20){
    cout << "func2(int a,int b)" << endl;
}
void func2(int a){
    cout << "func2(int a = 20)" << endl;
}
int main(int argc,const char * argv[]){

    int a = 10;
    func1(a);
    func1(10);

    int b = 20;
    // func2(a);有多个 重载函数 "func2" 实例与参数列表匹配
    // func2(a);

    return 0;
}