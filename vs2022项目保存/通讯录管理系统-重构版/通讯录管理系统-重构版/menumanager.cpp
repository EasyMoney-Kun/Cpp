#include "menumanager.h"

MenuManager::MenuManager()
{
    //�������Ϊ1000
    this->m_Maxsize = 1000;

    //��ʼ������
    this->initVector();

}

void MenuManager::showMenu()
{
    cout << "**************************" << endl;
    cout << "*****  1.�����ϵ��  *****" << endl;
    cout << "*****  2.��ʾ��ϵ��  *****" << endl;
    cout << "*****  3.ɾ����ϵ��  *****" << endl;
    cout << "*****  4.������ϵ��  *****" << endl;
    cout << "*****  5.�޸���ϵ��  *****" << endl;
    cout << "*****  6.�����ϵ��  *****" << endl;
    cout << "*****  0.�˳�ͨѶ¼  *****" << endl;
    cout << "**************************" << endl;
}

void MenuManager::initVector()
{
    this->vPer.clear();
    ifstream ifs(FILE, ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ʧ�ܣ�" << endl;
        return;
    }
    Person p;
	while (ifs >> p.name && ifs >> p.sex >> p.age && ifs >> p.phone && ifs >> p.Add)
	{
		vPer.push_back(p);
	}
    ifs.close();
}

void MenuManager::updateFile()
{
    ofstream ofs(FILE, ios::out | ios::trunc);
    for (vector<Person>::iterator it = vPer.begin(); it != vPer.end(); it++)
    {
        ofs << it->name << " " << it->sex << " " << it->age << " " << it->phone << " " << it->Add << endl;
    }
    ofs.close();
}

void MenuManager::Addperson()
{
    if (this->vPer.size() == this->m_Maxsize)
    {
        cout << "ͨѶ¼�������޷����!" << endl;
        return;
    }
    //������ϵ��
    Person p;
    cout << "������������";
    cin >> p.name;
    cout << "�������Ա�" << endl;
    cout << "1����" << endl;
    cout << "2��Ů" << endl;
    int temp;   
    while (true)
    {
        cout << "����������ѡ��" << endl;
        cin >> temp;
        if (temp == 1 || temp == 2)
        {
            p.sex = temp;
            break;
        }
        else
        {
            cout << "���������������������룡����" << endl;
        }
    }
    while (true)
    {
        cout << "���������䣺";
        cin >> temp;
        if (temp > 0 && temp < 100)
        {
            p.age = temp;
            break;
        }
        else
        {
            cout << endl;
            cout << "�������������������룡����" << endl;
        }
    }
    cout << "��������ϵ�绰��";
    cin >> p.phone;
    cout << "�������ַ��";
    cin >> p.Add;
    cout << "��ӳɹ���" << endl;
    //������ϵ������
    vPer.push_back(p);
    //�����ļ�
    this->updateFile();
    system("pause");
    system("cls");
}

void show(Person& p)
{
    cout << "������" << p.name<< " \t";
    cout << "�Ա�" << (p.sex==1?"��":"Ů") << " \t";
    cout << "���䣺" << p.age << " \t";
    cout << "�绰��" << p.phone<< " \t";
    cout << "��ַ��" << p.Add << endl;
}
void MenuManager::showPerson()
{
    if (this->vPer.size() == 0)
    {
        cout << "��¼Ϊ�գ�" << endl;
    }
    else
    {
        for_each(vPer.begin(), vPer.end(), show);
    }  
    system("pause");
    system("cls");
}

