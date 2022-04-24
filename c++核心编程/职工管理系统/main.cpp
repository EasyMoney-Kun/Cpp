#include <iostream>
using namespace std;
#include "workerManager.h"
#include "employee.h"
#include "worker.h"
#include "manager.h"
#include "boss.h"
int main()
{
    WorkerManager wm;
    int choice;
    while (true)
    {
        // 调用展示菜单成员函数
        wm.Show_Menu();
        cout << "请输入您的选择：" << endl;
        cin >> choice; // 接受用户的选项
        switch (choice)
        {
        case 0: // 退出系统
            wm.ExitSystem();
            break;
        case 1: // 增加员工
            wm.Add_Emp();
            break;
        case 2: // 显示员工
            wm.show_Emp();
            break;
        case 3: // 删除员工
            wm.Del_Emp();
            break;
        case 4: // 修改职工
            wm.Mod_Emp();
            break;
        case 5: // 查找职工
            wm.Find_Emp();
            break;
        case 6: // 排序职工
            wm.Sort_Emp();
            break;
        case 7: // 清空文档
            wm.Clean_File();
            break;
        default:
            system("cls"); //清屏
            break;
        }
    }
    system("pause");
    return 0;
}
