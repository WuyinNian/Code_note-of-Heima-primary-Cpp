#include <iostream>
using namespace std;

class Person{
    public:
    //无参构造
    Person(){//对象创建时调用
        cout << "this is a Person constructor." << endl;
    }
    ~Person(){
        cout << "this is a Person destructor." << endl;
    }
};

class Student{
    public:
    Student(){
        cout << "this is a Student constructor." << endl;
    }
    ~Student(){
        cout << "this is a Student destructor." << endl;
    }
    Person p;//其他类对象作为本类成员，先构造其他类对象，再构造自身 
};

int main(int argc, const char * argv[]) {
    
    Student s;

    return 0;
}