#include <iostream>
using namespace std;

//成员变量和成员函数分开储存
class Person1{
    
};
class Person2{
    public:
    int a;//非静态成员变量 属于类的对象上
};
class Person3{
    public:
    int a;//
    static int b;//静态成员变量 不属于类的对象上
};
int Person3::b = 1;
class Person4{
    public:
    int a;
    static int b;
    void c(){};//非静态成员函数 不属于类对象上
};
class Person5{
    public:
    static void d(){};//静态成员函数 不属于类对象上
};


void test1(){
    Person1 p1;
    cout << sizeof(p1) << endl;//C++编译器为了区分空对象占内存的位置，而给每个空对象分配一个独一无二的1字节空间

    Person2 p2;
    cout << sizeof(p2) << endl;//4

    Person3 p3;
    cout << sizeof(p3) << endl;//4

    Person4 p4;
    cout << sizeof(p4) << endl;//4

    Person5 p5;
    cout << sizeof(p5) << endl;//
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}