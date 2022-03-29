#include <iostream>
using namespace std;
int main()
{
    // 1.const 修饰指针 常量指针
    int a = 985, b = 211;
    const int *p = &a;
    // 指针指向的值不可以改，指针的指向可以改
    p = &b; // *p=20是错误的

    // 2.const 修饰常量 指针常量
    int *const p1 = &a;
    // 指针的指向不可以改，指针的值可以改
    *p1 = 100; // p=&b是错误的

    // 3.const 修饰指针和常量
    const int *const p2 = &a;
    // 指针的指向和指针指向的值都不可以改变
    //*p2 = 100;
    // p2 = &b;
    // 都是错误的
    system("pause");
    return 0;
}
/*******************************
技巧：看const右侧紧跟着的是指针还是常量，是指针就是常量指针，是常量就是指针常量
********************************/