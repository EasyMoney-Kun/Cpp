#include <iostream>
using namespace std;
void Print(int a, int b)
{
    cout << "调用普通函数" << endl;
}
template <typename T>
void Print(T a, T b)
{
    cout << "调用模板" << endl;
}
template <typename T>
void Print(T a, T b, T c)
{
    cout << "调用重载模板" << endl;
}
void test01()
{
    int a = 1, b = 2;
    Print(a, b);
}
void test02()
{
    int a = 1, b = 2;
    Print<>(a, b);
}
void test03()
{
    Print(1, 2, 3);
}
void test04()
{
    char a = 'a', b = 'b';
    Print(a, b);
}
int main()
{
    test01(); // 如果函数模板和普通函数都可以实现，优先调用普通函数
    test02(); // 可以通过空模板参数列表来强调函数模板
    test03(); // 函数模板也可以发生重载
    test04(); // 如果函数模板可以产生更好的匹配，优先调用函数模板
    system("pause");
    return 0;
}
/***********************************
调用规则：
    1.如果函数模板和普通函数都可以实现，优先调用普通函数
    2.可以通过空模板参数列表来强调函数模板
    3.函数模板也可以发生重载
    4.如果函数模板可以产生更好的匹配，优先调用函数模板
***********************************/