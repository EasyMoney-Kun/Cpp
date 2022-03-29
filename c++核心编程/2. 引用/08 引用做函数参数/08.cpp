#include <iostream>
using namespace std;
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void mySwap03(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int a = 10, b = 20;
    //mySwap02(&a, &b);
    mySwap03(a, b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    system("pause");
    return 0;
}
/***********************************
作用：函数传参时，可以利用方的技术让形参修饰实参
优点：可以简化指针修改实参
***********************************/