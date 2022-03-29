#include <iostream>
using namespace std;
class Person
{
public:
    Person()
    {
        cout << "Person默认构造函数调用" << endl;
    }
    Person(int age, int height)
    {
        cout << "Person有参构造函数的调用" << endl;
        m_Age = age;
        m_Height = new int(height);
    }
    Person(const Person &p)
    {
        cout << "Person的拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
        m_Height = new int(*p.m_Height);
    }
    ~Person()
    {
        if (m_Height != NULL)
        {
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Person析构函数调用" << endl;
    }
    int m_Age;
    int *m_Height;
};
void test01()
{
    Person p1(18, 160);
    cout << "p1的年龄为" << p1.m_Age << "身高为：" << *p1.m_Height << endl;
    Person p2(p1);
    cout << "p1的年龄为" << p1.m_Age << "身高为：" << *p2.m_Height << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
浅拷贝：简单的赋值拷贝操作
深拷贝：在堆区重新申请空间，进行拷贝操作
***********************************/