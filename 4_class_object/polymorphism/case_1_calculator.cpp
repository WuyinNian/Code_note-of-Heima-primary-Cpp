#include <iostream>
#include <string.h>
using namespace std;

//普通实现
class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return num1 + num2;
        }
        else if (oper == "-")
        {
            return num1 - num2;
        }
        else if (oper == "*")
        {
            return num1 * num2;
        }
        //如果想扩展新的功能，需求修改源码
        //真实开发中，提倡 开闭原则
        //开闭原则：对扩展进行开发，对修改进行关闭
    }

    int num1;
    int num2;
};

void test1()
{
    Calculator cal;
    cal.num1 = 10;
    cal.num2 = 10;
    cout << cal.getResult("+") << endl;
    cout << cal.getResult("-") << endl;
    cout << cal.getResult("*") << endl;
}

//利用多态实现计算器
//实现计算器抽象类
/**
 * @brief 多态好处
 * 1. 组织结构清晰
 * 2. 可读性强
 * 3. 对于前期和后期扩展以及可维护性高
 */
class AbstarctCalculator
{
public:
    int num1;
    int num2;

    //纯虚函数
    //当类中存在纯虚函数，该类也称为抽象类
    //1.抽象类无法实例化对象
    //2.抽象类的子类必须重写纯虚函数
    virtual int getResult() = 0;
};

class AddCalculator : public AbstarctCalculator
{
    int getResult()
    {
        return num1 + num2;
    }
};
class SubCalculator : public AbstarctCalculator
{
    int getResult()
    {
        return num1 - num2;
    }
};
class MulCalculator : public AbstarctCalculator
{
    int getResult()
    {
        return num1 * num2;
    }
};

void test2()
{
    AbstarctCalculator *cal = new AddCalculator;
    cal->num1 = 10;
    cal->num2 = 10;
    cout << cal->getResult() << endl;
    delete(cal);

    cal = new SubCalculator;
    cal->num1 = 10;
    cal->num2 = 10;
    cout << cal->getResult() << endl;
    delete(cal);

    cal = new MulCalculator;
    cal->num1 = 10;
    cal->num2 = 10;
    cout << cal->getResult() << endl;
    delete(cal);
}

int main(int argc, const char *argv[])
{
    test2();
    return 0;
}