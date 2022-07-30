#include <iostream>
using namespace std;
// 交换算法
template <typename T>
void MySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 排序算法
template <typename T>
void MySort(T *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] > arr[max])
                max = j;
        }
        if (max != i)
        {
            MySwap(arr[i], arr[max]);
        }
    }
}
// 打印算法
template <typename T>
void Myprint(T *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test01()
{
    int arr[] = {1, 7, 8, 9, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    MySort(arr, len);
    Myprint(arr, len);
}
void test02()
{
    char arr[] = {'a', 'b', 'd', 'c', 'e'};
    int len = sizeof(arr) / sizeof(arr[0]);
    MySort(arr, len);
    Myprint(arr, len);
}

int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}
/***********************************

***********************************/