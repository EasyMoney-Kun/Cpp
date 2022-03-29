#include <iostream>
using namespace std;
#include <string>
class Phone
{
public:
    Phone(string pName)
    {
        cout << "Phone的构造函数调用" << endl;
        m_PName = pName;
    }
    ~Phone()
    {
        cout << "Phone的析构函数调用" << endl;
    }
    string m_PName;
};
class Person
{
public:
    Person(string name, string pName) : m_Name(name), m_Phone(pName) // Phone m_phone = pName  隐式法
    {
        cout << "Person的构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
    string m_Name;
    Phone m_Phone;
};
void test01()
{
    Person p("张三", "小米10");
    cout << p.m_Name << "拿着" << p.m_Phone.m_PName << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
c++类中的成员可以是另一个类的对象，我们称该成员为对象成员
B类中有对象A作为成员，A为对象成员
那么当创建B对象时，A与B的构造与析构的顺序是谁先谁后？
A先被构造后被析构，B后被构造先被析构
***********************************/