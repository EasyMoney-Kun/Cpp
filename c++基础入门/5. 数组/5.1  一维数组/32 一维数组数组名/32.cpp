#include <iostream>
using namespace std;
int main()
{
    // 1.可以统计整个数组在内存中的长度
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "整个数组占用内存空间为：" << sizeof(arr) << endl;
    cout << "每个元素占用内存空间为：" << sizeof(arr[0]) << endl;
    cout << "数组元素个数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
    // 2.可以获取数组在内存中的首地址
    cout << "数组首地址为：" << (long long)arr << endl;
    cout << "数组首地址为：" << (long long)&arr[1] << endl;
    system("pause");
    return 0;
}
/*******************************
一位数组名称的用途：
1.可以统计整个数组在内存中的长度
2.可以获取数组在内存中的首地址
********************************/