#include <iostream>
using namespace std;
#include <string>
template <class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    void showPerson()
    {
        cout << "姓名：" << this->m_Name
             << "年龄：" << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;
};
// 指定传入类型
void PrintPerson1(Person<string, int> &p)
{
    p.showPerson();
}
void test01()
{
    Person<string, int> p("孙悟空", 1000);
    PrintPerson1(p);
}
// 参数模板化
template <class T1, class T2>
void PrintPerson2(Person<T1, T2> &p)
{
    p.showPerson();
    cout << "T1的类型为" << typeid(T1).name() << endl;
    cout << "T2的类型为" << typeid(T2).name() << endl;
}
void test02()
{
    Person<string, int> p("猪八戒", 20);
    PrintPerson2(p);
}
// 整个类模板化
template <class T>
void PrintPerson3(T &p)
{
    p.showPerson();
    cout << typeid(p).name();
}
void test03()
{
    Person<string, int> p("小刘", 22);
    PrintPerson3(p);
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
总结：
    通过类模板创建的对象，可以有三种方式向函数中进行传参
    使用比较广泛是第一种，指定传入类型
***********************************/