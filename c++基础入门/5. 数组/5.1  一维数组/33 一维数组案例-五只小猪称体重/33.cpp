#include <iostream>
using namespace std;
int main()
{
    int arr[] = {122, 222, 4, 5, 66};
    int max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "最重的小猪体重为：" << max << endl;
    system("pause");
    return 0;
}
/*******************************
在一个数组中记录了五只小猪的体重，找出并打印出最重的小猪
********************************/