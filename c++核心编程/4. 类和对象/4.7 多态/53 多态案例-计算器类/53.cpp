#include <iostream>
using namespace std;
#include <string>
// 分别利用普通技术和多态技术实现计算器

// 普通写法
class Calculator
{
public:
    int getResult(string oper)
    {
        if (oper == "+")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "-")
        {
            return m_Num1 + m_Num2;
        }
        else if (oper == "*")
        {
            return m_Num1 * m_Num2;
        }
        // 如果想扩展新的功能，需要修改源码
        // 在真正的开发中 提倡 开闭原则
        // 开闭原则；对扩展进行开发，对修改进行关闭
    }

    int m_Num1;
    int m_Num2;
};

// 利用多态实现抽象类
class AbstratCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
// 加法计算器类
class AddCalculator : public AbstratCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};
// 减法计算器类
class SubCalculator : public AbstratCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};
// 乘法计算器类
class MulCalculator : public AbstratCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};
// 除法计算器类
class Divcalculator : public AbstratCalculator
{
public:
    int getRusult()
    {
        return m_Num1 / m_Num2;
    }
};
void test01()
{
    // 创建计算器对象
    Calculator c;
    c.m_Num1 = 10;
    c.m_Num2 = 20;
    cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
    cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
    cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
}
void test02()
{
    // 多态使用条件
    // 父类指针或引用指向子类对象
    AbstratCalculator *abs = new AddCalculator;
    abs->m_Num1 = 100;
    abs->m_Num2 = 200;
    cout << abs->m_Num1
         << "+"
         << abs->m_Num2
         << "=" << abs->getResult() << endl;
    // 用完后记得销毁
    delete abs;
    abs = new SubCalculator;
    abs->m_Num1 = 100;
    abs->m_Num2 = 200;
    cout << abs->m_Num1
         << "-"
         << abs->m_Num2
         << "=" << abs->getResult() << endl;
    delete abs;
    abs = new MulCalculator;
    abs->m_Num1 = 100;
    abs->m_Num2 = 200;
    cout << abs->m_Num1
         << "*"
         << abs->m_Num2
         << "=" << abs->getResult() << endl;
    delete abs;
    abs = new Divcalculator;
    abs->m_Num1 = 100;
    abs->m_Num2 = 200;
    cout << abs->m_Num1
         << "/"
         << abs->m_Num2
         << "=" << abs->getResult() << endl;
    delete abs;
}
int main()
{
    // test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
案例描述：
分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类
多态的优点：
    代码组织结构清晰
    可读性强
    利于前期和后期的扩展以及维护
c++开发提倡利用多态设计程序架构，因为多态优点多
***********************************/