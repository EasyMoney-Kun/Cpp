#include <iostream>
using namespace std;
// 动物类
class Animal
{
public:
    int m_Age;
};
// 利用虚继承 解决菱形继承的问题
// 继承之前 加上关键字 virtual 变为虚继承
// Animal类称为虚基类

// 羊类
class Sheep : virtual public Animal
{
};
// 驼类
class Tuo : virtual public Animal
{
};
// 羊驼类
class SheepTuo : public Sheep, public Tuo
{
};
void test01()
{
    SheepTuo s1;
    s1.Sheep::m_Age = 10;
    s1.Tuo::m_Age = 28;
    // 当菱形继承，两个父类拥有相同的数据，需要加以作用域区分
    cout << "s1.Sheep::m_Age = " << s1.Sheep::m_Age << endl;
    cout << " s1.Tuo::m_Age = " << s1.Tuo::m_Age << endl;
    // 这份数据我们知道 只要有一份就可以 ，菱形继承导致数据有两份，资源浪费
    cout << "s1.m_Age=" << s1.m_Age << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
菱形继承概念：
    两个派生类继承同一个基类
    又有某个类同时继承两个派生类
    这种继承称为菱形继承，或者钻石继承
vitual底层实现
vbptr：虚基类指针
v - virtual
b - base
ptr - pointer
vbtable:虚基列表
虚基列表记录着 虚基指针的偏移量 从而找到唯一的属性
***********************************/