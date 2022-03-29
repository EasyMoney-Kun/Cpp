#include <iostream>
using namespace std;
int main()
{
    int a = 985, b = 211;
    //逻辑非
    cout << !a << endl;
    cout << !!a << endl;
    //逻辑与
    cout << (a && b) << endl;
    cout << (a && !b) << endl; //括号提高优先级
    //逻辑或
    cout << (a || b) << endl;
    cout << (!a || !b) << endl;
    system("pause");
    return 0;
}
/*******************************
作用：用于表达式的值返回真值或假值
********************************/