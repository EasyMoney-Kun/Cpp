#include <iostream>
using namespace std;
// 二维数组的结构与二级指针不同 两者应该区别开来
void print1(int **arr)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << arr[i][j]<<" " ;
        }
        cout<<endl;
    }
}
void print2(int arr[2][3]) //推荐这种简洁明了 arr[i][j]
{

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
            arr[i][j] = 6;
        }
        cout<<endl;
    }
}
int main()
{
    int arr[2][3] = {{5, 6}, {7, 8}};
    print2(arr); //二维数组底层是一维数组
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout<<endl;
    }
    // int **arr1 = new int *[1];
    // for (int i = 0; i < 2; i++)
    // {
    //     arr1[i] = new int[1];
    // }
    // arr1[0][0] = 1;
    // arr1[0][5] = 2;
    // arr1[1][0] = 3;
    // arr1[1][1] = 4;
    // print1(arr1);
    system("pause");
    return 0;
}
/***********************************

***********************************/