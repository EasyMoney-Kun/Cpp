#pragma once
#include"identity.h"
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"
#include<fstream>
class Main_Menu
{
public:
	//展示菜单
	void showMenu();

	//登录功能
	void LoginIn(string fileName, int type);
	//进入管理员子菜单界面
	void managerMenu(Identity*& manager);
	//进入学生子菜单界面
	void studentMenu(Identity*& student);
	//进入老师子菜单界面
	void teacherMenu(Identity*& teacher);

};