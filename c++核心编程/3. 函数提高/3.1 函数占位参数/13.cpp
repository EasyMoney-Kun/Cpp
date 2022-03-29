#include <iostream>
using namespace std;
void func(int a, int = 10) // 占位参数还可以有默认参数
{
    cout << "我是你爹" << endl;
}
int main()
{
    func(10, 10);
    system("pause");
    return 0;
}
/***********************************
c++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置
语法：返回值类型 函数名 (数据类型) {}
***********************************/