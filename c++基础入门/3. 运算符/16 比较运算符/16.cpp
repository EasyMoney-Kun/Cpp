#include <iostream>
using namespace std;
int main()
{
    int a = 985, b = 211;
    cout << (a == b) << endl;
    cout << (a != b) << endl;
    cout << (a <= b) << endl;
    cout << (a >= b) << endl;//括号提高优先级
    cout << (a > b) << endl;
    cout << (a < b) << endl;
    system("pause");
    return 0;
}
/*******************************
作用：用于表达式的比较，并返回一个真值或假值
********************************/