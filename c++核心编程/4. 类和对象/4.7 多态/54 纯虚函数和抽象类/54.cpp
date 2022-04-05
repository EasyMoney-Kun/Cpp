#include <iostream>
using namespace std;
// 纯虚函数和抽象类
class Base
{
public:
    // 纯虚函数
    // 只要有一个纯虚函数，这个类称为抽象类
    virtual void func() = 0;
};
class Son : public Base
{
};
class Son1 : public Base
{
    void func()
    {
        cout << "func的调用" << endl;
    }
};
void test01()
{
    //  Base a; 无法实例化对象
    // new Base;
    // Son s; 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
    Base *base = new Son1;
    base->func();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
因此可以将虚函数改为纯虚函数
纯虚函数语法：virtual 返回值类型 函数名 （参数列表）=0;
当类中有了纯虚函数，这个类也称为抽象类
抽象类特点：
    无法实例化对象
    子类必须重写抽象类中的纯虚函数，否则也属于抽象类
***********************************/