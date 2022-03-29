#include <iostream>
using namespace std;
// 赋值运算符重载
class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age);
    }
    ~Person()
    {
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
    }
    Person &operator=(Person &p)
    {
        // 应该先判断是否有属性在堆区，如果有限释放干净，然后在进行深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        m_Age = new int(*p.m_Age);
        return *this; // 链式编程思想
    }
    int *m_Age;
};
void test01()
{

    Person p1(19);
    Person p2(30);
    Person p3(20);
    p3 = p1 = p2; // 赋值操作
    cout << "p1的年龄为" << *p1.m_Age << endl;
    cout << "p2的年龄为" << *p2.m_Age << endl;
    cout << "p3的年龄为" << *p3.m_Age << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
c++编译器至少给一个类添加4个函数
    1.默认构造函数（无参，函数体为空）
    2.默认析构函数（无参，函数体为空）
    3.默认拷贝函数，对属性进行值拷贝
    4.赋值运算符，对属性进行值拷贝
如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
***********************************/