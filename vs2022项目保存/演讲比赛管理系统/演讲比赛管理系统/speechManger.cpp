#include "speechManger.h"

// ���캯��
SpeechManger::SpeechManger()
{
	// ������ʼ��
	this->initSpeech();
	// ����ѡ��
	this->createSpeaker();
	// ��ȡ��¼
	this->loadRecord();
}

// չʾ�˵�
void SpeechManger::show_Menu()
{
	cout << "**********************" << endl;
	cout << "***��ӭ�μ��ݽ�����***" << endl;
	cout << "****1.��ʼ�ݽ�����****" << endl;
	cout << "****2.�鿴�����¼****" << endl;
	cout << "****3.��ձ�����¼****" << endl;
	cout << "****0.�˳���������****" << endl;
	cout << "**********************" << endl;
}

// �˳�ϵͳ
void SpeechManger::exit_System()
{
	cout << "��ӭ�´�ʹ��!" << endl;
	system("pause");
	exit(0);
}

// ��ʼ������������
void SpeechManger::initSpeech()
{
	// ������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();

	// ��ʼ����������
	this->m_Index = 1;
}

// ����ѡ��
void SpeechManger::createSpeaker()
{
	string nameSpeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSpeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSpeed[i];
		Speaker sp(name);
		// 12��ѡ�ֱ��
		this->v1.push_back(i + 10001);
		// ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

// ��ʼ����
void SpeechManger::start_Speech()
{
	// ��һ�ֱ���
	// 1.��ǩ
	this->speechDraw();
	// 2.����
	this->speechContest();
	// 3.��ʾ����Ч��
	this->showScore();
	// �ڶ��ֱ���
	this->m_Index++;
	// 1.��ǩ
	this->speechDraw();
	// 2.����
	this->speechContest();
	// 3.��ʾ���ս��
	this->showScore();
	// 4.�������
	this->saveRecord();

	// ���ñ��� whileѭ�����뿪ʼ״̬һ��
	// ������ʼ��
	this->initSpeech();
	// ����ѡ��
	this->createSpeaker();
	// ��ȡ��¼
	this->loadRecord();
}

// �鿴��¼
void SpeechManger::show_Record()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ�Ϊ�ջ����ļ������ڣ�" << endl;
	}
	else
	{

		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��" <<
				" �ھ���ţ�" << this->m_Record[i][0] << " �÷֣�" << this->m_Record[i][1] <<
				" �Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3] <<
				" ������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
void SpeechManger::clear_Record()
{
	cout << "�Ƿ�����ļ���" << endl;
	cout << "1����" << endl;
	cout << "2����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//ȷ�����
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		// ������ʼ��
		this->initSpeech();
		// ����ѡ��
		this->createSpeaker();
		// ��ȡ��¼
		this->loadRecord();
		cout << "��ճɹ���" << endl;
		
	}
	system("pause");
	system("cls");

}
void Print::operator()(int val)
{
	cout << val << " ";
}
// ��ǩ
void SpeechManger::speechDraw()
{
	cout << "�ڡ�" << this->m_Index << "���ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(v1.begin(), v1.end());
		for_each(v1.begin(), v1.end(), Print());
		cout << endl;
	}
	else
	{
		random_shuffle(v2.begin(), v2.end());
		for_each(v2.begin(), v2.end(), Print());
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;
}

// ����
void SpeechManger::speechContest()
{
	cout << "----------------��" << this->m_Index << "�ֱ�����ʽ��ʼ----------------" << endl;
	//׼��һ����ʱ���� ���С��ɼ�
	multimap<double, int, greater<int>> groupScore;
	int num = 0; //����ͳ�ƺͼ�¼��Ա�ĸ��� 6��һ��
	vector<int> v_src; // ����ѡ�ֵ�����
	if (this->m_Index == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	// ��������ѡ�ֽ��д��
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;
		// ��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>()); // ����
		d.pop_front();                               // ȥ����߷�
		d.pop_back();                                // ȥ����ͷ�
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size(); // ƽ����
		//��ӡƽ����
		//cout << "��ţ�" << *it << " ������" << this->m_Speaker[*it].m_Name << " ��ȡƽ���֣�" << avg << endl;
		//��ƽ���ַŵ�map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//��������� �ŵ���ʱС��������
		groupScore.insert(make_pair(avg, *it));
		//ÿ����ȡ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->m_Speaker[it->second].m_Name << " �����ɼ���" << it->first << endl;
			}
			//ȡ��ǰ����
			int count = 0;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
		}
	}
	cout << "----------------��" << this->m_Index << "�ֱ�����ϣ�----------------" << endl;
	cout << endl;
	system("pause");
}

// ��ʾ�÷�
void SpeechManger::showScore()
{
	cout << "--------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�--------------" << endl;
	vector<int> v;
	if (this->m_Index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������" << this->m_Speaker[*it].m_Name << " �÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

// �����¼
void SpeechManger::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //������ķ�ʽ���ļ� -- д�ļ�
	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << " ,"
			<< m_Speaker[*it].m_Score[1] << " ,";
	}
	ofs << endl;
	//�ر��ļ�
	cout << "��¼������ϣ�" << endl;
	//�����ļ�
	fileIsEmpty = false;
	system("pause");
	system("cls");
}

// ��ȡ��¼
void SpeechManger::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //���ļ�
	//�ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ������ڣ�" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�������
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch); //�������ȡ���ַ� �Ż���
	string data;
	int index = 0;
	while (getline(ifs, data))
	{
		int pos = -1;
		int start = 0;
		vector<string> v;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp;
			v.push_back(temp);
			start = pos + 1;

		}
		this->m_Record.insert(make_pair(index, v));
		++index;
	}
	ifs.close();
	/*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << it->first << endl;
	}*/
}
// ��������
SpeechManger::~SpeechManger()
{
}
