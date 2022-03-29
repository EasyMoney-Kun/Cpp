#include <iostream>
using namespace std;
int main()
{
    int a = 985, b = 211;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl; // 1.两个整数相除，结果依然是整数，将小数部分去除 2.除数不能为0
    cout << a % b << endl; // 1.除数不能为0 2.两个小数不能做取模运算 3.只有整型变量可以进行取模运算
    cout << a++ << endl; //先运算后加1
    cout << ++a << endl; //先加1后运算
    system("pause");
    return 0;
}
