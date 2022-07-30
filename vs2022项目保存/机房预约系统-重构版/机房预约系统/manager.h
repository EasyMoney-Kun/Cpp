#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<fstream>
#include"globalFile.h"
#include<vector>
#include "student.h"
#include "teacher.h"
#include"computerRoom.h"
#include<algorithm>
class Manager:public Identity
{
public:
	//普通构造
	Manager();
	//有参构造
	Manager(string name, string pwd);
	//菜单界面
	virtual void openMenu();
	//添加账号
	void addPerson();
	//查看账号
	void showPerson();
	//查看机房信息
	void showComputer();
	//清空预约记录
	void cleanFile();
	
	//初始化容器
	void initVector();
	//检测重复 参数1 检测学号/职工号 参数2 检测类型
	bool checkRepeat(int id, int type);

	//学生容器
	vector<Student> vStu;
	//老师容器
	vector<Teacher> vTea;
	//机房容器
	vector<computerRoom> vCom;
};