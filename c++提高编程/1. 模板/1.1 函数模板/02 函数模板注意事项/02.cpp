#include <iostream>
using namespace std;
template <typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
void func()
{
    cout << "调用" << endl;
}
void test01() // 自动类型推导，必须推导出一致的数据类型T才可以使用
{
    int a = 1, b = 2;
    char c = 'c';
    MySwap(a, b); // 正确
    // MySwap(a, c);错误!推导不出一致的T类型
    cout << "a=" << a << "\t"
         << "b=" << b << endl;
}
void test02() // 模板必须要确定出T的数据类型，才可以使用
{
    // func();
    func<int>();
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************
注意事项：自动类型推导，必须推导出一致的数据类型T才可以使用
        模板必须要确定出T的数据类型，才可以使用
***********************************/