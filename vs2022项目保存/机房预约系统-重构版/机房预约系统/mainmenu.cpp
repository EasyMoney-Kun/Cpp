#include "mainmenu.h"

void Main_Menu::showMenu()
{
	cout << "--------------��ӭ��������ԤԼϵͳ--------------" << endl;
	cout << endl << "�������������:" << endl;
	cout << "\t\t-------------------------------" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        1.ѧ������           |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        2.��ʦ               |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        3.����Ա             |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t|        0.�˳�               |" << endl;
	cout << "\t\t|                             |" << endl;
	cout << "\t\t-------------------------------" << endl;
}

void Main_Menu::LoginIn(string fileName, int type)
{
	//����ָ������ָ���������
	Identity* person = NULL;
	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//�ж��ļ��Ƿ����
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	//׼�������û���Ϣ
	int id = 0;
	string name;
	string pwd;

	//�ж����
	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	if (type == 1)
	{
		//ѧ�������֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "ѧ����¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ������Ӳ˵�
				this->studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ�����֤
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid && ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ���Ա�
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "��ʦ��¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//������ʦ����Ӳ˵�
				this->teacherMenu(person);
				return;
			}
		}
	}
	else
	{
		//����Ա�����֤
		string fname;
		string fpwd;
		while (ifs >> fname && ifs >> fpwd)
		{
			//���û��������Ϣ���Ա�
			if (fname == name && fpwd == pwd)
			{
				cout << "����Ա��¼��֤�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա����Ӳ˵�
				this->managerMenu(person);
				return;
			}
		}
	}
	cout << "��֤��¼ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
}

void Main_Menu::managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�
		manager->openMenu();
		//������ָ�� תΪ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;
		int select = 0;
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:
			man->addPerson();
			break;
		case 2:
			man->showPerson();
			break;
		case 3:
			man->showComputer();
			break;
		case 4:
			man->cleanFile();
			break;
		case 0:
			delete manager; //���ٶ�������
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Main_Menu::studentMenu(Identity*& student)
{
	while (true)
	{
		//�򿪲˵�
		student->openMenu();
		//������ָ��ǿתΪ����ָ��
		Student* man = (Student*)student;
		int select = 0;
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:
			man->applyOrder();
			break;
		case 2:
			man->showMyOrder();
			break;
		case 3:
			man->showAllOrder();
			break;
		case 4:
			man->cancelOrder();
			break;
		case 0:
			delete man;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

void Main_Menu::teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->openMenu();
		//������ָ��ǿתΪ����ָ��
		Teacher* man = (Teacher*)teacher;
		int select = 0;
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:
			man->showAllOrder();
			break;
		case 2:
			man->validOrder();
			break;
		case 0:
			delete man;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}
