#include <iostream>
using namespace std;
template <typename T>
T Add(T a, T b)
{
    return a + b;
}
int add(int a, int b)
{
    return a + b;
}
void test01()
{
    int a = 1, b = 2;
    char c = 'c';
    cout << add(a, c); // 普通函数调用时可以发生自动类型转换（隐式类型转换）
    // cout << Add(a, c); // 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
    cout << Add<int>(a, c); // 如果利用显示指定类型的方式，则可以发生隐式类型转换
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
普通函数与函数模板区别：
普通函数调用时：普通函数调用时可以发生自动类型转换（隐式类型转换）
               函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
               如果利用显示指定类型的方式，则可以发生隐式类型转换
***********************************/