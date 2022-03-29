#include <iostream>
using namespace std;
class Person
{
public:
    Person(int age)
    {
        {
            // this指针指向的是 被调用的成员函数 所属的对象
            this->age = age;
        }
    }
    Person &PersonAddAge(Person &p)
    {
        this->age += p.age;
        // this指向的的所属对象的指针，而*this指向的是对象本体
        return *this;
    }
    Person PersonAddAge1(Person &p)
    {
        this->age += p.age;
        // this指向的的所属对象的指针，而*this指向的是对象本体
        return *this;
    }
    int age;
};
// 1.解决名称冲突
void test01()
{
    Person p(19);
    cout << "p的年龄为：" << p.age << endl;
}
void test02()
{
    Person p1(10);
    Person p2(10);
    // 链式编程思想
    p1.PersonAddAge(p2).PersonAddAge(p2);
    cout << p1.age << endl;
}
void test03()
{
    Person p1(10);
    Person p2(10);
    // 链式编程思想
    p1.PersonAddAge1(p2).PersonAddAge1(p2);
    cout << p1.age << endl;
}
int main()
{
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}
/***********************************
每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码
c++通过提供特殊的对象指针，this指针，解决上述问题。this指针指向被调用的成员函数所属的对象
    this指针是隐含每一个非静态成员函数的一种指针
    this指针不需要定义，直接使用即可
this指针的用途
    当形参和成员变量同名时，可用this来区分
    在类的非静态成员函数返回对象本身，可使用return *this
***********************************/