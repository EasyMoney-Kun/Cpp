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
	//չʾ�˵�
	void showMenu();

	//��¼����
	void LoginIn(string fileName, int type);
	//�������Ա�Ӳ˵�����
	void managerMenu(Identity*& manager);
	//����ѧ���Ӳ˵�����
	void studentMenu(Identity*& student);
	//������ʦ�Ӳ˵�����
	void teacherMenu(Identity*& teacher);

};