#include <iostream>
using namespace std;
int main()
{
    int arr[2][2] = {{5, 6}, {7, 8}};
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
    cout << sizeof(arr[0][0]) << endl;
    cout << (long long)arr << endl;
    cout << (long long)arr[0] << endl;
    cout << (long long)&arr[0][0] << endl;
    system("pause");
    return 0;
}
/*******************************
作用：1.查看二位数组所占空间
      2.获取二位数组首地址
********************************/