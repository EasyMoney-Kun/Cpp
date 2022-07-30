#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include"orderFile.h"
#include<vector>
//教师类
class Teacher:public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int empId, string name, string pwd);
	//菜单界面
	virtual void openMenu();
	//查看所有人预约
	void showAllOrder();
	//审核预约
	void validOrder();

	//职工号
	int m_EmpId;
};