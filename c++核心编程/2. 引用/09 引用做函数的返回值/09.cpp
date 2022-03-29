#include <iostream>
using namespace std;
// int &test01()
// {
//     int a = 10;
//     return a; // 不要返回局部变量引用
// }
int &test02()
{
    static int a = 20;
    return a;
}
int main()
{
    int &ref = test02();
    cout << "ref=" << ref << endl;
    test02() = 1000; // 函数调用可以作为左值
    cout << "ref=" << ref << endl;
    system("pause");
    return 0;
}
/***********************************
作用：引用是可以作为函数的返回值存在的
注意：不要返回局部变量引用
用法：函数调用可以作为左值
***********************************/