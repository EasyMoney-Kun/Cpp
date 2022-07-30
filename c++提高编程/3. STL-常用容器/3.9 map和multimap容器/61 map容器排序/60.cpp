#include <iostream>
using namespace std;
#include <map>
#include <string>
class myCompare
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
class PersonCompare
{

public:
    bool operator()(Person p1, Person p2) const
    {
        p1.m_Age > p2.m_Age;
    }
};
void test01()
{
    map<int, int, myCompare> m1;
    m1.insert(make_pair(1, 10));
    m1.insert(make_pair(2, 30));
    m1.insert(make_pair(4, 20));
    m1.insert(make_pair(3, 30));
    for (map<int, int, myCompare>::iterator it = m1.begin(); it != m1.end(); it++)
    {
        cout << (*it).first << " " << (*it).second << endl;
    }
}
void test02()
{
    map<Person, int, PersonCompare> m1;
    Person p1("a", 1);
    Person p2("b", 2);
    Person p3("c", 3);
    Person p4("d", 4);
    m1.insert(make_pair(p1, 10));
    m1.insert(make_pair(p2, 20));
    m1.insert(make_pair(p3, 30));
    m1.insert(make_pair(p4, 40));
    for (map<Person, int, PersonCompare>::iterator it = m1.begin(); it != m1.end(); it++)
    {
        cout << (*it).first.m_Age << " " << (*it).first.m_Name << " " << (*it).second << endl;
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