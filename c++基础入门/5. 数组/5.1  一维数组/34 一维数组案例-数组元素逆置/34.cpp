#include <iostream>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    // for (int i = 0, j = 4; i < j; i++, j--)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    // }
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    system("pause");
    return 0;
}
/*******************************
先声明一个5个元素的数组，并将元素逆置
********************************/