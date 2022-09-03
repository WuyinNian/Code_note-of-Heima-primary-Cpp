#include <iostream>
using namespace std;

class Cubic{
    public:
    double longth;
    double width;
    double height;
    double area(){
        return longth * width;
    }
    double volume(){
        return area() * height;
    }
    bool isEqual(Cubic other){
        if (area() == other.area() && volume() == other.volume())
        {
            return true;
        }else {
            return false;
        }
    }
};

bool cubicIsEqual(Cubic cubic1, Cubic cubic2){
    if (cubic1.area() == cubic2.area() && cubic1.volume() == cubic2.volume())
        {
            return true;
        }else {
            return false;
        }
}

int main(int argc, const char * argv[]){
    Cubic cubic1 = {1,2,3};
    Cubic cubic2 = {1,2,3};
    cout << cubic1.isEqual(cubic2) << endl;
    cout << cubicIsEqual(cubic1,cubic2) << endl;
    return 0;
}