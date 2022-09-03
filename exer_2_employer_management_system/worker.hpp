#pragma once //防止头文件重复包含
#include <iostream>
#include <string>
using namespace std;

//职工抽象基类
class Worker
{
public:
    virtual void showInfo() = 0;      //显示个人信息
    virtual string getDeptName() = 0; //获取岗位名称
    int wId;
    string wName;
    int wDeptId;
    virtual ~Worker(){};
};