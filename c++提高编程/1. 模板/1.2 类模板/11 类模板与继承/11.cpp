#include <iostream>
using namespace std;
template <class T>
class Base
{
public:
    T m;
};
// 子类在声明的时候，需指定出父类中T中的类型
class Son : public Base<int>
{
};
// 如果想要灵活指定父类中T类型，子类也需要变模拟
template <class T, class T1>
class Son2 : public Base<T>
{
public:
    Son2()
    {
        cout << "T1的类型为：" << typeid(T1).name() << endl;
        cout << "T的类型为：" << typeid(T).name() << endl;
    }
    T1 m1;
};
void test01()
{
    Son2<int, char> s;
}
int main()
{

    test01();
    system("pause");
    return 0;
}
/***********************************
当类模板碰到继承的时候，需要注意以下几点：
    当子类继承的父类是一个类模板时，子类在声明的时候，需指定出父类中T中的类型
    如果不指定，编译器无法给子类分配内存
    如果想灵活指定出父类中T的类型，子类也需变为模板
***********************************/