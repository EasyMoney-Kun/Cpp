#include <iostream>
#define Day 7
using namespace std;
int main()
{

    cout << "一周一共有" << Day << "天" << endl;
    const int month = 12;
    cout << "一年一共有" << month << "月" << endl;
    system("pause");
    return 0;
}
/************************************
常量的作用：用于记录程序中不可更改的数据
1.#define 宏常量：#define 常量名 常量值
通常在文件上方定义，表示一个常量
2.const 修饰的变量：const 数据类型 常量名 =常量值
通常在变量定义面前加关键字const，修饰该变量为常量，不可修改
**************************************/
