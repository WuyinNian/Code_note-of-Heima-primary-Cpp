#include <iostream>
#include <string>
using namespace std;
const double PI = 3.14;

class Circle{
    public:
    int r;

    double calculateZC(){
        return 2 * PI * r;
    }
};

class Student{
    
    private:
    string name;
    long long sid;

    public:
    void setName(string n){
        name = n;
    }
    void setSID(long long s){
        sid = s;
    }
    void showStudent(){
        cout << name << endl;
        cout << sid << endl;
    }
};

int main(int argc, const char * argv[]){

    Circle c1;
    c1.r = 10;
    cout << c1.calculateZC() << endl;

    Student s1;
    s1.setName("xjp");
    s1.setSID(12132089);
    s1.showStudent();

    return 0;
}