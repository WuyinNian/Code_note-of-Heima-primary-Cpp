#include <iostream>
using namespace std;

class BasePage
{
public:
    void header()
    {
        cout << "header" << endl;
    }
    void footer()
    {
        cout << "footer" << endl;
    }
    void left()
    {
        cout << "left" << endl;
    }
};
//继承的基本语法
//语法： class 子类 ：继承方式 父类
//子类 派生类 ； 父类 基类
class Java : public BasePage
{
public:
    void content()
    {
        cout << "java content" << endl;
    }
};

class Python : public BasePage
{
public:
    void content()
    {
        cout << "python content" << endl;
    }
};

class CPP : public BasePage
{
public:
    void content()
    {
        cout << "cpp content" << endl;
    }
};

void test1()
{
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
    cout << "---------------" << endl;
    Python py;
    py.header();
    py.footer();
    py.left();
    py.content();
    cout << "---------------" << endl;
    CPP cpp;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
    cout << "---------------" << endl;
}

int main(int argc, const char *argv[])
{
    test1();
    return 0;
}