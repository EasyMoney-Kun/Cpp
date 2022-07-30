#include<iostream>
#include "identity.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"
using namespace std;
//登录功能
void LoginIn(string fileName, int type);
//进入管理员子菜单界面
void managerMenu(Identity*& manager);
//进入学生子菜单界面
void studentMenu(Identity*& student);
//进入老师子菜单界面
void teacherMenu(Identity*& teacher);
int main()
{
	int select = 0;
	while (true)
	{
		cout << "--------------欢迎来到机房预约系统--------------" << endl;
		cout << endl << "请输入您的身份:" << endl;
		cout << "\t\t-------------------------------" << endl;
		cout << "\t\t|                             |" << endl;
		cout << "\t\t|        1.学生代表           |" << endl;
		cout << "\t\t|                             |" << endl;
		cout << "\t\t|        2.老师               |" << endl;
		cout << "\t\t|                             |" << endl;
		cout << "\t\t|        3.管理员             |" << endl;
		cout << "\t\t|                             |" << endl;
		cout << "\t\t|        0.退出               |" << endl;
		cout << "\t\t|                             |" << endl;
		cout << "\t\t-------------------------------" << endl;
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1:// 学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:// 老师
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:// 管理员
			LoginIn(ADMIN_FILE, 3);
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

void LoginIn(string fileName, int type)
{
	//父类指针用于指向子类对象
	Identity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接受用户信息
	int id = 0;
	string name;
	string pwd;
	
	//判断身份
	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//学生身份验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "学生登录验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生身份子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "老师登录验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入老师身份子菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else
	{
		//管理员身份验证
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			//与用户输入的信息做对比
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员登录验证成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员身份子菜单
				managerMenu(person);
				return;
			}
		}
	}
	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");
}

void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单
		manager->openMenu();
		//将父类指针 转为子类指针，调用子类里其他接口
		Manager* man = (Manager*)manager;
		int select = 0;
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1:
			man->addPerson();
			break;
		case 2:
			man->showPerson();
			break;
		case 3:
			man->showComputer();
			break;
		case 4:
			man->cleanFile();
			break;
		case 0:
			delete manager; //销毁堆区数据
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");	
			break;
		}
	}
}

void studentMenu(Identity*& student)
{
	while (true)
	{
		//打开菜单
		student->openMenu();
		//将父类指针强转为子类指针
		Student* man = (Student*)student;
		int select = 0;
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1:
			man->applyOrder();
			break;
		case 2:
			man->showMyOrder();
			break;
		case 3:
			man->showAllOrder();
			break;
		case 4:
			man->cancelOrder();
			break;
		case 0:
			delete man;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->openMenu();
		//将父类指针强转为子类指针
		Teacher* man = (Teacher*)teacher;
		int select = 0;
		cout << "请输入您的选择：";
		cin >> select;
		switch (select)
		{
		case 1:
			man->showAllOrder();
			break;
		case 2:
			man->validOrder();
			break;
		case 0:
			delete man;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
