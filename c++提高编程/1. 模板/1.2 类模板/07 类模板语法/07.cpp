#include <iostream>
using namespace std;
template <class NameType, class AgeType>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    NameType m_Name;
    AgeType m_Age;
};
void test01()
{
    Person<string, int> p1("树", 99);
    cout << p1.m_Age << endl;
    cout << p1.m_Name << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
类模板的作用：建立一个通用类，类中的成员数据类型可以不具体制定，用一个虚拟的类型来代表
***********************************/