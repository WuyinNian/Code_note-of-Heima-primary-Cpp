#pragma once //防止头文件重复包含
#include <iostream>
#include <string>
using namespace std;
#include "worker.hpp"

//普通员工
class Manager : public Worker
{
public:
    Manager(int id,string name,int dId);
    virtual void showInfo();
    virtual string getDeptName();
};