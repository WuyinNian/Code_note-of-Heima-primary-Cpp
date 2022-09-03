#include <iostream>
using namespace std;

//构造函数和析构函数的是一个程序必须有的实现，如果不人为实现的话，编译器会自动提供一个空实现
/*
    构造函数调用规则：
    1.C++编译器会默认提供如下2个构造函数和1个析构函数
        无参空实现构造函数  无参空实现析构函数 对属性值进行拷贝的拷贝构造函数
    2.若人为提供有参构造函数，则不提供默认无参构造函数，但提供默认拷贝构造函数
    3.若人为提供拷贝函数，则两种默认构造函数均不提供

*/
//构造函数分类：有参 和 无参； 普通 和 拷贝 
class Person{
    public:
    int age;
    int *height;
    int id;
    //无参构造
    Person(){//对象创建时调用
        cout << "this is a constructor." << endl;
    }

    //有参构造
    Person(int a){
        age = a;
        cout << "this is a contructor with paramater" << endl;
    }
    Person(int a, int h){
        age = a;
        height = new int(h);
        cout << "this is a contructor with paramater" << endl;
    }
    //初始化列表
    Person(int a,int h, int i): age(a),height(new int(h)),id(i) {
        
    }
    
    ~Person(){//对象销毁时调用
        //将堆区的开辟的数据做一个释放的操作
        if(height != NULL){
            delete height;
            height = NULL; 
        }
        cout << "this is a destructor." << endl;
    }

    //拷贝构造函数
    Person(const Person &p){
        age = p.age;
        //height = p.height;//编译器默认实现
        height = new int(*p.height); //深拷贝操作，重新在堆区开辟一块内存
        cout << "this is a copy constructor" << endl;
    }
};

//构造函数的调用形式
void test1(){
    //括号法
    Person p1;//默认构造
    Person p2(10);//有参构造
    Person p3(p1);//拷贝构造
    //注意事项
    //调用默认构造函数时不要加（）,因为编译器会把它当成一个函数声明，不会认为在创建对象

    //显示法
    Person p4 = Person(10);//有参构造
    Person p5 = Person(p2);//拷贝构造 
    //注意事项
    //1.Person(10)是一个匿名对象，当前行执行结束后，系统会立即回收匿名对象。
    //2.不要利用拷贝构造函数初始化一个匿名的对象Person(p4)，编译器会认为Person(p4) === Person p4;

    //隐式转换法
    Person p6 = 10;//Person p6 = Person(10) 有参构造
    Person p7 = p5;//拷贝构造
}

//拷贝构造函数的调用场景
void doWork(Person p){};
Person doWork2(){
    Person p(20);
    cout << (long long)&p << endl;
    return p;
}
void test2(){
    //1.使用已知对象创建新对象
    Person p1(20);
    Person p2(p1);
    //2.值传递的方式给函数参数传值,值传递会拷贝出来一个副本
    doWork(p1);
    //3.值方式返回局部对象//g++ -fno-elide-constructors constructor_destructor.cpp编译才会调用
    Person p3 = doWork2();
    cout << (long long)&p3 << endl; 
}

//浅拷贝 和 深拷贝
//利用编译器提供的拷贝构造函数做浅拷贝，会造成内存重复释放（因为拷贝的时候会把地址逐一字节拷贝过去，在拷贝对象被释放后，被拷贝对象会被重复释放）
//自己实现拷贝函数，在堆区重新开辟一块空间，存放被拷贝内容，解决浅拷贝带来的  内存重复释放 问题
void test3(){
    Person p1(20,180);
    cout << "p1: " << p1.age << "  " << *p1.height << endl;
    Person p2(p1);
    cout << "p2: " << p2.age << "  " << *p2.height << endl;
}

void test4(){
    Person p(1,2,3);
    cout << p.age << endl;
    cout << *p.height << endl;
    cout << p.id << endl;
}
int main(int argc, const char * argv[]) {
    
    test4();
    return 0;
}