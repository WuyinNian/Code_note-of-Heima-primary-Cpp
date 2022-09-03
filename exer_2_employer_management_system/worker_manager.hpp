#pragma once //防止头文件重复包含
#include <iostream>
#include <fstream> 
#define FILENAME "empFile.txt"
#include "worker.hpp"
#include "employer.cpp"
#include "manager.cpp"
#include "boss.cpp"
using namespace std;

class WorkerManager
{
public:
    int empNum;//记录职工人数
    Worker** empArray;//职工数组指针
    bool fileIsEmpty; 
    WorkerManager();
    void showMenu();
    void exitSystem();
    void addEmp();
    void showEmp();
    int isExist(int id);//判断员工是否存在
    void deleteEmp();//按照编号删除员工 
    void modifyEmp();
    void findEmp();//查找员工 1:按姓名 2:按编号
    void sortEmp();
    void cleanFile();//清空文件
    void save();
    int getEmpNum();
    void initEmp();
    ~WorkerManager();
};