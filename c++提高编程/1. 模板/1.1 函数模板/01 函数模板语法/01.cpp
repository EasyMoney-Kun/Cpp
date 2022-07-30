#include <iostream>
using namespace std;
template <typename T> // 声明一个模板，告诉编译器后面代码中紧跟着的T不要报错，T是一个通用的数据类型
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
void test01()
{
    int a = 1, b = 2;
    char c = 'c', d = 'd';
    // 自动类型推导
    MySwap(a, b);
    cout << "a=" << a << "\t"
         << "b=" << b << endl;
    MySwap(c, d);
    cout << "c=" << c << "\t"
         << "d=" << d << endl;
    // 显示指定类型
    MySwap<int>(a, b);
    cout << "a=" << a << "\t"
         << "b=" << b << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
函数模板的作用:建立一个通用函数，其函数返回值和形参类型可以不具体制定，用一个虚拟的类型来代表
语法：template<typename T>
解释：template -- 声明创建模板
      typename -- 表面即后面的符号是一种数据类型，可以用class代替
      T -- 通用的数据类型，名称可以替换，通常为大写字母
***********************************/