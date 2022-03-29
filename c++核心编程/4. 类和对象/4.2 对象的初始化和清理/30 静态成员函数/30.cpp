#include <iostream>
using namespace std;
class Person
{
public:
    static void func()
    {
        cout << "static void func的调用" << endl;
        m_A = 100;
        // m_B = 200; // 静态成员函数 不能访问 非静态成员变量，无法分别到底是那个对象的m_B属性
    }

private:
    static void func1()
    {
        cout << "static void func的调用" << endl;
    }
    static int m_A;
    int m_B;
};
int Person::m_A = 0;
void test01()
{
    // 1.通过对象访问
    Person p;
    p.func();

    // 2.通过类名访问
    Person::func();
    // Person::func1(); 静态成员函数也是有访问权限的
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
静态成员函数
        所有对象共享同一个函数
        静态成员函数只能访问静态成员变量
***********************************/