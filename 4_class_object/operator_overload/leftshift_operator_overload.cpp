#include <iostream>
using namespace std;

//左移运算符重载
class Person{
    friend ostream & operator<<(ostream &cout, Person &p);
    friend void test1();

    private:
    int a;
    int b;

};

ostream & operator<<(ostream &cout, Person &p){
    cout << "a = " << p.a << " b = " << p.b;
    return cout;
}



void test1(){
    Person p1;
    p1.a = 10;
    p1.b = 10;

    cout << p1 << endl;
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}