#include <iostream>
using namespace std;

//重载赋值运算符

class Person{
    public:
    Person(int age){
        this->age = new int(age);
    }
    ~Person(){
        if(age != NULL){
            delete age;
            age = NULL;
        }
    }
    Person & operator=(Person &p){
        //先判断属性是否在堆区，如果有先释放干净，再进行深拷贝
        if(age != NULL){
            delete age;
            age = NULL;
        }
        //深拷贝
        age = new int(*p.age);
        return *this;
    }
    int *age;
};

void test1(){
    Person p1(18);
    Person p2(20);
    Person p3(30);
    p3 = p2 = p1;

    cout << *p1.age << endl;
    cout << *p2.age << endl;
    cout << *p3.age << endl;
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}