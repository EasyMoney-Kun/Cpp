#include"head.h"
int main()
{
	MenuManager m;
	
	int select = 0;
	while (true)
	{
		m.showMenu();
		cout << "请输入您的选择：";
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
			cout << "欢迎下次使用！" << endl;
			system("pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "您的输入有误，请重新输入！" << endl;
			system("pasue");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}