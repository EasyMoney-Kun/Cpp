#include <iostream>
int add(int num1, int num2);//函数声明可以多次
int add(int num1, int num2);
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
作用：告诉编译器函数名称以及如何调用函数。函数实际主体可以单独定义
函数声明可以多次，但函数定义只有一次
********************************/