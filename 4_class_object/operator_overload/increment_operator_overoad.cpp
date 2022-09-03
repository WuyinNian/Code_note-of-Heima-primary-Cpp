#include <iostream>
using namespace std;

//递增运算符重载
 
class MyInteger{
    friend  ostream & operator<<(ostream &cout, MyInteger myint);

    public:
        MyInteger(){
            num = 1;
        }

        //前置运算符 返回引用
        MyInteger & operator++(){//返回引用是为了对一个数据进行操作
            num++;
            return *this;
        }
        //后置运算符 返回值 
        //int代表占位参数，用于区分前置和后置
        MyInteger operator++(int){
            MyInteger temp = *this;
            num++;
            return temp;
        }
    private:
        int num;
};

ostream & operator<<(ostream &cout,  MyInteger myint){
    cout << myint.num;
    return cout;
}

void test1(){
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
    cout << (myint++)++ << endl; 
    cout << myint << endl;
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}