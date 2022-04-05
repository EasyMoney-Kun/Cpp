#include <iostream>
using namespace std;
#include <string>
// 虚析构和纯虚析构
class Animal
{
public:
    // 纯虚函数
    Animal()
    {
        cout << "Animal的构造函数调用" << endl;
    }
    // 利用虚析构可以解决 父类指针释放子类对象时不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal的析构函数调用" << endl;
    // }
    // 纯虚析构 需要声明也需要实现
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
    virtual ~Animal() = 0;
    virtual void speak() = 0;
};
Animal::~Animal()
{
    cout << "Animal的析构函数调用" << endl;
}
class Cat : public Animal
{

public:
    Cat(string name)
    {
        cout << "Cat的构造函数调用" << endl;
        m_Name = new string(name);
    }
    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
    }
    virtual void speak()
    {
        cout << *m_Name << "小猫在说话" << endl;
    };
    string *m_Name;
};
void test01()
{
    Animal *a = new Cat("tom");
    a->speak();
    // 父类指针在析构的时候 不会调用子类中的析构函数 导致子类如果有堆区属性 就会出现内存泄漏
    delete a;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到之类的析构代码
解决方式：将父类中的析构函数改为虚析构或者纯虚析构
虚析构和纯虚析构共性
    可以解决父类指针释放子类对象
    都要有具体的函数实现
虚析构和纯虚析构的区别
如果是纯虚析构，该类属于抽象类，无法实例化对象
虚析构语法：
virtual ~类名（）{}
纯虚析构语法
virtual ~类名（）=0
类名:: ~类名（）{}
***********************************/