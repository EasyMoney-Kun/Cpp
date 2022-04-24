#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"
WorkerManager::WorkerManager()
{
    // 初始化属性
    // 1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        // cout << "文件不存在" << endl;
        // 初始化记录人数
        this->m_EmpNum = 0;
        // 初始化数组指针
        this->m_EmpArray = NULL;
        // 初始化文件为空标志
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 2.文件存在但数据被清空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //文件为空
        // cout << "文件为空" << endl;
        // 初始化记录人数
        this->m_EmpNum = 0;
        // 初始化数组指针
        this->m_EmpArray = NULL;
        // 初始化文件为空标志
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 3.文件存在，并且记录数据
    int num = this->get_EmpNum();
    this->m_EmpNum = num;
    // 开辟空间
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    // 将文件中的数据存入到数组中
    this->init_Emp();
    // 初始化文件不为空
    this->m_FileIsEmpty = false;
}
WorkerManager::~WorkerManager()
{
    // 堆区的内容释放并置空
    if (this->m_EmpArray != NULL)
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            if (this->m_EmpArray[i] != NULL)
            {
                delete this->m_EmpArray[i];
            }
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}
void WorkerManager::Show_Menu()
{
    cout << "**********************" << endl;
    cout << "*欢迎使用职工管理系统*" << endl;
    cout << "****0.退出管理程序****" << endl;
    cout << "****1.增加职工信息****" << endl;
    cout << "****2.显示职工信息****" << endl;
    cout << "****3.删除职工信息****" << endl;
    cout << "****4.修改职工信息****" << endl;
    cout << "****5.查找职工信息****" << endl;
    cout << "****6.按照编号排序****" << endl;
    cout << "****7.清空所有文档****" << endl;
    cout << "**********************" << endl;
    cout << endl;
};
void WorkerManager::ExitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0); // 退出程序
};
void WorkerManager::Add_Emp()
{
    cout << "请输入添加职工数量" << endl;
    int addNum = 0; // 保存用户输入的数量
    cin >> addNum;
    if (addNum > 0)
    {
        // 计算添加新空间大小
        int newSize = this->m_EmpNum + addNum; // 新空间大小=原来记录人数+新增人数
        // 开辟新空间
        Worker **newspace = new Worker *[newSize];
        // 将原来空间下数据，拷贝到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newspace[i] = this->m_EmpArray[i];
            }
        }
        // 批量添加数据
        for (int i = 0; i < addNum; i++)
        {
            int id;      // 职工编号
            string name; // 职工姓名
            int dSelect; // 部门选择
            cout << "请输入第" << i + 1 << "个新职工编号：" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个新职工姓名：" << endl;
            cin >> name;
            cout << "请选择改职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:
                break;
            }
            // 将创建的职工职责，保存到数组中
            newspace[this->m_EmpNum + i] = worker;
        }
        // 释放原有空间
        delete[] this->m_EmpArray;
        // 更改新空间的指向
        this->m_EmpArray = newspace;
        // 更新新的职工人数
        this->m_EmpNum = newSize;
        // 更新职工不为空标志
        this->m_FileIsEmpty = false;
        // 提示添加成功
        cout << "成功添加" << addNum << "名新职工" << endl;
    }
    else
    {
        cout << "您的输入有误！" << endl;
    }
    // 文件写入
    this->save();
    system("pause");
    system("cls");
};
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
};
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); // 打开文件
    int id;
    string name;
    int dId;
    int num = 0; // 初始化记录人数
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        num++;
    }
    return num;
};
void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int dId;
    int index;
    while (ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker *worker = NULL;
        if (dId == 1) // 普通职工
        {
            worker = new Employee(id, name, dId);
        }
        else if (dId == 2) // 经理
        {
            worker = new Employee(id, name, dId);
        }
        else // 老板
        {
            worker = new Boss(id, name, dId);
        }
        this->m_EmpArray[index++] = worker;
    }
    ifs.close();
};
void WorkerManager::show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或为空!" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showINfo();
        }
    }
    system("pause");
    system("cls");
};
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0; i < this->get_EmpNum(); i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
};
void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        // 按照职工编号删除
        cout << "请输入想要删除职工编号：" << endl;
        int id = 0;
        cin >> id;
        int index = this->IsExist(id);
        if (index != -1) // 职工存在并删除index位置上的人
        {
            //数据前移
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_EmpNum--; // 更新数组中记录人员的个数
            this->save();     // 数据同步到文件中
            cout << "删除成功" << endl;
        }
        else
        {
            cout << "删除失败，未找到该员工" << endl;
        }
    }
    system("pause");
    system("cls");
};
void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;
        int ret = this->IsExist(id);
        if (ret != -1)
        {
            // 查找到编号的职工
            delete this->m_EmpArray[ret];
            int newId = 0;
            string newName = "";
            int dSelect = 0;
            cout << "查到：" << id << "号职工" << endl;
            cout << "请输入新职工号：" << endl;
            cin >> newId;
            cout << "请输入新姓名：" << endl;
            cin >> newName;
            cout << "请输入岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;
            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(newId, newName, dSelect);
                break;
            case 2:
                worker = new Manager(newId, newName, dSelect);
                break;
            case 3:
                worker = new Boss(newId, newName, dSelect);
                break;
            default:
                break;
            }
            // 更新数据到数组中
            this->m_EmpArray[ret] = worker;
            cout << "修改成功！" << endl;
            //保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人！" << endl;
        }
    }
    system("pause");
    system("cls");
};
void WorkerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或者记录为空！" << endl;
    }
    else
    {
        cout << "请输入查找的方式：" << endl;
        cout << "1、按职工编号查找" << endl;
        cout << "2、按职工姓名查找" << endl;
        int select = 0;
        cin >> select;
        if (select == 1)
        {
            // 按照编号查
            int id;
            cout << "请输入查找的编号：" << endl;
            cin >> id;
            int ret = this->IsExist(id);
            if (ret != -1)
            {
                // 找到职工
                cout << "查找成功！该职工信息如下：" << endl;
                this->m_EmpArray[ret]->showINfo();
            }
            else
            {
                cout << "查找失败，查无此人！" << endl;
            }
        }
        else if (select == 2)
        {
            // 按照姓名查
            string name;
            cout << "请输入查找的姓名：" << endl;
            cin >> name;
            bool flag = false; //设置标志判断是否查找成功
            for (int i = 0; i < m_EmpNum; i++)
            {
                if (this->m_EmpArray[i]->m_Name == name)
                {
                    cout << "查找成功，职工编号为：" << this->m_EmpArray[i]->m_Id << "号职工信息如下：" << endl;
                    // 调用信息
                    this->m_EmpArray[i]->showINfo();
                    flag = true;
                }
                if (flag == false)
                {
                    cout << "查找失败，查无此人！" << endl;
                }
            }
        }
    }
    system("pause");
    system("cls");
};
void WorkerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        cout << "请选择排序方式：" << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;
        int select = 0;
        cin >> select;
        for (int i = 0; i < m_EmpNum - 1; i++)
        {
            int MinOrMax = i;
            for (int j = i + 1; j < m_EmpNum; j++)
            {
                if (select == 1) // 升序排序
                {
                    if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id)
                    {
                        MinOrMax = j;
                    }
                }
                else if (select == 2) // 降序排序
                {
                    if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id)
                    {
                        MinOrMax = j;
                    }
                }
                else
                {
                    cout << "您的输入有误！" << endl;
                    system("pause");
                    system("cls");
                    return;
                }
                if (i != MinOrMax)
                {
                    Worker *temp = this->m_EmpArray[i];
                    this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
                    this->m_EmpArray[MinOrMax] = temp;
                }
            }
        }
        cout << "排序成功！排序结果为：" << endl;
        this->save();     //排序后结果保存到文件中
        this->show_Emp(); // 展示
    }
};
void WorkerManager::Clean_File()
{
    cout << "确定清空？" << endl;
    cout << "1、确定" << endl;
    cout << "2、返回" << endl;
    int select = 0;
    cin >> select;
    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc); // 删除文件后重新创建
        ofs.close();
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                // 删除堆区的每个职工对象
                if (this->m_EmpArray[i] != NULL)
                {
                    delete this->m_EmpArray[i];
                    this->m_EmpArray[i] = NULL;
                }
            }
            // 删除堆区数组指针
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
        }
        cout << "清空成功！" << endl;
    }
    system("pause");
    system("cls");
};