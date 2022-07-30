#include "menumanager.h"

MenuManager::MenuManager()
{
    //最大人数为1000
    this->m_Maxsize = 1000;

    //初始化容器
    this->initVector();

}

void MenuManager::showMenu()
{
    cout << "**************************" << endl;
    cout << "*****  1.添加联系人  *****" << endl;
    cout << "*****  2.显示联系人  *****" << endl;
    cout << "*****  3.删除联系人  *****" << endl;
    cout << "*****  4.查找联系人  *****" << endl;
    cout << "*****  5.修改联系人  *****" << endl;
    cout << "*****  6.清空联系人  *****" << endl;
    cout << "*****  0.退出通讯录  *****" << endl;
    cout << "**************************" << endl;
}

void MenuManager::initVector()
{
    this->vPer.clear();
    ifstream ifs(FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败！" << endl;
        return;
    }
    Person p;
	while (ifs >> p.name && ifs >> p.sex >> p.age && ifs >> p.phone && ifs >> p.Add)
	{
		vPer.push_back(p);
	}
    ifs.close();
}

void MenuManager::updateFile()
{
    ofstream ofs(FILE, ios::out | ios::trunc);
    for (vector<Person>::iterator it = vPer.begin(); it != vPer.end(); it++)
    {
        ofs << it->name << " " << it->sex << " " << it->age << " " << it->phone << " " << it->Add << endl;
    }
    ofs.close();
}

void MenuManager::Addperson()
{
    if (this->vPer.size() == this->m_Maxsize)
    {
        cout << "通讯录已满，无法添加!" << endl;
        return;
    }
    //创建联系人
    Person p;
    cout << "请输入姓名：";
    cin >> p.name;
    cout << "请输入性别：" << endl;
    cout << "1、男" << endl;
    cout << "2、女" << endl;
    int temp;   
    while (true)
    {
        cout << "请输入您的选择：" << endl;
        cin >> temp;
        if (temp == 1 || temp == 2)
        {
            p.sex = temp;
            break;
        }
        else
        {
            cout << "您的输入有误，请重新输入！！！" << endl;
        }
    }
    while (true)
    {
        cout << "请输入年龄：";
        cin >> temp;
        if (temp > 0 && temp < 100)
        {
            p.age = temp;
            break;
        }
        else
        {
            cout << endl;
            cout << "您输入有误，请重新输入！！！" << endl;
        }
    }
    cout << "请输入联系电话：";
    cin >> p.phone;
    cout << "请输入地址：";
    cin >> p.Add;
    cout << "添加成功！" << endl;
    //插入联系人容器
    vPer.push_back(p);
    //更新文件
    this->updateFile();
    system("pause");
    system("cls");
}

void show(Person& p)
{
    cout << "姓名：" << p.name<< " \t";
    cout << "性别：" << (p.sex==1?"男":"女") << " \t";
    cout << "年龄：" << p.age << " \t";
    cout << "电话：" << p.phone<< " \t";
    cout << "地址：" << p.Add << endl;
}
void MenuManager::showPerson()
{
    if (this->vPer.size() == 0)
    {
        cout << "记录为空！" << endl;
    }
    else
    {
        for_each(vPer.begin(), vPer.end(), show);
    }  
    system("pause");
    system("cls");
}

void MenuManager::deletePerson()
{
    if (vPer.size() == 0)
    {
        cout << "通讯录为空，请先添加人！" << endl;
        system("pause");
        system("cls");
        return;
    }
    string name;
    cout << "请输入要删除的人的姓名：";
    cin >> name;
    bool ret = 0; //0表示人不存在 1表示存在
    for (vector<Person>::iterator it = vPer.begin(); it != vPer.end();)
    {
        if (it->name == name)
        {    
            cout << "删除成功！" << endl;
            it=vPer.erase(it); //erase删除元素会返回下一个元素的迭代器 vector会重新开辟一段内存 原有迭代器为野指针 无法进行it++
            ret = true;
        }
        else
        {
            it++; //删除最后一个元素时返回 v.end() 进行++操作造成越界
        }
    }
    if (!ret)
    {
        cout << "查无此人!" << endl;  
    }
    this->updateFile();
    system("pause");
    system("cls");
}

void MenuManager::findPerson()
{
    string name;
    cout << "请输入要查找的人的姓名：";
    cin >> name;
    bool ret = 0; //0表示人不存在 1表示存在
    for (vector<Person>::iterator it = vPer.begin(); it != vPer.end(); it++)
    {
        if (it->name == name)
        {
            cout << "姓名：" << it->name << " \t";
            cout << "性别：" << (it->sex == 1 ? "男" : "女") << " \t";
            cout << "年龄：" << it->age << " \t";
            cout << "电话：" << it->phone << " \t";
            cout << "地址：" << it->Add << endl;
            ret = true;
        }
    }
    if (!ret)
    {
        cout << "查无此人!" << endl;
    }
    system("pause");
    system("cls");
}

void MenuManager::modifyPerso()
{
    string name;
    cout << "请输入要修改人的姓名：";
    cin >> name;
    bool ret = 0; //0表示人不存在 1表示存在
    for (vector<Person>::iterator it = vPer.begin(); it != vPer.end(); it++)
    {
        if (it->name == name)
        {
            cout << "原有信息：" << endl;
            cout << "姓名：" << it->name << " \t";
            cout << "性别：" << (it->sex == 1 ? "男" : "女") << " \t";
            cout << "年龄：" << it->age << " \t";
            cout << "电话：" << it->phone << " \t";
            cout << "地址：" << it->Add << endl;
            ret = true;
            cout << endl;
            cout << "修改信息：" << endl;
            int select = 0; //判断是否退出修改
            cout << "请选择是否继续，输入1继续输入0退出" << endl;
            while (true)
            {
                cin >> select;
                if (select == 0)
                {
                    break;
                }
                else
                {
                    cout << "请输入姓名：";
                    cin >> it->name;
                    cout << "请输入性别：" << endl;
                    cout << "1、男" << endl;
                    cout << "2、女" << endl;
                    int temp;
                    while (true)
                    {
                        cout << "请输入您的选择：" << endl;
                        cin >> temp;
                        if (temp == 1 || temp == 2)
                        {
                            it->sex = temp;
                            break;
                        }
                        else
                        {
                            cout << "您的输入有误，请重新输入！！！" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "请输入年龄：";
                        cin >> temp;
                        if (temp > 0 && temp < 100)
                        {
                            it->age = temp;
                            break;
                        }
                        else
                        {
                            cout << endl;
                            cout << "您输入有误，请重新输入！！！" << endl;
                        }
                    }
                    cout << "请输入联系电话：";
                    cin >> it->phone;
                    cout << "请输入地址：";
                    cin >> it->Add;
                    cout << "修改成功！" << endl;
                    break;
                }
            }
            
        }
    }
    if (!ret)
    {
        cout << "查无此人!" << endl;
    }
    this->updateFile();
    system("pause");
    system("cls");
}

void MenuManager::cleanPerson()
{
    if (vPer.size() == 0)
    {
        cout << "原有记录为空，无需清空！"<<endl;
    }
    else
    {
        //将容器清空
        this->vPer.clear();
        //更新
        this->updateFile();
        cout << "清空完成！" << endl;
    }  
    system("pause");
    system("cls");
}
