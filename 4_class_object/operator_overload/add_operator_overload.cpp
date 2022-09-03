#include <iostream>
using namespace std;

//加号运算符重载
class Person{
    public:
    int a;
    int b;

    //成员函数运算符重载
    // Person operator+(Person &p){
    //     Person sum;
    //     sum.a = this->a + p.a;
    //     sum.b = this->b + p.b;
    //     return sum;
    // }
};

//全局函数运算符重载
Person operator+(Person &p1, Person &p2){
        Person sum;
        sum.a = p1.a + p2.a;
        sum.b = p1.b + p2.b;
        return sum;
    }


void test1(){
    Person p1;
    p1.a = 10;
    p1.b = 10;

    Person p2;
    p2.a = 10;
    p2.b = 10;

    //本质
    //Person p3 = p1.operator+(p2);
    //Person p3 = opperator(p1,p2);
    //运算符重载也可以发生函数重载
    Person p3 = p1 + p2;
    cout << "a = " << p3.a << ", b = " << p3.b << endl;
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}