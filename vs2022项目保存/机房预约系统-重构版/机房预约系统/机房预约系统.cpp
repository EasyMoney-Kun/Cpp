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
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:// ѧ��
			m.LoginIn(STUDENT_FILE, 1);
			break;
		case 2:// ��ʦ
			m.LoginIn(TEACHER_FILE, 2);
			break;
		case 3:// ����Ա
			m.LoginIn(ADMIN_FILE, 3);
			break;
		case 0:// �˳�
			cout << "��ӭ��һ��ʹ��!" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
