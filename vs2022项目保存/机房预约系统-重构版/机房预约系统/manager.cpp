#include "manager.h"

Manager::Manager()
{
}

Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʶ������
	this->initVector();
}

void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.����˺�           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.�鿴�˺�           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.�鿴����           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        4.���ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.ע����¼           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;

}

void Manager::addPerson()
{
	cout << "����������˺�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	string fileName; //�����ļ���
	string tip; //��ʾid��
	ofstream ofs; //�ļ���������
	string errortip; //������ʾ
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errortip = "ְ�����ظ�������������";
	}
	//����׷�ӵķ�ʽ д�ļ�
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
	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ���" << endl;
	this->initVector(); //��ʱ����
	system("pause");
	system("cls");
	ofs.close(); //�ļ�������ر�
}

//��ӡ����
void studentPrint(Student &s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void teacherPrint(Teacher &t)
{
	cout << "ְ����ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select = 0;
	cout << "����������ѡ��";
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
	cout << "������Ϣ���£�" << endl;
	for (vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "����id��" << it->m_ComId << "  �������������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

void Manager::cleanFile()
{
	//trunc ���ļ�,��������������
	ofstream ofs(ORDER_FIEL, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	vCom.clear();
	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "ѧ��������Ϊ��" << vStu.size() << endl;
	ifs.close();
	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ʦ������Ϊ��" << vTea.size() << endl;
	ifs.close();
	//��ȡ������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
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
		//���ѧ��
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
		//�����ʦ
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
