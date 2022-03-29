#include <iostream>
using namespace std;

class Person
{
public:
    Person()
    {
        cout << "Person构造函数调用" << endl;
    }
    Person(int age)
    {
        cout << "Person有参构造函数的调用" << endl;
        m_Age = age;
    }
    // Person(const Person &p)
    // {
    //     cout << "Person拷贝构造函数调用" << endl;
    //     m_Age = p.m_Age;
    // }
    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }
    int m_Age;
};
void test01()
{
    Person p;
    p.m_Age = 18;
    Person p1(p);
    cout << "p1的年龄为：" << p1.m_Age << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
默认情况下，c++编译期至少给一个类添加3个函数
    1.默认构造函数（无参，函数体为空）
    2.默认析构函数（无参，函数体为空）
    3.默认拷贝构造函数，对属性进行拷贝
拷贝调用规则：
    如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造
    如果用户定义拷贝构造函数，c++不会再提供其它构造函数
***********************************/