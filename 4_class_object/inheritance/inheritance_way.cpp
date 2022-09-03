#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A constructer" << endl;
    }

    ~A()
    {
        cout << "A destructer" << endl;
    }
    int a;
    int sameName = 1;
    void func()
    {
        cout << "A sameName func" << endl;
    }
    void func(int a)
    {
        cout << "overload sameName func" << endl;
    }

protected:
    int b;

private:
    int c;
};

//继承方式
//父类中的private权限子类无论何种继承都无法访问，但是只是隐藏了，还是会继承下去
class B : public A
{
public:
    B()
    {
        cout << "B constructer" << endl;
    }

    ~B()
    {
        cout << "B destructer" << endl;
    }

    void func()
    {
        cout << "B sameName func" << endl;
        //父类非private权限到子类中为public权限
    }
     int sameName = 2;
};

class C : protected A
{
public:
    void func()
    {
        //父类非private权限到子类中为protected权限
    }
};

class D : private A
{
public:
    void func()
    {
        //父类非private权限到子类中为private权限
    }
};

//父类中的private权限子类无论何种继承都无法访问，但是只是隐藏了，还是会继承下去
void test1()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;
    cout << sizeof(D) << endl;
}

//继承中的构造 和 析构顺序
// 构造：AB
// 析构：BA
void test2()
{
    A a;
    B b;
}

//同名(静态)成员的处理方式
//子类：直接访问
//父类：加作用域
void test3()
{
    B b;
    cout << b.sameName << endl;
    cout << b.A::sameName << endl;
    b.func();
    b.A::func();
    // b.func(100); 如果子类出现和父类中同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    //虽然子类中没有func(int a)，但子类也不能直接访问，必须加上父类的作用域
    b.A::func(100);
}

int main(int argc, const char *argv[])
{
    test3();
    return 0;
}