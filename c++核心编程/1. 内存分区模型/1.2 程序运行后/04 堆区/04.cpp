#include <iostream>
using namespace std;
int *func()
{
    int *a = new int(10);// 利用new关键字 将数据开辟到堆区
     // 指针 本质也是局部变量，放在栈上，指针保存的数据是放在堆区
    return a;
}
int main()
{

    int *p = func();
    cout << *p << endl;
    system("pause");
    return 0;
}
/***********************************
堆区：
    由程序员分配释放，若程序员不释放，程序结束时由操作系统回收
    在c++中由new在堆区开辟内存
***********************************/