#pragma once
#include"head.h"
class MenuManager
{
public:
	MenuManager();
	void showMenu(); //�˵�����
	void initVector(); //��ʼ������
	void updateFile(); //�����ļ�
	/*���ܺ���*/
	void Addperson(); //�����ϵ��
	void showPerson(); //��ʾ��ϵ��
	void deletePerson(); //ɾ����ϵ��
	void findPerson(); //������ϵ��
	void modifyPerso(); //�޸���ϵ��
	void cleanPerson(); //���ͨѶ¼
	
	
	vector<Person> vPer; //���ͨѶ¼�����
	int m_Maxsize; //ͨѶ¼�������
};