#include <iostream>
using namespace std;
// 常函数
class Person
{
public:
    // this指针的本质 是指针常量 指针的指向是不可以修改的
    // const Person * const this;
    // 在成员函数后面加const，修饰的是this指向，让指针指向的值也不可以修改
    void showPerson() const // 相当于修饰this的值也不可以修改
    {
        this->m_B = 100;
        // this->m_A = 200;
        // this = NULL; this指针不可以修改指针的指向的
    }
    void func()
    {
        m_A = 100;
    }
    int m_A;
    mutable int m_B; //  成员属性声明时加关键字mutable后，在常函数中依然可以修改
};
void test01()
{
    Person p;
    p.showPerson();
}
// void test02()
// {
//     const Person p;
//     // p.m_A=100;
//     p.m_B = 100; // m_B是特殊值，在常对象下也可以修改
//     p.showPerson();
//    // p.func(); // 常对象 不可以调用普通成员函数，因为普通成员函数可以修改属性
// }
int main()
{
    test01();
    // test02();
    system("pause");
    return 0;
}
/***********************************
常函数：
    成员函数后加const后我们称为这个函数为常函数
    常函数内不可以修改成员属性
    成员属性声明时加关键字mutable后，在常函数中依然可以修改
常对象：
    声明对象前加const称该对象为常对象
    常对象只能调用常函数
***********************************/