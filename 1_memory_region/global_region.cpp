#include <iostream>
#include <stdio.h>
using namespace std;

int g_a = 10;
int g_b = 20;
const int cg_a = 10;

int main(int argc, const char * argv[]){
    int l_a = 10;
    int l_b = 20;

    static int s_a = 10;
    static int s_b = 20;

    const int cl_a = 10;

    cout << "全局变量的地址：" << (long long)&g_a << endl;
    cout << "全局变量的地址：" << (long long)&g_b << endl;
    cout << "局部变量的地址：" << (long long)&l_a << endl;
    cout << "局部变量的地址：" << (long long)&l_b << endl;
    cout << "静态变量的地址：" << (long long)&s_a << endl;
    cout << "静态变量的地址：" << (long long)&s_b << endl;
    cout << "字符串常量的地址：" << (long long)&"abc" << endl;
    cout << "const局部常量的地址：" << (long long)&cl_a << endl;
    cout << "const全局常量的地址：" << (long long)&cg_a << endl;


}