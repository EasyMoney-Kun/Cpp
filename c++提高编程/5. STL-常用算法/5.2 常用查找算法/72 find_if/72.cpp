#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};
class GreaterFive
{
public:
    bool operator()(int val)
    {
        return val > 5;
    }
};
class GreaterTwenty
{
public:
    bool operator()(Person &p)
    {
        return p.m_Age > 2;
    }
};
//查找内置数据类型
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了：" << *it << endl;
    }
}
//查找自定义数据类型
void test02()
{
    vector<Person> v;
    Person p1("aaa", 1);
    Person p2("bbb", 2);
    Person p3("ccc", 3);
    Person p4("ddd", 4);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    vector<Person>::iterator it = find_if(v.begin(), v.end(), GreaterTwenty());
    if (it == v.end())
    {
        cout << "未找到此人" << endl;
    }
    else
    {
        cout << "找到了姓名：" << it->m_Name
             << "年龄：" << it->m_Age << endl;
    }
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************

***********************************/
