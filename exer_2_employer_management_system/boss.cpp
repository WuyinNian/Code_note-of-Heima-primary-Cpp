#include "boss.hpp"

Boss::Boss(int id, string name, int dId)
{
    wId = id;
    wName = name;
    wDeptId = dId;
}
void Boss::showInfo()
{
    cout << "id: " << wId
         << "\tname: " << wName
         << "\tdepartment:" << getDeptName()
         << "\t\tresponsibility: boss tasks!" << endl;
}
string Boss::getDeptName()
{
    return "Boss";
}