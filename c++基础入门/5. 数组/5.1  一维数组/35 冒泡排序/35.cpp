#include <iostream>
using namespace std;
int main()
{
    int arr[] = {9, 4, 1, 8, 1, 8, 4, 5, 2};
    cout << "排序前：";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
    //普通排序
    // for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    // {

    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
    // {
    //     for (int j = i + 1; j < sizeof(arr) / sizeof(arr[0]); j++)
    //     {
    //         if (arr[i] > arr[j])
    //         {
    //             int temp = arr[i];
    //             arr[i] = arr[j];
    //             arr[j] = temp;
    //         }
    //     }
    // }
    // cout << "排序后：";
    // for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    // {

    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    //冒泡排序
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++)
    {
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j+1] = temp;
            }
        }
    }
    cout << "排序后：";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {

        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
/*******************************
冒泡排序：1.比较相邻的元素，如果第一个比第二个大，就交换他们两个
         2.让每一幅相邻的元素做同样的工作，执行完毕后，找到一个最大值
         3.重复以上的步骤，每次比较次数减1，直到不需要比较
********************************/