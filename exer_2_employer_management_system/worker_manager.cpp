#include "worker_manager.hpp"
WorkerManager::WorkerManager()
{

    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    //文件不存在
    if (!ifs.is_open())
    {
        cout << "file does not exit" << endl;
        //初始化属性
        this->empNum = 0;
        this->empArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件存在但是数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "file empty" << endl;
        this->empNum = 0;
        this->empArray = NULL;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    //文件存在，并存在数据
    int num = getEmpNum();
    cout << "worker numbers: " << num << endl;
    empNum = num;

    //初始化emp数组
    empArray = new Worker *[empNum];
    initEmp();

    //测试初始化代码
    // for (int i = 0; i < empNum; i++)
    // {
    //     cout << empArray[i]->wId << endl;
    // }
}
WorkerManager::~WorkerManager()
{
    if (empArray != NULL)
    {
        delete[] empArray;
        empArray = NULL;
    }
}
void WorkerManager::showMenu()
{
    cout << "********************" << endl;
    cout << "Welcom to worker management sysytem!" << endl;
    cout << "0.quit system" << endl;
    cout << "1.add workers" << endl;
    cout << "2.show workers" << endl;
    cout << "3.delete workers" << endl;
    cout << "4.modify workers" << endl;
    cout << "5.find workers" << endl;
    cout << "6.sorted by id" << endl;
    cout << "7.empty workers" << endl;
    cout << "********************" << endl;
    cout << endl;
}
void WorkerManager::exitSystem()
{
    cout << "good bye!" << endl;
    exit(0);
}
void WorkerManager::addEmp()
{
    cout << "please enter the employer numbers" << endl;
    int addNum = 0; //保存用户输入的数量
    cin >> addNum;
    if (addNum > 0)
    {
        //计算添加新空间的大小
        int newSize = empNum + addNum; //新的人数
        //开辟新空间
        Worker **newSpace = new Worker *[newSize];
        //将原来的数组数据拷贝到新数组中
        if (empArray != NULL)
        {
            for (int i = 0; i < empNum; i++)
            {
                newSpace[i] = empArray[i];
            }
        }
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect; //部门编号选择
            cout << "please enter the " << i + 1 << " new employer id:" << endl;
            cin >> id;
            cout << "please enter the " << i + 1 << " new employer name:" << endl;
            cin >> name;
            cout << "please enter the " << i + 1 << " new employer department id:" << endl;
            cout << "1: employer" << endl;
            cout << "2: manager" << endl;
            cout << "3: boss" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employer(id, name, dSelect);
                break;
            case 2:
                worker = new Manager(id, name, dSelect);
                break;
            case 3:
                worker = new Boss(id, name, dSelect);
                break;
            default:
                break;
            }
            newSpace[empNum + i] = worker; // empNum + i !!!
        }
        //释放原有的空间
        delete[] empArray;
        //更改新空间的指向
        empArray = newSpace;
        //更新一下新的员工人数
        empNum = newSize;

        cout << "add successfully " << addNum << " new worker!" << endl;
        //成功添加后保存到文件中
        save();
        //更新文件不为空标志
        fileIsEmpty = false;
    }
    else
    {
        cout << "illegal input" << endl;
    }
}
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < empNum; i++)
    {
        ofs << empArray[i]->wId << " "
            << empArray[i]->wName << " "
            << empArray[i]->wDeptId << endl;
    }
    ofs.close();
}

