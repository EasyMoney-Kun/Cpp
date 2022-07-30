#pragma once
#include"head.h"
class MenuManager
{
public:
	MenuManager();
	void showMenu(); //菜单界面
	void initVector(); //初始化容器
	void updateFile(); //更新文件
	/*功能函数*/
	void Addperson(); //添加联系人
	void showPerson(); //显示联系人
	void deletePerson(); //删除联系人
	void findPerson(); //查找联系人
	void modifyPerso(); //修改联系人
	void cleanPerson(); //清空通讯录
	
	
	vector<Person> vPer; //存放通讯录里的人
	int m_Maxsize; //通讯录最大人数
};