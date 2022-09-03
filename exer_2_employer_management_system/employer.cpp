#include "employer.hpp"
Employer::Employer(int id, string name, int dId)
{
    wId = id;
    wName = name;
    wDeptId = dId;
}
void Employer::showInfo()
{
    cout << "id: " << wId
         << "\tname: " << wName
         << "\tdepartment:" << getDeptName()
         << "\tresponsibility: excute tasks!" << endl;
}
string Employer::getDeptName()
{
    return "employer";
}