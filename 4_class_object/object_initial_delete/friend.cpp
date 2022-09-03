#include <iostream>
#include <string>
using namespace std;

class Building;

//friend class
class Goodgay{
public:
    Goodgay();
    Building *b;
    void visit();
};

//friend member function
/*
    成员函数做友元易错点：
    1.因为Goodgay类需要声明Building类变量，所以Building类必须Goodgay类之前声明（前向声明）；
    2.因为Building的定义中需要将Goodgay类的成员函数声明成友元成员函数，所以Building类必须Goodgay类之后定义；
    3.因为Goodgay中的构造函数需要调用Building的构造函数，所以Goodgay类中构造函数的实现必须在Building类的定义之后；
    4.因为Goodgay中成员函数需要访问Building的私有变量badRoom，所以Goodgay类中成员函数的实现必须在Building类的定义之后；
    总结：
    1. Building类在Goodgay类前面声明，后面定义；
    2. Goodgay类定义时“类内”不实现 构造函数 和 需要friend的成员函数；
    3. Goodgay在Building类定义后，“类外”实现构造函数 和 需要friend的成员函数；
*/
class Goodgay1{
public:
    Goodgay1();
    Building *b;
    void visit();
};

class Building{
    //Building's friend , access to private variable
    friend void goodGay(Building *b);
    friend class Goodgay;
    friend void Goodgay1::visit();
public:
    Building(){
        sittingRoom = "sittingroom";
        badRoom = "badroom";
    };
    string sittingRoom;
private:
    string badRoom;
};

//类外函数的实现
Goodgay::Goodgay(){
    b = new Building;
}
Goodgay1::Goodgay1(){
    b = new Building;
}
void Goodgay::visit(){
    cout << "class goodgay: " << b->sittingRoom << endl;
    cout << "class goodgay: " << b->badRoom << endl;
}
void Goodgay1::visit(){
    cout << "goodgay1 member func: " << b->sittingRoom << endl;
    cout << "goodgay1 member func: " << b->badRoom << endl;
}

//global function
void goodGay(Building *b){
    cout << "goodgay gloabl func: " << b->sittingRoom << endl;
    cout << "goodgay gloabl func: " << b->badRoom << endl;
}

void test1(){
    Building b;
    goodGay(&b);
}
void test2(){
    Goodgay g;
    g.visit();
}
void test3(){
    Goodgay1 g1;
    g1.visit();
}

int main(int argc, const char * argv[]){
    test1(); 
    test2();
    test3();
    return 0;
}