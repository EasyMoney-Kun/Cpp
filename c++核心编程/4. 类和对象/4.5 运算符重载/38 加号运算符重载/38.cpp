#include <iostream>
using namespace std;
class Person
{
public:
    int age;
    int height;
    // // 成员函数重载+号
    // Person operator+(Person &p)
    // {
    //     Person temp;
    //     temp.age = this->age + p.age;
    //     temp.height = this->height + p.height;
    //     return temp;
    // }
    Person personAdd(Person &p)
    {
        Person temp;
        temp.age = this->age + p.age;
        temp.height = this->height + p.height;
        return temp;
    }
};
// 全局函数重载+号
Person operator+(Person &p1, Person &p2)
{
    Person temp;
    temp.age = p1.age + p2.age;
    temp.height = p1.height + p2.height;
    return temp;
}
Person operator+(Person &p1, int num)
{
    Person temp;
    temp.age = p1.age + num;
    temp.height = p1.height + num;
    return temp;
}
void test01()
{
    Person p1;
    Person p2;
    Person p3;
    p1.age = 10;
    p1.height = 190;
    p2.age = 20;
    p2.height = 120;
    cout << p1.personAdd(p2).age << endl;
    cout << p1.personAdd(p2).height << endl;
    cout << (p1 + p2).age << endl;
    cout << (p1 + p2).height << endl;
    cout << (p1 + 10).age << endl;
    cout << (p1 + 10).height << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

成员函数本质调用
Person p1.operator(p2)
Person p1+p2
全局函数本质调用
Person operator(p1,p2)
Person p1+p2
总结：
    对于内置的数据类型的表达式的运算符是不可能改变的
    不要滥用运算符
***********************************/