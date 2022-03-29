#include <iostream>
using namespace std;
class Person
{
public:
    static int m_A;

private:
    static int m_B; // 类外访问不到私有静态成员变量
};
int Person::m_A = 100; // 类内声明类外初始化
int Person::m_B = 300;
void test01()
{
    Person p;
    cout << p.m_A << endl;
    Person p1;
    p1.m_A = 200;
    cout << p.m_A << endl; // 所有对象共享一份数据
}
void test02()
{
    // 静态成员变量 不属于某个对象上，所有对象都共享一份数据
    // 因此静态成员变量有两种访问方式
    // 1.通过对象进行访问
    Person p;
    cout << p.m_A << endl;

    // 2.通过类名进行访问
    cout << Person::m_A << endl;
    // cout << p.m_B << endl;
    // cout << Person::m_B << endl;
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
静态成员就是在成员变量和成员函数前加上关键字static，成为静态成员
静态成员：
    静态成员变量
        所有对象共享一份数据
        在编译阶段分配内存
        类内声明，类外初始化
    静态成员函数
        所有对象共享同一个函数
        静态成员函数只能访问静态成员变量
***********************************/