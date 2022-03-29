#include <iostream>
using namespace std;
void showValue(const int &val)
{
    // val=1000;
    cout << "val=" << val << endl;
}
int main()
{

    int a = 10;
    // 加上const之后 编译器将代码修改 int temp = 10;const int &ref=temp;
    const int &ref = 10; // 必须引用一块合法的内存
    showValue(a);
    system("pause");
    return 0;
}
/***********************************
作用：常量引用主要用来修饰形参，防止被误操作
在函数形参列表中，可以加const修饰形参，防止形参改变实参
***********************************/