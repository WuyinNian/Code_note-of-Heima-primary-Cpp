#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void test1()
{
    ofstream ofs;
    ofs.open("test", ios::out);
    ofs << "i am a output stream" << endl;
    ofs.close();
}
void test2()
{
    ifstream ifs;
    ifs.open("test", ios::in);
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
    string buffer;
    while (getline(ifs, buffer))
    {
        cout << buffer << endl;
    }

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