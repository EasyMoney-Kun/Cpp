#include "orderFile.h"
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FIEL, ios::in);
	string date; //����
	string interval; //ʱ���
	string stuId; //ѧ�����
	string stuName; //ѧ������
	string roomId; //�������
	string status; //ԤԼ״̬
	this->m_Size = 0; //��¼����
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;
		substrString(date, m);
		substrString(interval, m);
		substrString(stuId, m);
		substrString(stuName, m);
		substrString(roomId, m);
		substrString(status, m);
		//��С�����ŵ���������
		//m_sizeΪ0��ʼ ���ڷ���map[i]
		m_orderData.insert(make_pair(m_Size,m));
		this->m_Size++;
	}
	ifs.close();
}

void OrderFile::updateOrder()
{
	if (this->m_Size == 0)
	{
		return;
	}
	else
	{
		ofstream ofs(ORDER_FIEL, ios::out | ios::trunc);
		for (int i = 0; i < this->m_Size; i++)
		{
			ofs << "date:" << this->m_orderData[i]["date"] << " ";
			ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
			ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
			ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
			ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
			ofs << "status:" << this->m_orderData[i]["status"] << endl;
		}
		ofs.close();
	}
}

void OrderFile::substrString(string &temp,map<string,string> &tMap)
{
	string key;
	string value;
	int pos = temp.find(":");
	if (pos != -1)
	{
		key = temp.substr(0, pos);
		value = temp.substr(pos + 1, temp.size() - pos - 1);
		tMap.insert(make_pair(key, value));
	}	
}
