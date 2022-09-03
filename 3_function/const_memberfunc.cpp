#include <iostream>
using namespace std;

//常函数 
class Person{
    public:
    Person(){};
    //this的本质是一个指针常量，指针的指向是不可以修改的
    //this == "Person * const this"
    //const Person * const this;
    void showPerson() const {//在成员函数后面加const，修饰的是this指针，让指针指向的值也不可以修改
        // this->m_A = 100;
        // this = NULL;//this指针不可以修改指针的指向
        this -> m_B = 100;
    }
    void func(){};
    int m_A;
    mutable int m_B;//使用mutable关键字 特殊变量，即使在常函数中，也可以修改这个值
};
void test1(){
    Person p;
    p.showPerson();
}     

//常对象
void test2(){
    const Person p;//在对象前加const，变为常对象
    // p.m_A = 100;
    p.m_B = 100;
    p.showPerson();//常函数只能调用常函数
    // p.func();
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}