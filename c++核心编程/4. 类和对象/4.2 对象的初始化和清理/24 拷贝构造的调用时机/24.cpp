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
    Person(const Person &p)
    {
        cout << "Person拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
    }
    ~Person()
    {
        cout << "Person析构函数调用" << endl;
    }
    int m_Age;
};
// 使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    Person p1(10);
    Person p2(p1);
}
// 值传递的方式给函数参数传值
void doWork(Person p) // 值传递拷贝副本 利用拷贝构造函数
{
}
void test02()
{
    Person p;
    doWork(p);
}
Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
}
void test03()
{
    Person p;
    p = doWork2();
    cout << (int *)&p << endl;
}
int main()
{
    // test01();
    // test02();
    test03();
    system("pause");
    return 0;
}
/***********************************
拷贝构造函数调用时机：
    使用一个已经创建完毕的对象来初始化一个新对象
    值传递的方式给函数参数传值
    以值方式返回局部对象
***********************************/