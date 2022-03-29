#include <iostream>
using namespace std;
// 发现是引用，转换为 int* const ref
void func(int &ref)
{
    ref = 100; // ref是引用，转化为*ref = 100
}
int main()
{
    int a = 10;
    //自动转换为 int * const ref = &a;指针常量时指针指向不能改，也说明为什么引用不可更改
    int &ref = a;
    ref = 20; // 内部发现ref是引用，自动帮我们转换为：*ref=20;
    cout << "a:" << a << endl;
    cout << "ref:" << ref << endl;
    func(a);
    func(ref);
    cout << "a:" << a << endl;
    cout << "ref:" << ref << endl;
    system("pause");
    return 0;
}
/***********************************
本质：引用的本质在c++内部实现是一个指针常量
结论：c++推荐用引用技术，因为语法方便，引用的本质是指针常量，但是所有的指针操作编译器都帮我们做了
***********************************/