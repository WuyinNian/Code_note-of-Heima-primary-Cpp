#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void speak()
    {
        cout << "animal speak" << endl;
    }
};

class Cat : public Animal
{
    void speak()
    {
        cout << "cat speak" << endl;
    }
};

class Dog : public Animal
{
    void speak()
    {
        cout << "dog speak" << endl;
    }
};

//该函数的地址在编译阶段就已经被确定
//如果想执行让猫说话，这个函数的地址需要在运行阶段绑定,地址晚绑定

//动态多态满足条件
/*
    1. 有继承关系
    2. 子类重写父类的虚函数(子类中的虚函数表内部 会替换成 子类的虚数地址)
*/

//动态多态使用
//父类的指针或引用指向子类的对象

void doSpeak(Animal &animal)
{
    animal.speak();
}

void test1()
{
    Cat cat;
    doSpeak(cat);
    Dog dog;
    doSpeak(dog);
}

void test2()
{
    cout << "animal: " << sizeof(Animal) << endl; // 8
    cout << "cat: " << sizeof(Cat) << endl;
    cout << "dog: " << sizeof(Dog) << endl;
    cout << sizeof(int *) << endl;                // 8
}

int main(int argc, const char *argv[])
{
    test2();
    return 0;
}