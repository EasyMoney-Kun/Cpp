#include <iostream>
using namespace std;
int main()
{

    int num = 0;
    while (num < 10)//在执行循环语句的时候，程序必须提供循环的出口，否则出现死循环
    {
        cout << num << endl;
        num++;
    }
    system("pause");
    return 0;
}
/*******************************
作用：满足循环条件，执行循环语句
语法：while（循环条件）{循环语句}
翻译：只要循环条件的结果为真，就执行循环语句
********************************/