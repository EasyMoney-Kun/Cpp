#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int *P = &a;
    cout << "sizeof(int*)=" << sizeof(int *) << endl;
    cout << "sizeof(float*)=" << sizeof(float *) << endl;
    cout << "sizeof(double*)=" << sizeof(double *) << endl;
    cout << "sizeof(bool*)=" << sizeof(bool *) << endl;
    system("pause");
    return 0;
}
/*******************************
在32位操作系统下占4个字节
在64位操作系统下占8个字节
********************************/