void MenuManager::deletePerson()
{
    if (vPer.size() == 0)
    {
        cout << "ͨѶ¼Ϊ�գ���������ˣ�" << endl;
        system("pause");
        system("cls");
        return;
    }
    string name;
    cout << "������Ҫɾ�����˵�������";
    cin >> name;
    bool ret = 0; //0��ʾ�˲����� 1��ʾ����
    for (vector<Person>::iterator it = vPer.begin(); it != vPer.end();)
    {
        if (it->name == name)
        {    
            cout << "ɾ���ɹ���" << endl;
            it=vPer.erase(it); //eraseɾ��Ԫ�ػ᷵����һ��Ԫ�صĵ����� vector�����¿���һ���ڴ� ԭ�е�����ΪҰָ�� �޷�����it++
            ret = true;
        }
        else
        {
            it++; //ɾ�����һ��Ԫ��ʱ���� v.end() ����++�������Խ��
        }
    }
    if (!ret)
    {
        cout << "���޴���!" << endl;  
    }
    this->updateFile();
    system("pause");
    system("cls");
}

void MenuManager::findPerson()
{
    string name;
    cout << "������Ҫ���ҵ��˵�������";
    cin >> name;
    bool ret = 0; //0��ʾ�˲����� 1��ʾ����
    for (vector<Person>::iterator it = vPer.begin(); it != vPer.end(); it++)
    {
        if (it->name == name)
        {
            cout << "������" << it->name << " \t";
            cout << "�Ա�" << (it->sex == 1 ? "��" : "Ů") << " \t";
            cout << "���䣺" << it->age << " \t";
            cout << "�绰��" << it->phone << " \t";
            cout << "��ַ��" << it->Add << endl;
            ret = true;
        }
    }
    if (!ret)
    {
        cout << "���޴���!" << endl;
    }
    system("pause");
    system("cls");
}

void MenuManager::modifyPerso()
{
    string name;
    cout << "������Ҫ�޸��˵�������";
    cin >> name;
    bool ret = 0; //0��ʾ�˲����� 1��ʾ����
    for (vector<Person>::iterator it = vPer.begin(); it != vPer.end(); it++)
    {
        if (it->name == name)
        {
            cout << "ԭ����Ϣ��" << endl;
            cout << "������" << it->name << " \t";
            cout << "�Ա�" << (it->sex == 1 ? "��" : "Ů") << " \t";
            cout << "���䣺" << it->age << " \t";
            cout << "�绰��" << it->phone << " \t";
            cout << "��ַ��" << it->Add << endl;
            ret = true;
            cout << endl;
            cout << "�޸���Ϣ��" << endl;
            int select = 0; //�ж��Ƿ��˳��޸�
            cout << "��ѡ���Ƿ����������1��������0�˳�" << endl;
            while (true)
            {
                cin >> select;
                if (select == 0)
                {
                    break;
                }
                else
                {
                    cout << "������������";
                    cin >> it->name;
                    cout << "�������Ա�" << endl;
                    cout << "1����" << endl;
                    cout << "2��Ů" << endl;
                    int temp;
                    while (true)
                    {
                        cout << "����������ѡ��" << endl;
                        cin >> temp;
                        if (temp == 1 || temp == 2)
                        {
                            it->sex = temp;
                            break;
                        }
                        else
                        {
                            cout << "���������������������룡����" << endl;
                        }
                    }
                    while (true)
                    {
                        cout << "���������䣺";
                        cin >> temp;
                        if (temp > 0 && temp < 100)
                        {
                            it->age = temp;
                            break;
                        }
                        else
                        {
                            cout << endl;
                            cout << "�������������������룡����" << endl;
                        }
                    }
                    cout << "��������ϵ�绰��";
                    cin >> it->phone;
                    cout << "�������ַ��";
                    cin >> it->Add;
                    cout << "�޸ĳɹ���" << endl;
                    break;
                }
            }
            
        }
    }
    if (!ret)
    {
        cout << "���޴���!" << endl;
    }
    this->updateFile();
    system("pause");
    system("cls");
}

void MenuManager::cleanPerson()
{
    if (vPer.size() == 0)
    {
        cout << "ԭ�м�¼Ϊ�գ�������գ�"<<endl;
    }
    else
    {
        //���������
        this->vPer.clear();
        //����
        this->updateFile();
        cout << "�����ɣ�" << endl;
    }  
    system("pause");
    system("cls");
}
