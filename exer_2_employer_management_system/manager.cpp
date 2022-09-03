#include "manager.hpp"

Manager::Manager(int id, string name, int dId)
{
    wId = id;
    wName = name;
    wDeptId = dId;
}
void Manager::showInfo()
{
    cout << "id: " << wId
         << "\tname: " << wName
         << "\tdepartment:" << getDeptName()
         << "\tresponsibility: manager tasks!" << endl;
}
string Manager::getDeptName()
{
    return "Manager";
}