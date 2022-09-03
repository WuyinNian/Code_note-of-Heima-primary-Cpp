#include <iostream>
using namespace std;

class MakeDrink
{
public:
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
class MakeCoffee : public MakeDrink
{
    void makeDrink()
    {
        cout << "-----------please waiting...----------" << endl;
        boilWater();
        cout << "making coffee..." << endl;
        pourToCup();
        cout << "adding the sugar and the milk..." << endl;
        cout << "Done!" << endl;
    }
};
class MakeTea : public MakeDrink
{
    void makeDrink()
    {
        cout << "-----------please waiting...----------" << endl;
        boilWater();
        cout << "making tea..." << endl;
        pourToCup();
        cout << "adding the lenmon..." << endl;
        cout << "Done!" << endl;
    }
};

void makeDrink(MakeDrink *drink)
{
    drink->makeDrink();
    delete drink;
}

void test1()
{
    makeDrink(new MakeCoffee);
    makeDrink(new MakeTea);
}
int main(int argc, const char *argv[])
{
    test1();
    return 0;
}