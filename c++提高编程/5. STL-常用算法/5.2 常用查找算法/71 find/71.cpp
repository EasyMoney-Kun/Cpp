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
    //重载== 底层find知道如何对比Person数据类型
    bool operator==(const Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string m_Name;
    int m_Age;
};
//查找内置数据类型
void test01()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it = find(v.begin(), v.end(), 50);
    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了" << endl;
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
    vector<Person>::iterator it = find(v.begin(), v.end(), p3);
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
find 查找元素
find_if 按条件查找

adjacent_find 查找相邻重复元素

binary_search 二分查找法

count 统计元素个数
count_if 按条件统计元素个数
***********************************/