#include <iostream>
using namespace std;
int main()
{
    int *p = (int *)0x1122;
    cout << *p << endl;//访问野指针编译没问题，运行不了
    system("pause");
    return 0;
}
/*******************************
野指针：指向非法内存空间
总结： 空指针和野指针都不是我们申请的空间，因此不要访问
********************************/