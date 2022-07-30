#include<iostream>
#include "identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include"mainmenu.h"
using namespace std;
int main()
{
	int select = 0;
	Main_Menu m;
	while (true)
	{
		m.showMenu();
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1:// 学生
			m.LoginIn(STUDENT_FILE, 1);
			break;
		case 2:// 老师
			m.LoginIn(TEACHER_FILE, 2);
			break;
		case 3:// 管理员
			m.LoginIn(ADMIN_FILE, 3);
			break;
		case 0:// 退出
			cout << "欢迎下一次使用!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
