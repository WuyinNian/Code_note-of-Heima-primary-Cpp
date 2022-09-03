#include <iostream>
using namespace std;

//函数的默认参数
//返回值类型 函数名（形参 = 默认值）
/*
    注意点：
    1. 如果某个位置有默认参数，其后所有参数必须有默认值
    2. 如果函数声明里定义了默认参数，则函数实现不能再定义一次默认参数
*/
int func(int a,int b = 2, int c = 3){
    return a+b+c;
}

int main(int argc, const char * argv[]){
    
    cout << func(1) << endl;
    cout << func(1,3) << endl; 

    return 0;
}