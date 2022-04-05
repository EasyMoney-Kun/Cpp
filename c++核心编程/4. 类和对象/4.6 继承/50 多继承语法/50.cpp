#include <iostream>
using namespace std;
// 多继承语法
class Base
{
public:
    Base()
    {
        m_A = 100;
    }
    int m_A;
};
class Base1
{
public:
    Base1()
    {
        m_A = 200;
    }
    int m_A;
};
// 子类 需要继承Base1和Base2
class Son : public Base, public Base1
{
public:
    Son()
    {
        int m_C = 100;
        int m_D = 200;
    }
    int m_C;
    int m_D;
};
void test01()
{
    Son s;
    cout << "sizeof(son)=" << sizeof(Son) << endl;
    // 多继承可能会引发父类中有同名成员出现，需要加作用域区分
    cout << "Base::m_A=" << s.Base::m_A << endl;
    cout << "Base1::m_A=" << s.Base1::m_A << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
c++允许一个类继承多个类
语法：class 子类：继承方式 父类1 ，继承方式 父类2
多继承可能会引发父类中有同名成员出现，需要加作用域区分
但是 c++开发中不建议使用多继承
***********************************/