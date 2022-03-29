#include <iostream>
using namespace std;
#include <ctime> //time系统时间头文件包括
int main()
{
    int num = rand() % 100 + 1; // rand()%100+1生成0+1到99+1的数
    int num1 = 0;               // num1为玩家输入的数字
    int times = 0;              // times记录猜的次数
    srand((unsigned int)time(NULL));//添加随机时间种子利用当前系统生成随机数，防止生成的每次随机数都一样
    while (1)
    {
        cout << "请输入一个1到100的数字：";
        cin >> num1;
        if (num1 > num)
        {
            cout << "您输入的数字过大" << endl;
        }
        if (num1 < num)
        {
            cout << "您输入的数字过小" << endl;
        }
        if (num1 == num)
        {
            cout << "恭喜你，猜对了!!!" << endl;
            break;
        }
        times++;
        if (times == 5)
        {
            cout << "您是废物" << endl;
            break;
        }
    }
    system("pause");
    return 0;
}
/*******************************
案例需求：系统随机生成一个1到100的数字，玩家进行猜测，如果猜错，提示玩家数字过大或过小，如果猜对恭喜玩家获得胜利，并且退出游戏。
********************************/