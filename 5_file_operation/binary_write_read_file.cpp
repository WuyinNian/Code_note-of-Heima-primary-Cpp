#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Person
{
public:
    int age;
};

void test1()
{
    ofstream ofs;
    ofs.open("test", ios::out | ios::binary);
    Person p1 = {18};
    string s = "i am binary ofs";
    ofs.write((const char *)&p1, sizeof(struct Person));
    ofs.write((const char *)&s, sizeof(s));
    ofs.close();
}
void test2()
{
    ifstream ifs;
    ifs.open("test", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "fail" << endl;
        return;
    }

    //读数据 法一
    // char buffer[1024] = {0};
    // while (ifs >> buffer)
    // {
    //     cout << buffer << endl;
    // }

    //法二
    // char buffer[1024] = {0};
    // while (ifs.getline(buffer, sizeof(buffer)))
    // {
    //     cout << buffer << endl;
    // }

    // //法三
    Person p;
    string s;
    ifs.read((char *)&p, sizeof(Person));
    ifs.read((char *)&s, sizeof(s));
    cout << p.age << endl;
    cout << s << endl;

    //法四
    // char c;
    // while ((c = ifs.get()) != EOF)
    // {
    //     cout << c;
    // }

    ifs.close();
}
int main(int argc, const char *argv[])
{
    test1();
    test2();
    return 0;
}