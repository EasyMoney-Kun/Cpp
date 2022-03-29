#include <iostream>
using namespace std;
int main()
{
    short num1 = 10; //=32678——32677
    int num2 = 20;
    long num3 = 30;
    long long num4 = 40;
    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;
    cout << "num3=" << num3 << endl;
    cout << "num4=" << num4 << endl;
    system("pause");
    return 0;
}
/*************************************
c++规定在创建一个变量或者常量时，必须要指定出相应的数据类型，否则无法给变量分配内存
short（短整型）：2字节  范围-2^15——2^15-1
int（整型）：4字节  范围-2^31——2^31-1
long（长整型）：4字节   范围-2^31——2^31-1
long long(长长整型号)：8字节    范围-2^63——2^63-1
**************************************/