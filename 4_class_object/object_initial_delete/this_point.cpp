#include <iostream>
using namespace std;

class Person{
    public:
    int age;
    Person(int age){
        //指向被调用的成员函数所指的对象
        this->age = age;
    }
    Person& PersonAddAge(Person &p){//返回p本体
        this->age += p.age;
        return *this; 
    }
    Person PersonAddAge1(Person &p){//返回值
        this->age += p.age;
        return *this; 
    }
};


//1.解决名称冲突
void test1(){
    Person p1(18);
    cout << p1.age << endl;
}

//2.返回对象本身用*this；
void test2(){
    Person p1(10);
    Person p2(10);
    //链式编程思想
    p2.PersonAddAge(p1).PersonAddAge(p1);
    cout << p2.age << endl;//30
    p2.PersonAddAge1(p1).PersonAddAge1(p1);
    cout << p2.age << endl;//40
}

int main(int argc, const char * argv[]){
    test2();
    return 0;
}