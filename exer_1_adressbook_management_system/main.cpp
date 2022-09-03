//
//  main.cpp
//  通讯录管理系统
//
//  Created by 徐剑鹏 on 2022/5/11.
//

#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

struct Contact{
    string name;
    int age;
    string gender;
    string tel;
    string address;
};

struct addressBook{
    Contact contacts[MAX];
    int bookSize;
};

void showMenu();
void addCon(addressBook * addBook);
void showCon(addressBook addBook);
void delCon(addressBook * addBook);
void searchCon(addressBook addBook);
void modCon(addressBook * addBook);
void emptyCon(addressBook * addBook);

int main(int argc, const char * argv[]) {
    int option = 0;
    addressBook addBook;
    addBook.bookSize = 0;
    while(true){
        showMenu();
        cin >> option;//如果输入的是非int型，为什么该例中会自动赋值为0?
        cout << "option = " << option << endl;
        switch (option) {
            case 0:
                cout << "----------系统退出！----------" << endl;
                return 0;
                break;
            case 1:
                addCon(&addBook);
                break;
            case 2:
                showCon(addBook);
                break;
            case 3:
                delCon(&addBook);
                break;
            case 4:
                searchCon(addBook);
                break;
            case 5:
                modCon(&addBook);
                break;
            case 6:
                emptyCon(&addBook);
                break;
            default:
                cout << "输入有误，请重新输入！" << endl;
                break;
        }
    };
    
}

//菜单界面
void showMenu(){
    cout << "----------通讯录管理系统----------" << endl;
    cout << "----------1. 添加联系人----------" << endl;
    cout << "----------2. 显示联系人----------" << endl;
    cout << "----------3. 删除联系人----------" << endl;
    cout << "----------4. 查找联系人----------" << endl;
    cout << "----------5. 修改联系人----------" << endl;
    cout << "----------6. 清空联系人----------" << endl;
    cout << "----------0. 推出通讯录----------" << endl;
    cout << "-------------------------------" << endl;
    cout << "请选择你要执行的操作（请输入整数，否则程序会自动退出）：";
}

void addCon(addressBook * addBook){
    addBook->bookSize++;
    
    if (addBook->bookSize > MAX)
    {       
        cout << "通讯录人数已满，无法添加！" << endl;
    }else{
        cout << "请输入姓名：";
        string name;
        cin >> name;
        addBook->contacts[addBook->bookSize].name = name;
        cout << "请输入性别(男/女)： ";
        string gender;
        cin >> gender;
        addBook->contacts[addBook->bookSize].gender = gender;
        cout << "请输入年龄：";
        int age;
        cin >> age;
        addBook->contacts[addBook->bookSize].age = age;
        cout << "请输入电话号码：";
        string tel;
        cin >> tel;
        addBook->contacts[addBook->bookSize].tel = tel;
        cout << "请输入家庭地址：";
        string address;
        cin >> address;
        addBook->contacts[addBook->bookSize].address = address;
        cout << "添加成功" << endl;
    }
    
    
}
void showCon(addressBook addBook){
    if (addBook.bookSize == 0)
    {
        cout << "通讯录暂无联系人！" << endl;
    }
    for (int i = 1; i <= addBook.bookSize; i++)
    {
        cout << "联系人" << i << ": [" << addBook.contacts[i].name << "\t"
        << addBook.contacts[i].gender << "\t"
        << addBook.contacts[i].age << "\t"
        << addBook.contacts[i].tel << "\t"
        << addBook.contacts[i].address << "]" <<  endl;
    } 
}
/**
 * @brief   按照姓名删除指定联系人
 * 
 * @param addBook 
 */
void delCon(addressBook * addBook){
    if (addBook->bookSize == 0)
    {
        cout << "通讯录暂无联系人！" << endl;
    }
    cout << "请输入你要删除的联系人："; 
    string name;
    cin >> name;
    for (int i = 1; i <= addBook->bookSize; i++)
    {
        if (addBook->contacts[i].name == name)
        {
            for (int j = i; j <= addBook->bookSize; j++)
            {
                addBook->contacts[j] = addBook->contacts[j+1];
            }
            addBook->bookSize--;
        }else{
            cout << "查无此人！" << endl;
        }     
    }
    cout << "删除成功！" << endl;
}
/**
 * @brief 按照指定姓名查找联系人
 * 
 * @param addBook 
 */
void searchCon(addressBook addBook){
    if (addBook.bookSize == 0)
    {
        cout << "通讯录暂无联系人！" << endl;
    }
    cout << "请输入你要查找的联系人："; 
    string name;
    cin >> name;
    for (int i = 1; i <= addBook.bookSize; i++)
    {
        if (addBook.contacts[i].name == name)
        {
            cout << "联系人" << i << ": [" << addBook.contacts[i].name << "\t"
            << addBook.contacts[i].gender << "\t"
            << addBook.contacts[i].age << "\t"
            << addBook.contacts[i].tel << "\t"
            << addBook.contacts[i].address << "]" <<  endl; 
        }else{
            cout << "查无此人！" << endl;
        }     
    }  
}
/**
 * @brief 按照姓名修改指定联系人
 * 
 * @param addBook 
 */
void modCon(addressBook * addBook){
    cout << "请输入你要修改的联系人："; 
    string name;
    cin >> name;
    for (int i = 0; i <= addBook->bookSize; i++)
    {
        if (addBook->contacts[i].name == name)
        {
            cout << "请输入姓名：";
            string name;
            cin >> name;
            addBook->contacts[i].name = name;
            cout << "请输入性别(男/女)： ";
            string gender;
            cin >> gender;
            addBook->contacts[i].gender = gender;
            cout << "请输入年龄：";
            int age;
            cin >> age;
            addBook->contacts[i].age = age;
            cout << "请输入电话号码：";
            string tel;
            cin >> tel;
            addBook->contacts[i].tel = tel;
            cout << "请输入家庭地址：";
            string address;
            cin >> address;
            addBook->contacts[i].address = address;
            addBook->bookSize++;
            cout << "修改成功" << endl;
        }else{
            cout << "查无此人！" << endl;
        }      
    }
}
/**
 * @brief 清空联系人
 * 
 * @param addBook 
 */
void emptyCon(addressBook * addBook){
    addBook->bookSize = 0;
    cout << "已清空联系人！" << endl;
}
