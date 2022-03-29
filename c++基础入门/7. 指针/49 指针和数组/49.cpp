#include <iostream>
using namespace std;
int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int *p = arr;
    cout << *p << endl;
    p++;
    cout << *p << endl;
    int *p1 = arr;
    for (int i = 0; i < 8; i++)
    {
        cout << *p1 << endl;
        p1++;
    }

    system("pause");
    return 0;
}
/*******************************
作用：利用指针访问数组中的元素
********************************/