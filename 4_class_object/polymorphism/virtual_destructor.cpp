#include <iostream>
using namespace std;

//多态使用时，子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码
//解决方式：将父类中的析构函数改为 虚析构 或者 纯虚析构

//虚析构和纯虚析构共性
// 1.可以解决父类指针释放子类对象
// 2.都需要有具体的函数实现
//区别：有了纯虚析构之后，这个类也属于抽象类，无法实例化对象

class MakeDrink
{
public:
    MakeDrink()
    {
        cout << "MakeDrink constructor" << endl;
    }
    //利用虚析构可以解决 父类指针释放子类对象时不干净的问题
    virtual ~MakeDrink()
    {
        cout << "MakeDrink destructor" << endl;
    }

    //纯虚析构,需要声明也需要实现
    // virtual ~MakeDrink() = 0;

    void boilWater()
    {
        cout << "boiling the water..." << endl;
    }
    void pourToCup()
    {
        cout << "pouring to the cup..." << endl;
    }
    virtual void makeDrink() = 0;
};
// MakeDrink::~MakeDrink()
// {
//     cout << "MakeDrink pure virtual destructor" << endl;
// }

class MakeCoffee : public MakeDrink
{
public:
    MakeCoffee(int no)
    {
        cout << "MakeCoffe constructor" << endl;
        num = no;
    }
    void makeDrink()
    {
        cout << "-----------Drink NO." << num << "----------" << endl;
        boilWater();
        cout << "making coffee..." << endl;
        pourToCup();
        cout << "adding the sugar and the milk..." << endl;
        cout << "Done!" << endl;
    }
    ~MakeCoffee()
    {
        cout << "MakeCoffee destructor" << endl;
    }
    int num;
};

class MakeTea : public MakeDrink
{
public:
    MakeTea(int no)
    {
        cout << "MakeTea constructor" << endl;
        num = no;
    }
    void makeDrink()
    {
        cout << "-----------Drink NO." << num << "----------" << endl;
        boilWater();
        cout << "making tea..." << endl;
        pourToCup();
        cout << "adding the lenmon..." << endl;
        cout << "Done!" << endl;
    }
    ~MakeTea()
    {
        cout << "MakeTea destructor" << endl;
    }
    int num;
};

void test1()
{
    MakeDrink *drink = new MakeCoffee(1);
    drink->makeDrink();
    delete drink; //父类指针在析构的时候不会调用子类中析构函数，导致子类如果有堆区属性，会出现内存泄漏情况
    drink = new MakeTea(2);
    drink->makeDrink();
    delete drink;
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}