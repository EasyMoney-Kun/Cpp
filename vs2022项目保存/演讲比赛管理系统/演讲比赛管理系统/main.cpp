#include <iostream>
using namespace std;
#include "speechManger.h"
#include<ctime>
int main()
{
    srand((unsigned int)time(NULL));
    // �������������
    SpeechManger sm;
    int choice = 0; // �����洢�û�ѡ��
    while (true)
    {
        sm.show_Menu();
        cout << "����������ѡ��" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1: // ��ʼ�ݽ�����
            sm.start_Speech();
            break;
        case 2: // �鿴�����¼
            sm.show_Record();
            break;
        case 3: // ��ձ�����¼
            sm.clear_Record();
            break;
        case 0:
            sm.exit_System();
            break;
        default:
            system("pause");
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}
