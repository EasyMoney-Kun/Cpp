#include"head.h"
int main()
{
	MenuManager m;
	
	int select = 0;
	while (true)
	{
		m.showMenu();
		cout << "����������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:
			m.Addperson();
			break;
		case 2:
			m.showPerson();
			break;
		case 3:
			m.deletePerson();
			break;
		case 4:
			m.findPerson();
			break;
		case 5:
			m.modifyPerso();
			break;
		case 6:
			m.cleanPerson();
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "���������������������룡" << endl;
			system("pasue");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}