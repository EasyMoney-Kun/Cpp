#include <iostream>
void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
using namespace std;
int main()
{
    int a = 985, b = 211;
    swap(&a, &b);
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    system("pause");
    return 0;
}
/*******************************
作用：利用指针做函数的参数，可以修改实参的值
********************************/