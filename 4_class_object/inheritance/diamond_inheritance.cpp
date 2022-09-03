#include <iostream>
using namespace std;

class Animal
{
public:
    int age;
};

//Animal 虚基类
//vbptr虚基类指针 指向 虚基类表vbtable
class Sheep : virtual public Animal
{

};

class Camel : virtual public Animal
{

};

class Alpaca : public Sheep, public Camel
{

};

void test1(){
    Alpaca al;
    //出现钻石继承时，两个父类拥有相同的数据需要加以作用域区分
    al.Sheep :: age = 18;
    al.Camel :: age = 28;
    cout << "Sheep" << al.Sheep :: age << endl;
    cout << "Camel" << al.Camel :: age << endl;

    //这份数据我们知道，只有一份就可以，菱形继承导致数据有两份，资源浪费
    //利用虚继承解决
    cout << al.age << endl;
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}