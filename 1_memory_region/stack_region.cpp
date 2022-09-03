#include <iostream>
using namespace std;

int* func(int b){//形参数据也放在栈区
    b = 100;
    int a = 10;//局部变量储存在栈区，函数执行完后自动释放
    return &a;
}

int main(int argc, const char * argv[]){
    int *b = func(1);

    cout << *b << endl;//10
    cout << *b << endl;//1
} 