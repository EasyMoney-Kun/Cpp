#include <iostream>
using namespace std;
#include "speechManger.h"
#include <ctime>
int main()
{
    srand((unsigned int)time(NULL));
    // 创建管理类对象
    SpeechManger sm;
    int choice = 0; // 用来存储用户选项
    while (true)
    {
        sm.show_Menu();
        cout << "请输入您的选择：" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: // 开始演讲比赛
            sm.start_Speech();
            break;
        case 2: // 查看往届记录
            sm.show_Record();
            break;
        case 3: // 清空比赛记录
            sm.clear_Record();
            break;
        case 0:
            sm.exit_System();
            break;
        default:
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}
