#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        cout << "Base的构造函数" << endl;
    }
    ~Base()
    {
        cout << "Base的析构函数" << endl;
    }
};
class Son : public Base
{
public:
    Son()
    {
        cout << "Son的构造函数" << endl;
    }
    ~Son()
    {
        cout << "Son的析构函数" << endl;
    }
};
void test01()
{

    Son s1;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
子类继承父类后，当创建子类对象，也会调用父类的构造函数
问题：父类和子类的构造和析构顺序是谁先谁后
继承中的的构造和析构顺序如下
先构造父类在构造子类，析构的顺序与构造的顺序相反
***********************************/