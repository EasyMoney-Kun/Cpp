#include <iostream>
using namespace std;
// 类模板中的成员函数创建时机
// 类模板中成员函数在调用时才去创建
class Person1
{
public:
    void show1()
    {
        cout << "Person1" << endl;
    }
};
class Person2
{
public:
    void show2()
    {
        cout << "Person2" << endl;
    }
};
template <class T>
class MyPerson
{
public:
    T obj;
    // 类模板中的成员函数
    void func1()
    {
        obj.show1();
    }
    void func2()
    {
        obj.show2();
    }
};
void test01()
{
    MyPerson<Person2> m;
    // m.func1();
    m.func2();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
类模板中成员函数和普通类中成员函数创建时机是有区别的：
    普通类中的成员函数一开始就可以创建
    类模板中的成员函数在调用时才可以创建
***********************************/