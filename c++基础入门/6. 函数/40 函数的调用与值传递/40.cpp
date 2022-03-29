#include <iostream>
void change(int num1, int num2);
using namespace std;
int main()
{
    int a = 985, b = 211;
    cout << "a=" << a << "b=" << b << endl;
    change(a,b);
    cout << "a=" << a << "b=" << b << endl;
    system("pause");
    return 0;
}
void change(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "num1=" << num1 << "num2=" << num2 << endl;
}
/*******************************
函数调用： 函数名(参数)
值传递时，形参发生改变不影响实参
********************************/