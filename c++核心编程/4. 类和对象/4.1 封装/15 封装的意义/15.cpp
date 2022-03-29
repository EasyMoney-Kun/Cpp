#include <iostream>
using namespace std;
const double PI = 3.14;
class Circle
{
public:
    int m_r;
    double calculateZc()
    {
        return 2 * PI * m_r;
    }
};
int main()
{
    Circle c1;
    c1.m_r = 10;
    cout << "圆的周长为：" << c1.calculateZc() << endl;
    system("pause");
    return 0;
}
/***********************************
c++面向对象的三大特性：封装、继承、多态
c++认为万事万物都皆为对象，对象上有其属性和行为
封装是c++面向对象的三大特性之一
封装的意义：
    将属性和行为作为一个整体，表现生活中的事五
    将属性和行为加以权限控制
封装意义一：
    在设计类的时候，属性和行为写在一起，表现事物
封装意义二：
    类在设计的时，可以吧属性和行为放在不同的权限下，加以控制
语法: class 类名{ 访问权限: 属性/行为}；
***********************************/