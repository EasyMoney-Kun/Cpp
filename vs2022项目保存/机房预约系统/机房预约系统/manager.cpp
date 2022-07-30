#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初识化容器
	this->initVector();
}

void Manager::openMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.添加账号           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.查看账号           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.查看机房           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        4.清空预约           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.注销登录           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;

}

void Manager::addPerson()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	string fileName; //操作文件名
	string tip; //提示id号
	ofstream ofs; //文件操作对象
	string errortip; //错误提示
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errortip = "职工号重复，请重新输入";
	}
	//利用追加的方式 写文件
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	while (true)
	{
		cout << tip;
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功！" << endl;
	this->initVector(); //及时更新
	system("pause");
	system("cls");
	ofs.close(); //文件操作后关闭
}

//打印函数
void studentPrint(Student &s)
{
	cout << "学号：" << s.m_Id << " 姓名：" << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void teacherPrint(Teacher &t)
{
	cout << "职工编号：" << t.m_EmpId << " 姓名：" << t.m_Name << " 密码：" << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;
	int select = 0;
	cout << "请输入您的选择：";
	cin >> select;
	if (select == 1)
	{
		for_each(vStu.begin(), vStu.end(), studentPrint);
	}
	else
	{
		for_each(vTea.begin(), vTea.end(), teacherPrint);
	}
	system("pause");
	system("cls");
}

void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房id：" << it->m_ComId << "  机房最大容量：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	//trunc 打开文件,如果有内容则清空
	ofstream ofs(ORDER_FIEL, ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	vCom.clear();
	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "学生的数量为：" << vStu.size() << endl;
	ifs.close();
	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "老师的数量为：" << vTea.size() << endl;
	ifs.close();
	//读取机房信息
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
	}
	computerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << vCom.size() << endl;
	ifs.close();	
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		//检测老师
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{

			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
