#include <iostream>
int add(int num1, int num2);
using namespace std;
int main()
{
    int a = 985, b = 211;
    cout << "sum=" << add(a, b) << endl;
    system("pause");
    return 0;
}
int add(int num1, int num2)
{
    int sum = num1 + num2;
    return sum;
}
/*******************************
作用：将代码封装，减少重复代码
函数的定义：1.返回值类型
           2.函数名
           3.参数表列
           4.函数体语句
           5.return表达式
语法：
返回值类型 函数名 (参数列表)
{
函数体语句；
return 表达式

}
********************************/