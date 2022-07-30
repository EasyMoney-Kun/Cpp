#include "student.h"

Student::Student()
{
}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��
	this->Initvector();
}

void Student::openMenu()
{
	cout << "��ӭѧ������" << this->m_Name << " ��¼��" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.����ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.�ҵ�ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.ȫ��ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        4.ȡ��ԤԼ           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.ע����¼           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;
}

void Student::applyOrder()
{
	string tip = "����������ѡ��";
	int date; //����
	int interval; //ʱ���
	int room = 0; //�������

	//ʱ������
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	while (true)
	{
		cout << tip;
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	//ʱ�������
	cout << "����������ԤԼʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cout << tip;
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	//��������
	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << " �Ż�������Ϊ��" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cout << tip << endl;
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	//��������Ϣд���ļ���
	ofstream ofs;
	ofs.open(ORDER_FIEL, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl; //statusΪԤԼ״̬
	ofs.close();
	system("pause");
	system("cls");
}

void Student::showMyOrder()
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
		//string תint
		//string ����c.str()ת const char *
		if (atoi(o.m_orderData[i]["stuId"].c_str()) == this->m_Id) //ͨ������ɸѡ
		{
			cout << "ԤԼ���ڣ���" << o.m_orderData[i]["date"];
			cout << " ʱ��Σ�" << (o.m_orderData[i]["interval"] == "1" ? "����" : "����");
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
	}
	system("pause");
	system("cls");

}

void Student::showAllOrder()
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
		cout << i+1 << "��";
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

void Student::cancelOrder()
{
	OrderFile o;
	if (o.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	int index = 1; //�±�����
	vector<int>vTemp; //��ŷ���״̬�������±�
	//������¼����
	for (int i = 0; i < o.m_Size; i++)
	{
		//��ɸ����ѧ��
		if (this->m_Id == atoi(o.m_orderData[i]["stuId"].c_str()))
		{
			//��ɸѡ״̬
			if (o.m_orderData[i]["status"] == "1" || o.m_orderData[i]["status"]=="2")
			{
				vTemp.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ���ڣ���" << o.m_orderData[i]["date"];
				cout << " ʱ��Σ�" << (o.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " �����ţ�" << o.m_orderData[i]["roomId"];
				string status = " ״̬��";
				if (o.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
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
				cout << "��ȡ��ԤԼ" << endl;
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

void Student::Initvector()
{
	//��֤��ʼ����һֱΪ0
	this->vCom.clear();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	//���ڽ�����Ϣ�����뵽������
	computerRoom c;
	//��ȡ������
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	ifs.close();
}
