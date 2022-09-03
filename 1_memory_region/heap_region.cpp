#include <iostream>
using namespace std;

int* func(){
    int *a = new int(10);//new可以将数据开辟到堆区，指针本质也是局部变量，放在栈上，指针保存的数据放在堆区
    return a;
}

void func2(){
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i; 
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }
    delete[] arr;
}

int main(int argc, const char * argv[]){
    int * a = func();
    cout << a << endl;
    cout << *a << endl;//10
    delete a; 
    cout << *a << endl;//内存已被释放，再次访问就是非法操作，可能会报错（取决于编译器或者系统）
    func2();
}

