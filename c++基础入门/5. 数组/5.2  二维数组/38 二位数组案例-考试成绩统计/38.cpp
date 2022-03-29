#include <iostream>
#include <string>
using namespace std;
int main()
{
    int arr[][3] = {{100, 100, 100}, {99, 99, 99}, {98, 98, 98}};
    string name[] = {"小红", "小明", "小兰"};
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += arr[i][j];
        }
        cout << name[i] << "总成绩为：" << sum << endl;
    }

    system("pause");
    return 0;
}
/*******************************
********************************/