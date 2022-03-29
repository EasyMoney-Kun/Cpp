#include <iostream>
using namespace std;
int func(int a, int b, int c)
{
    return a + b + c;
}
// 如果我们自己传入数据，就用自己的数据，如果没有，那么用默认值
// 语法：返回值类型 函数名 (形参 = 默认值)
int func1(int a, int b = 20, int c = 30)
{
    return a + b + c;
}
// int func2(int a, int b = 10, int c)// 如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有有默认值
// {
//     return a + b + c;
// }

// int func3(int a = 10, int b = 10);// 如果函数声明有默认参数，函数实现就不能有默认参数
// int func3(int a = 20, int b = 20)
// {
//     return a + b;
// }
int main()

{
    cout << func(10, 20, 30) << endl;
    cout << func1(10, 30) << endl;

    system("pause");
    return 0;
}
/***********************************
在c++中形参列表中的形参是可以有默认值的
语法：返回值类型 函数名 (参数值=默认值) {}
注意事项：
    如果某个位置已经有了默认参数，那么从这个位置往后，从左到右都必须有有默认值
    如果函数声明有默认参数，函数实现就不能有默认参数,声明和实现只能有一个有默认参数
***********************************/