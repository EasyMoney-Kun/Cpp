#include <iostream>
using namespace std;
int main()
{
    int a = 10, b = 9, c, d;
    c = (a > b ? a : b);
    d = (a < b ? a : b);
    cout << c << endl;
    cout << d << endl;
    (a > b ? a : b) = 985;//在c++中三目运算符返回的是变量，可以继续赋值
    (a < b ? a : b) = 211;
    cout << a << endl;
    cout << b << endl;

    system("pause");
    return 0;
}
/*******************************
作用：通过三目运算符实现简单的判断
语法：表达式1？表达式2 ：表达式3
解释：
如果表达式为真，执行表达式2，并返回表达式2的结果
如果表达式为假，执行表达式3，并返回表达式3的结果
********************************/