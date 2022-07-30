#include <iostream>
using namespace std;
#include <set>
#include <string>
#include <vector>
class MyCompare
{
public:
    bool operator()(int v1, int v2) const
    {
        return v1 > v2;
    }
};
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

class comparePerson
{
public:
    bool operator()(Person p1, Person p2) const
    {
        return p1.m_Age>p2.m_Age;
    }
};

//默认数据类型
void test01()
{
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(50);
    s.insert(40);
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    set<int, MyCompare> s1;
    s1.insert(10);
    s1.insert(20);
    s1.insert(50);
    s1.insert(40);
    for (set<int, MyCompare>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
//内置数据类型
void test02()
{
    // comparePerson 指定义排序属性
    set<Person, comparePerson> s;
    Person p1("刘备", 10);
    Person p2("张飞", 20);
    Person p3("关羽", 50);
    Person p4("诸葛亮", 40);
    Person p5("诸葛亮", 130);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);

    for (set<Person, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名：" << it->m_Name
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