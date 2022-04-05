#include <iostream>
using namespace std;
// 继承中同名成员处理
class Base
{
public:
    Base()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base-func()调用" << endl;
    }
    void func(int a)
    {
        cout << "Base-func(int a)调用" << endl;
    }
    int m_A;
};
class Son : public Base
{
public:
    Son()
    {
        m_A = 200;
    }
    void func()
    {
        cout << "Son-func()调用" << endl;
    }
    int m_A;
};
// 同名成员属性处理
void test01()
{
    Son s1;
    cout << "Son 下 m_A=" << s1.m_A << endl;
    cout << "Base 下 m_A=" << s1.Base::m_A << endl;
}
// 同名成员函数处理
void test02()
{
    Son s2;
    s2.func();
    s2.Base::func();
    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    s2.Base::func(10);
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢
1.访问子类同名成员 直接访问即可
2.访问父类同名成员 需要加作用域
3.当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父亲中同名函数
***********************************/