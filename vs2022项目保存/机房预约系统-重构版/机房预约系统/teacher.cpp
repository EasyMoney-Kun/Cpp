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
	cout << "��ӭ��ʦ��" << this->m_Name << " ��¼��" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.�鿴ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.���ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.ע����¼           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;
}

void Teacher::showAllOrder()
{
	OrderFile o;
	if (o.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	//������¼����
	for (int i = 0; i < o.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << o.m_orderData[i]["date"];
		cout << " ʱ��Σ�" << (o.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << o.m_orderData[i]["stuId"];
		cout << " ����:" << o.m_orderData[i]["stuName"];
		cout << " �����ţ�" << o.m_orderData[i]["roomId"];
		string status = " ״̬��";
		//1 ����� 2��ԤԼ -1ԤԼʧ�� 0ȡ��ԤԼ
		if (o.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (o.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (o.m_orderData[i]["status"] == "-1")
		{
			status += "ԤԼʧ�ܣ����δͨ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
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
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;
	vector<int>vTemp; //����ڴ������е��±�
	int index = 1;
	int ret = 0; //ͨ��ѡ��
	for (int i = 0; i < o.m_Size; i++)
	{
		//ɸѡ
		if (o.m_orderData[i]["status"] == "1")
		{
			vTemp.push_back(i);
			cout << index++ << "��";
			cout << "ԤԼ���ڣ���" << o.m_orderData[i]["date"];
			cout << " ʱ��Σ�" << (o.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ����ţ�" << o.m_orderData[i]["stuId"];
			cout << " ѧ��������" << o.m_orderData[i]["stuName"];
			cout << " �����ţ�" << o.m_orderData[i]["roomId"];
			cout << " ״̬�������" << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0������" << endl;
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
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					//ͨ��
					o.m_orderData[vTemp[select - 1]]["status"] = "2";
				}
				else
				{
					//��ͨ��
					o.m_orderData[vTemp[select - 1]]["status"] = "-1";
				}
				o.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	system("pause");
	system("cls");
}