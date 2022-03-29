#include <iostream>
using namespace std;
class Person
{
    friend ::ostream &operator<<(ostream &cout, Person &p);

public:
    int m_Age;
    Person();

private:
    int m_Height;
    // void operator<<(ostream &cout)
    // {
    //     cout << "age=" << age << " height=" << height << endl;
    // }
    // 不会利用成员函数重载 左移运算符 p.operator<<(cout) 简化版本为 p << cout;
};
Person::Person()
{
    m_Age = 10;
    m_Height = 140;
}
// 利用全局函数重载左移运算符
ostream &operator<<(ostream &cout, Person &p)
{
    cout << "age=" << p.m_Age<< " height=" << p. m_Height;
    return cout;
}
void test01()
{
    Person p;
    cout << p << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
作用：可以输出自定义数据类型
***********************************/