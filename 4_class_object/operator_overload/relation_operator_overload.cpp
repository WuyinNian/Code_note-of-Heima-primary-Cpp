#include <iostream>
using namespace std;

//重载关系运算符

class Person{
    public:
    string name;
    string age;
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    bool operator==(Person &p){
        if (name == p.name && age == p.age)
        {
             return true;
        }
        return false;    
    }
};

void test1(){
    Person p1("Tom", 18);
    Person p2("Tom", 18);
    if (p1 == p2)
    {
        cout << true << endl;
    }   
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}