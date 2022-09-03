#include <iostream>
using namespace std;

class Point{
    public:
    double x;
    double y;
};

class Circle{
    public:
    double centerX;
    double centerY;
    int radius;
    void locationWithPoint(Point point){
        double circle = (point.x - centerX) * (point.x - centerX) + (point.y - centerY) * (point.y - centerY);
        if (circle < radius * radius)
        {
            cout << "点在圆内" << endl;
        } else if(circle == radius * radius){
            cout << "点在圆上" << endl;
        }else if(circle > radius * radius){
            cout << "点在圆外" << endl;
        }
    }
};

int main(int argc, const char * argv[]){
    Circle c = {0,0,1};
    Point p1 = {0,0};
    Point p2 = {0,1};
    Point p3 = {0,2};
    c.locationWithPoint(p1);
    c.locationWithPoint(p2);
    c.locationWithPoint(p3);
    return 0;
}