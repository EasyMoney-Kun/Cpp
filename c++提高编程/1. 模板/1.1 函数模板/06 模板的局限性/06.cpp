#include <iostream>
using namespace std;
#include <string>

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
template <typename T>
bool myCompare(T &a, T &b) // 自定义数据类型不行
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 利用具体化Person的版本实现代码，具体化有限调用
template <>
bool myCompare(Person &p1, Person &p2)
{
    if (p1.m_Age == p2.m_Age && p1.m_Name == p2.m_Name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test01()
{
    int a = 1, b = 1;
    bool ret = myCompare(a, b);
    if (ret)
        cout << "相等" << endl;
    else
        cout << "不等" << endl;
}
void test02()
{
    Person p1("ton", 10);
    Person p2("ton", 10);
    bool ret = myCompare(p1, p2);
    if (ret)
        cout << "相等" << endl;
    else
        cout << "不等" << endl;
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
局限性：
    模板的通用性并不是万能的
总结：
    利用具体化的模板，可以解决自定义类型的通用化
    学习模板并不是为了写模板，而是在STL中能够运用系统提供的模板
***********************************/