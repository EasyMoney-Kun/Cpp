#include <iostream>
using namespace std;
void func()
{
    cout << "func()的调用" << endl;
}
void func(int a)
{
    cout << "func(int a)的调用" << endl;
}
void func(double a)
{
    cout << "func(double a)的调用" << endl;
}
void func(int a, double b)
{
    cout << "func(int a,double b)的调用" << endl;
}
void func(double a, int b)
{
    cout << "func(double a,int b)的调用" << endl;
}
int main()
{
    func();
    func(10);
    func(3.14);
    func(10, 3.14);
    func(3.14, 10);
    system("pause");
    return 0;
}
/***********************************
作用：函数名可以相同，提高复用性
函数重载条件：
    同一个作用域下
    函数名称相同
    函数参数 类型不同 或 个数不同 或 顺序不同
注意：函数的返回值不可以作为函数重载的条件
***********************************/