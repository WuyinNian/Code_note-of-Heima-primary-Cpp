#include <iostream>
using namespace std;

class Person{
    public:
    //静态成员变量
    //1.所有对象共享一份数据    两种访问方式：对象访问，类名访问
    //2.编译阶段分配内存，全局区
    //3.类内声明，类外初始化
    static int age;
    int height = 180;
    //静态成员函数
    static void func(){
        age = 18;
        //height = 80;静态成员函数不能访问非静态成员变量,无法判断访问该变量属于哪一个对象
        cout << "this is a static function" << endl;
    } 

    private:
    static int id;
    static void func2(){
        age = 18;
        //height = 80;静态成员函数不能访问非静态成员变量,无法判断访问该变量属于哪一个对象
        cout << "this is a static function" << endl;
    } 
};
int Person::age = 100;//类外初始化
int Person::id = 200;

void test1(){
    Person p1;
    cout << p1.age << endl; 
    Person p2;
    p2.age = 200;
    cout << p2.age << endl;//对象访问
    cout << Person::age << endl;//类名访问
    // cout << Person::id << endl;//类外访问不到私有静态成员变量

    p1.func();
    Person::func();
    //Person::func2();// 类外访问不到私有静态成员函数
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}