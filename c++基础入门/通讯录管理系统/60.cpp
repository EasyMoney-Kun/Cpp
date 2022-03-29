#include <iostream>
#include <string>
#define MAX 1000
using namespace std;
struct Person
{
    string name;
    int sex;
    int age;
    string phone;
    string Add;
};
struct Addressbooks
{
    Person arr[MAX];
    int size; // 记录联系人的人数
};
void showMenu()
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
void Exit()
{
    cout << "期待您下次使用！！！" << endl;
    system("pause");
}
void Addperson(Addressbooks *ads)
{
    if (ads->size == MAX)
    {
        cout << "通讯录已满，无法添加" << endl;
        return;
    }
    else
    {
        string name;
        cout << "请输入姓名：";
        cin >> name;
        ads->arr[ads->size].name = name;
        while (true)
        {
            int sex = 0;
            cout << "请输入性别（1---男 2---女）：";
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                ads->arr[ads->size].sex = sex;
                break;
            }
            else
            {
                cout << endl;
                cout << "您输入有误，请重新输入！" << endl;
            }
        }
        while (true)
        {
            int age = 0;
            cout << "请输入年龄：";
            cin >> age;
            if (age > 0 && age < 100)
            {
                ads->arr[ads->size].age = age;
                break;
            }
            else
            {
                cout << endl;
                cout << "您输入有误，请重新输入！！！" << endl;
            }
        }
        string phone;
        cout << "请输入联系电话：";
        cin >> phone;
        ads->arr[ads->size].phone = phone;
        cout << "请输入地址：";
        string add;
        cin >> add;
        ads->arr[ads->size].Add = add;
        ads->size++;
        cout << "添加成功！" << endl;
    }
    system("pause");
    system("cls");
}
void showPerson(Addressbooks *ads)
{
    if (ads->size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < ads->size; i++)
        {
            cout << "姓名：" << ads->arr[i].name << " \t";
            cout << "性别：" << (ads->arr[i].sex == 1 ? "男" : "女") << " \t";
            cout << "年龄：" << ads->arr[i].age << " \t";
            cout << "电话：" << ads->arr[i].phone << " \t";
            cout << "地址：" << ads->arr[i].Add << endl;
        }
    }
    system("pause");
    system("cls");
}
int isExist(Addressbooks *ads, string name)
{

    for (int i = 0; i < ads->size; i++)
    {
        if (ads->arr[i].name == name)
        {
            return i;
        }
    }
    return -1;
}
void deletePerson(Addressbooks *ads)
{
    string name;
    cout << "请输入要删除的人的姓名：";
    cin >> name;
    int ret = isExist(ads, name);
    if (ret != -1)
    {
        for (int i = ret; i < ads->size - 1; i++)
        {
            ads->arr[i] = ads->arr[i + 1];
        }
        ads->size--;
        cout << "删除成功！" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
void findPerson(Addressbooks *ads)
{
    string name;
    cout << "请输入要查找的人的姓名：";
    cin >> name;
    int ret = isExist(ads, name);
    if (ret != -1)
    {
        cout << "姓名：" << ads->arr[ret].name << " \t";
        cout << "性别：" << (ads->arr[ret].sex == 1 ? "男" : "女") << " \t";
        cout << "年龄：" << ads->arr[ret].age << " \t";
        cout << "电话：" << ads->arr[ret].phone << " \t";
        cout << "地址：" << ads->arr[ret].Add << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
void modifyPerson(Addressbooks *ads)
{
    string name;
    cout << "请输入要修改的人的姓名：";
    cin >> name;
    int ret = isExist(ads, name);
    if (ret != -1)
    {
        string name;
        cout << "请输入姓名：";
        cin >> name;
        ads->arr[ret].name = name;
        while (true)
        {
            int sex = 0;
            cout << "请输入性别（1---男 2---女）：";
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                ads->arr[ret].sex = sex;
                break;
            }
            else
            {
                cout << endl;
                cout << "您输入有误，请重新输入！！！" << endl;
            }
        }
        int age = 0;
        cout << "请输入年龄：";
        cin >> age;
        ads->arr[ret].age = age;
        string phone;
        cout << "请输入联系电话：";
        cin >> phone;
        ads->arr[ret].phone = phone;
        string add;
        cout << "请输入地址：";
        cin >> add;
        ads->arr[ret].Add = add;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}
void cleanPerson(Addressbooks *ads)
{
    ads->size = 0;
    cout << "通讯录已清空" << endl;
    system("pause");
    system("cls");
}
int main()
{
    int select;
    Addressbooks addressbook;
    addressbook.size = 0;
    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1:
            Addperson(&addressbook);
            break;
        case 2:
            showPerson(&addressbook);
            break;
        case 3:
            deletePerson(&addressbook);
            break;
        case 4:
            findPerson(&addressbook);
            break;
        case 5:
            modifyPerson(&addressbook);
            break;
        case 6:
            cleanPerson(&addressbook);
            break;
        case 0:
        {
            Exit();
            return 0;
        }
        break;
        }
    }
    system("pause");
    return 0;
}
// void deleteperson(Addressbooks *ads)
// {

//     if (ads->size == 0)
//     {
//         cout << "通讯录为空，请先添加人" << endl;
//     }
//     else
//     {
//         string name;
//         cout << "请输入要删除的人的姓名：";
//         cin >> name;
//         int i;
//         int direct = 1;
//         for (i = 0; i < ads->size; i++)
//         {
//             if (ads->arr[i].name == name)
//             {
//                 for (int j = i; j < ads->size - 1; j++)
//                 {
//                     ads->arr[j] = ads->arr[j + 1];
//                 }
//                 cout << "删除成功！" << endl;
//                 direct = 0;
//             }
//         }
//         if (direct)
//         {
//             cout << "查无此人，请重新输入!" << endl;
//         }
//         else
//         {
//             ads->size--;
//         }
//     }
// }