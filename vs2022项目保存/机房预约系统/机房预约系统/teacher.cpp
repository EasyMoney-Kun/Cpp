#include "teacher.h"

Teacher::Teacher()
{
}

Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::openMenu()
{
	cout << "欢迎老师：" << this->m_Name << " 登录！" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.查看预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.审核预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.注销登录           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;
}

void Teacher::showAllOrder()
{
	OrderFile o;
	if (o.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	//遍历记录容器
	for (int i = 0; i < o.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << o.m_orderData[i]["date"];
		cout << " 时间段：" << (o.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << o.m_orderData[i]["stuId"];
		cout << " 姓名:" << o.m_orderData[i]["stuName"];
		cout << " 机房号：" << o.m_orderData[i]["roomId"];
		string status = " 状态：";
		//1 审核中 2已预约 -1预约失败 0取消预约
		if (o.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (o.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (o.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder()
{
	OrderFile o;
	if (o.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;
	vector<int>vTemp; //存放在大容器中的下标
	int index = 1;
	int ret = 0; //通过选择
	for (int i = 0; i < o.m_Size; i++)
	{
		//筛选
		if (o.m_orderData[i]["status"] == "1")
		{
			vTemp.push_back(i);
			cout << index++ << "、";
			cout << "预约日期：周" << o.m_orderData[i]["date"];
			cout << " 时间段：" << (o.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学生编号：" << o.m_orderData[i]["stuId"];
			cout << " 学生姓名：" << o.m_orderData[i]["stuName"];
			cout << " 机房号：" << o.m_orderData[i]["roomId"];
			cout << " 状态：审核中" << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= vTemp.size())
		{
			if (select == 0)
				break;
			else
			{
				cout << "请输入审核结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//通过
					o.m_orderData[vTemp[select - 1]]["status"] = "2";
				}
				else
				{
					//不通过
					o.m_orderData[vTemp[select - 1]]["status"] = "-1";
				}
				o.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
	}
	system("pause");
	system("cls");
}