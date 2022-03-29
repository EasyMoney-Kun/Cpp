#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &b = a;
    //引用必须初始化 int &b;为错误

    int c = 20;
    b = c;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl;
    system("pause");
    return 0;
}
/***********************************
引用必须初始化
引用在初始化后不可以改变
***********************************/