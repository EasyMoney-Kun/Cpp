#include "student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化
	this->Initvector();
}

void Student::openMenu()
{
	cout << "欢迎学生代表：" << this->m_Name << " 登录！" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.申请预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.我的预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.全部预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        4.取消预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.注销登录           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;
}

void Student::applyOrder()
{
	string tip = "请输入您的选择：";
	int date; //日期
	int interval; //时间段
	int room = 0; //机房编号

	//时间申请
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	while (true)
	{
		cout << tip;
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	//时间段申请
	cout << "请输入申请预约时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cout << tip;
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	//机房申请
	cout << "请选择机房：" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << " 号机房容量为：" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cout << tip << endl;
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}
	cout << "预约成功！审核中" << endl;

	//将申请信息写入文件中
	ofstream ofs;
	ofs.open(ORDER_FIEL, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl; //status为预约状态
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
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
		//string 转int
		//string 利用c.str()转 const char *
		if (atoi(o.m_orderData[i]["stuId"].c_str()) == this->m_Id) //通过容器筛选
		{
			cout << "预约日期：周" << o.m_orderData[i]["date"];
			cout << " 时间段：" << (o.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
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
	}
	system("pause");
	system("cls");

}

void Student::showAllOrder()
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
		cout << i+1 << "、";
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

void Student::cancelOrder()
{
	OrderFile o;
	if (o.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入取消的记录" << endl;
	int index = 1; //下标索引
	vector<int>vTemp; //存放符合状态的容器下标
	//遍历记录容器
	for (int i = 0; i < o.m_Size; i++)
	{
		//初筛自身学号
		if (this->m_Id == atoi(o.m_orderData[i]["stuId"].c_str()))
		{
			//再筛选状态
			if (o.m_orderData[i]["status"] == "1" || o.m_orderData[i]["status"]=="2")
			{
				vTemp.push_back(i);
				cout << index++ << "、";
				cout << "预约日期：周" << o.m_orderData[i]["date"];
				cout << " 时间段：" << (o.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房号：" << o.m_orderData[i]["roomId"];
				string status = " 状态：";
				if (o.m_orderData[i]["status"] == "1")
				{
					status += "审核中";
				}
				else
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入取消的记录，0代表返回" << endl;
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
				o.m_orderData[vTemp[select - 1]]["status"] = "0";
				o.updateOrder();
				cout << "已取消预约" << endl;
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

void Student::Initvector()
{
	//保证起始容量一直为0
	this->vCom.clear();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	//用于接受信息并插入到容器中
	computerRoom c;
	//读取并插入
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}
