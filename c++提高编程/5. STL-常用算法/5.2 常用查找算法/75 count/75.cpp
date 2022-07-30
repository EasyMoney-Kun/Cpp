#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    bool operator==(const Person &p) 
    {
        return this->m_Age == p.m_Age;
    }
    string m_Name;
    int m_Age;
};
// 内置数据类型
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    int num = count(v.begin(), v.end(), 10);
    cout << "10元素个数为：" << num << endl;
}
// 自定义数据类型
void test02()
{
    vector<Person> v;
    Person p1("aa", 1);
    Person p2("bb", 4);
    Person p3("cc", 3);
    Person p4("dd", 4);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    Person p("cc", 4);
    int num = count(v.begin(), v.end(), p);
    cout << "与p年龄相同个数为：" << num << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
count(beg,end,value)
***********************************/