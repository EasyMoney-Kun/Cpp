#include <iostream>
using namespace std;
int main()
{
    short num1 = 10;
    int num2 = 20;
    long num3 = 30;
    long long num4 = 40;
    cout << "short类型所占空间为：" << sizeof(short) << endl;
    cout << "int类型所占空间为：" << sizeof(int) << endl;
    cout << "long类型所占空间为：" << sizeof(long) << endl;
    cout << "long long类型所占空间为：" << sizeof(long long) << endl;
    cout << "short类型所占空间为：" << sizeof(num1) << endl;
    cout << "int类型所占空间为：" << sizeof(num2) << endl;
    cout << "long类型所占空间为：" << sizeof(num3) << endl;
    cout << "long long类型所占空间为：" << sizeof(num4) << endl;
    system("pause");
    return 0;
}
/*******************************************
利用sizeof关键字可以统计数据类型所占内存大小
语法：sizeof（数据类型/变量）
********************************************/