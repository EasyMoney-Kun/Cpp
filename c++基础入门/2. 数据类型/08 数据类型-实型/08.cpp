#include <iostream>
using namespace std;
int main()
{
    float f1=1234567;
    double d1=1234567;
    int a=2e3;
    float b=2e-3;
    cout<<f1<<endl;
    cout<<d1<<endl;
    cout<<a<<endl;
    cout<<b<<endl;
    system("pause");
    return 0;
}
/************************************
实型作用：用于表示小数   
默认情况下输出一个小数，会显示六位有效数字   
浮点型变量分为两种:1.单精度float
                  2.双精度double
float   4字节   7位有效数字
double  8字节   15——16位有效数字
*************************************/