#include <iostream>
using namespace std;
// 创建全局变量
int g_a = 10;
int g_b = 10;
// 创建const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 10;
int main()
{
    // 创建普通局部变量
    int a = 10;
    int b = 10;
    cout << "局部变量a的地址为：" << (long long)&a << endl;
    cout << "局部变量b的地址为：" << (long long)&b << endl;
    cout << "全局变量g_a的地址为：" << (long long)&g_a << endl;
    cout << "全局变量g_b的地址为：" << (long long)&g_b << endl;
    // 静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a的地址为：" << (long long)&s_a << endl;
    cout << "静态变量s_b的地址为：" << (long long)&s_b << endl;
    // 常量
    // 字符串常量
    // const 修饰的变量
    // const修饰的全局变量
    // const修饰地局部变量
    cout << "字符串常量的地址为：" << (long long)&"hello world" << endl;
    cout << "全局常量c_g_a的地址为：" << (long long)&c_g_a << endl;
    cout << "全局常量c_g_b的地址为：" << (long long)&c_g_b << endl;
    // 创建const修饰的局部变量
    const int c_a = 10;
    const int c_b = 10;
    cout << "局部常量c_a的地址为：" << (long long)&c_a << endl;
    cout << "局部常量c_b的地址为：" << (long long)&c_b << endl;

    return 0;
}
/***********************************
c++程序在执行时，将内存大方向划分为4个区域
    代码区：存放函数的二进制代码，由操作系统进行管理的
    全局区：存放全局变量和静态变量以及常量
    栈区：由编译器自动分配和释放，存放函数的参数值，局部变量等
    堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
全局区：
    全局变量和静态变量存放在此
    全局区还包含了常量区，字符串常量和其他常量也存放在此
    该区域的数据在程序结束后由操作系统释放
***********************************/