int WorkerManager::getEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int dId;

    int num;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    ifs.close();
    return num;
}
void WorkerManager::initEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;

    int index = 0;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;
        if (dId == 1)
        {
            worker = new Employer(id, name, dId);
        }
        else if (dId == 2)
        {
            worker = new Manager(id, name, dId);
        }
        else if (dId == 3)
        {
            worker = new Boss(id, name, dId);
        }
        empArray[index++] = worker;
    }
}
void WorkerManager::showEmp()
{
    //如果数组为空
    if (fileIsEmpty)
    {
        cout << "No worker!" << endl;
    }
    else
    {
        for (int i = 0; i < empNum; i++)
        {
            empArray[i]->showInfo();
        }
    }
}
int WorkerManager::isExist(int id)
{
    int index = -1;
    for (int i = 0; i < empNum; i++)
    {
        if (empArray[i]->wId == id)
        {
            index = i;
            break;
        }
    }
    return index;
}
void WorkerManager::deleteEmp()
{
    if (fileIsEmpty)
    {
        cout << "file not found" << endl;
    }
    else
    {
        cout << "please enter the id you want to delete" << endl;
        int id;
        cin >> id;
        int index = isExist(id);
        if (index == -1)
        {
            cout << "worker not found" << endl;
        }
        else
        {
            for (; index < empNum - 1; index++)
            {
                empArray[index] = empArray[index + 1];
            }
            empNum--;
            save();
            cout << "delete sucessfully!" << endl;
        }
    }
}
void WorkerManager::modifyEmp()
{
    if (fileIsEmpty)
    {
        cout << "file not found" << endl;
    }
    else
    {
        cout << "please enter the id you want to modify" << endl;
        int id;
        cin >> id;
        int index = isExist(id);
        if (index == -1)
        {
            cout << "worker not found" << endl;
        }
        else
        {
            delete empArray[index];
            int id = 0;
            int dId = 0;
            string name = "";
            cout << "please enter the new employer id:" << endl;
            cin >> id;
            cout << "please enter the new employer name:" << endl;
            cin >> name;
            cout << "please enter the new employer department id:" << endl;
            cout << "1: employer" << endl;
            cout << "2: manager" << endl;
            cout << "3: boss" << endl;
            cin >> dId;
            Worker *worker = NULL;
            switch (dId)
            {
            case 1:
                worker = new Employer(id, name, dId);
                break;
            case 2:
                worker = new Manager(id, name, dId);
                break;
            case 3:
                worker = new Boss(id, name, dId);
                break;
            default:
                break;
            }
            empArray[index] = worker;
            save();
            cout << "modify sucessfully!" << endl;
        }
    }
}
void WorkerManager::findEmp()
{
    if (fileIsEmpty)
    {
        cout << "file not found" << endl;
    }
    else
    {
        cout << "please choose you find mode:" << endl;
        cout << "1: by id" << endl;
        cout << "2: by name" << endl;
        int choose;
        cin >> choose;
        if (choose == 1)
        {
            cout << "please enter the id you want to find" << endl;
            int id;
            cin >> id;
            int index = isExist(id);
            if (index == -1)
            {
                cout << "worker not found" << endl;
            }
            else
            {
                empArray[index]->showInfo();
            }
        }
        else if (choose == 2)
        {
            cout << "please enter the name you want to find" << endl;
            string name;
            cin >> name;
            bool flag = false;
            for (int i = 0; i < empNum; i++)
            {
                if (empArray[i]->wName == name)
                {
                    empArray[i]->showInfo();
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "not found" << endl;
            }
        }
    }
}
void WorkerManager::sortEmp()
{
    if (fileIsEmpty)
    {
        cout << "file not found" << endl;
    }
    else
    {
        cout << "please choose your sort mode:" << endl;
        cout << "1: from small to big" << endl;
        cout << "2: from big to small" << endl;
        int choose;
        cin >> choose;
        for (int i = 0; i < empNum; i++)
        {
            int minOrMax = i;
            for (int j = i + 1; j < empNum; j++)
            {
                if (choose == 1)
                {
                    if (empArray[minOrMax]->wId > empArray[j]->wId)
                    {
                        minOrMax = j;
                    }
                }
                else if (choose == 2)
                {
                    if (empArray[minOrMax]->wId < empArray[j]->wId)
                    {
                        minOrMax = j;
                    }
                }
            }
            if (i != minOrMax)
            {
                Worker *w = empArray[i];
                empArray[i] = empArray[minOrMax];
                empArray[minOrMax] = w;
            }
        }
        save();
        cout << "sort successfully!" << endl;
    }
}
void WorkerManager::cleanFile()
{
    cout << "confirm empty?" << endl;
    cout << "1: yes" << endl;
    cout << "2: No" << endl;
    int choose;
    cin >> choose;
    if (choose == 1)
    {
        ofstream ofs(FILENAME,ios::trunc);//如果存在文件，则删除并重建 
        ofs.close();
        for(int i=0;i<empNum;i++)
        {
            if(empArray[i]!=NULL)
            {
                delete empArray[i];
            }
        }
        empNum=0;
        delete [] empArray;
        empArray = NULL;
        fileIsEmpty = true;

        cout<<"empty successfully!"<<endl;
    }
}
int main(int argc, const char *argv[])
{
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        wm.showMenu();
        cout << "please enter your choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            wm.exitSystem();
            break;
        case 1:
            wm.addEmp();
            break;
        case 2:
            wm.showEmp();
            break;
        case 3:
            wm.deleteEmp();
            break;
        case 4:
            wm.modifyEmp();
            break;
        case 5:
            wm.findEmp();
            break;
        case 6:
            wm.sortEmp();
            break;
        case 7:
            wm.cleanFile();
            break;
        default:
            break;
        }
    }
    return 0;
}