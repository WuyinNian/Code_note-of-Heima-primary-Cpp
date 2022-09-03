#include <iostream>
using namespace std;

void swap1(int a,int b){//值传递
    int temp = a;
    a = b;
    b = temp;
}

void swap2(int *a, int *b){//地址传递
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap3(int &a,int &b){//引用传递
    int temp = a;
    a = b;
    b = temp;
}

int& test01(){//不要返回局部变量的引用
    int a = 10;
    return a; 
}

int& test02(){//函数调用可以作为左值
    static int a = 10;
    return a; 
}

void func(int& ref){//引用的本质在C++底层实现的是一个指针常量
     ref = 100;
}
void func2(int * const ref){
    *ref = 200;
}

void showValue(const int & ref){//用来修饰形参，防止形参改变实参
    // ref = 1000;
    cout << ref << endl;
} 

int main(int argc, const char * argv[]){
    int a = 10;
    int &b = a;//引用的本质是给变量取别名，必须初始化，且不能更改取名对象 

    cout << a << endl;//10
    cout << b << endl;//10
    b = 20;
    cout << a << endl;//20
    cout << b << endl;//20
    int c = 30;
 
    swap1(b,c);
    cout << b << endl;
    cout << c << endl;

    swap2(&b,&c);
    cout << b << endl;
    cout << c << endl;

    swap3(b,c);
    cout << b << endl;
    cout << c << endl;

    int &d = test01();
    cout << d << endl;//10
    cout << d << endl;//1

    int &e = test02();//如果函数的返回值是引用，则函数调用可以作为左值使用
    cout << e << endl;
    cout << e << endl;

    test02() = 1000;
    cout << e << endl;
    cout << e << endl;

    int f = 500;
    int &ref = f;
    ref = 20;
    cout << f << endl;//20
    cout << ref << endl;//20
    func(f);
    cout << f << endl;//100
    cout << ref << endl;//100

    int g = 100;
    int * const pc = &g;
    *pc = 300;
    cout << g << endl;//300
    cout << *pc << endl;//300
    func2(&g);
    cout << g << endl;//200
    cout << *pc << endl;//200

    //常量引用：用来修饰形参，防止误操作
     int h = 99;
    //  int & i = 99;//必须引用合法内存空间
    // const int & i = 99;//加上const后，编译器将代码修改为， int temp = 10, const int &i = temp;
    // i = 999;//加入const后变为只读，不可修改 
    showValue(h);


    return 0;
}