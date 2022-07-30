#include <iostream>
using namespace std;
void bubbleSort(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void printfArray(int *a, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << *a << endl;
        a++;
    }
}
int main()
{
    int arr[] = {4, 3, 6, 9, 1, 2, 10, 8, 7, 5,9,3,23,455};
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, len);
    printfArray(arr, len);
    system("pause");
    return 0;
}
/*******************************
案列：封装一个函数，利用冒泡排序，实现对整型数组的升序排序
int arr[]={4,3,6,9,1,2,10,8,7,5}
********************************/