#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Person
{
public:
    Person(int age, string name)
    {
        this->m_Age = age;
        this->m_Name = name;
    }

    int m_Age;
    string m_Name;
};
// void print(Person p)
// {
//     cout << p.m_Age << endl;
//     cout << p.m_Name << endl;
// }
void test01()
{
    vector<Person> v;
    Person p1(10, "aaa");
    Person p2(20, "bbb");
    Person p3(30, "ccc");
    Person p4(40, "ddd");
    // 向容器中插入数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    // for_each(v.begin(), v.end(), print);
    // 遍历
    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).m_Name << "年龄：" << (*it).m_Age << endl;
    }
}
// 存放自定义数据类型指针
void test02()
{
    vector<Person *> v;
    Person p1(10, "aaa");
    Person p2(20, "bbb");
    Person p3(30, "ccc");
    Person p4(40, "ddd");
    // 向容器中插入数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    // 遍历
    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it)->m_Name << "年龄：" << (*it)->m_Age << endl;
    }
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}
/***********************************

***********************************/