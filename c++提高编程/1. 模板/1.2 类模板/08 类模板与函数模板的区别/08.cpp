#include <iostream>
using namespace std;
#include <string>
// 类模板与函数模板的区别
template <class NameType, class AgeType = int> // 类模板在模板参数列表中可以有默认参数
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "name:" << this->m_Name
             << "age:" << this->m_Age << endl;
    }

    NameType m_Name;
    AgeType m_Age;
};
// 类模板没有自动推导的使用方式
void test01()
{
    Person<string, int> p1("顺", 99);
    p1.showPerson();
    // Person p2("fd", 12); // 错误
    // p2.showPerson();
}
// 类模板在模板参数列表中可以有默认参数
void test02()
{
    Person<string> p1("fd", 99);
    p1.showPerson();
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
类模板与函数模板区别有两点：
1.类模板没有自动推导的使用方式
2.类模板在模板参数列表中可以有默认参数
***********************************/