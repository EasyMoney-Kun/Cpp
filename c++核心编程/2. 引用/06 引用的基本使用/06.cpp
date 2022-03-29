#include <iostream>
using namespace std;
int main()
{

    int a = 10;
    int &b = a;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    system("pause");
    return 0;
}
/***********************************
作用：给变量起别名
语法：数据类型 &别名 = 原名
***********************************/