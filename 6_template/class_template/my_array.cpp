#include <iostream>
#include <string>
using namespace std;
#include "my_array.hpp"

void printArr(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << arr[i] << endl;
    }
}
void test()
{
    MyArray<int> arr(5);
    for (int i = 0; i < 5; i++)
    {
        arr.add(i);
    }
    cout << "capacity:" << arr.getCapcity() << endl;
    cout << "size:" << arr.getSize() << endl;
    printArr(arr);

    arr.deleteArr();
    cout << "capacity:" << arr.getCapcity() << endl;
    cout << "size:" << arr.getSize() << endl;
}

class Person
{
public:
    Person(){};
    Person(string name, int age)
    {
        pName = name;
        pAge = age;
    }
    string pName;
    int pAge;
};
void printArr2(MyArray<Person> &arr)
{
    for (int i = 0; i < arr.getSize(); i++)
    {
        cout << "name:" << arr[i].pName << ",age:" << arr[i].pAge << endl;
    }
}
void test2()
{
    MyArray<Person> arr(5);
    Person *p;
    for (int i = 0; i < 5; i++)
    {
        p = new Person("i", i);
        arr.add(*p);
    }
    cout << "capacity:" << arr.getCapcity() << endl;
    cout << "size:" << arr.getSize() << endl;
    printArr2(arr);

    arr.deleteArr();
    cout << "capacity:" << arr.getCapcity() << endl;
    cout << "size:" << arr.getSize() << endl;
    delete p;
}
int main()
{
    test2();
    return 0;
}