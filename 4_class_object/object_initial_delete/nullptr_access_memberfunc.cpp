#include <iostream>
using namespace std;

class Person{
    public:
    void showClassName(){
        cout << "this is a Person class!" << endl;
    }
    void showPersonAge(){
        //报错的原因是因为传入的指针为NULL
        if(this == NULL){
            return;
        }
        cout << "age = " << this->m_Age << endl;
    }
    int m_Age;
};

void test1(){
    Person *p = NULL;
    p->showClassName();
    // p->showPersonAge(); 报错 
}

int main(int argc, const char * argv[]){
    test1();
    return 0;
}