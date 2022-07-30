#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
//学生类
class Student :public Identity
{
public:
	//默认构造
	Student();
	//有参构造
	Student(int id, string name, string pwd);
	//菜单页面
	virtual void openMenu();
	//申请预约
	void applyOrder();
	//查看自身预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();

	//初始化机房容器
	void Initvector();

	//学生学号
	int m_Id;
	//机房信息
	vector<computerRoom> vCom;
};