#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *p; // 数据类型 * 指针变量名
    p = &a;
    cout << "a的地址为：" << &a << endl;
    cout << "指针p为：" << p << endl;
    *p = 1000; // 可以通过解引用的方式来找到指针指向的内存，指针前加*代表解引用，找到指针指向的内存中的数据
    cout << "a=" << a << endl;
    cout << "*p=" << *p << endl;

    system("pause");
    return 0;
}
/*******************************
指针的作用：可以通过指针间接访问内存
内存编号是从0开始记录的，一般用十六进制数字表示
可以用指针变量保存地址
********************************/