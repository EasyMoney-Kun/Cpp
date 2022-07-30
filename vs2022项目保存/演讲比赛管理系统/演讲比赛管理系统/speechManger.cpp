#include "speechManger.h"

// 构造函数
SpeechManger::SpeechManger()
{
	// 容器初始化
	this->initSpeech();
	// 创建选手
	this->createSpeaker();
	// 读取记录
	this->loadRecord();
}

// 展示菜单
void SpeechManger::show_Menu()
{
	cout << "**********************" << endl;
	cout << "***欢迎参加演讲比赛***" << endl;
	cout << "****1.开始演讲比赛****" << endl;
	cout << "****2.查看往届记录****" << endl;
	cout << "****3.清空比赛记录****" << endl;
	cout << "****0.退出比赛程序****" << endl;
	cout << "**********************" << endl;
}

// 退出系统
void SpeechManger::exit_System()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}

// 初始化容器和属性
void SpeechManger::initSpeech()
{
	// 容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Record.clear();

	// 初始化比赛轮数
	this->m_Index = 1;
}

// 创建选手
void SpeechManger::createSpeaker()
{
	string nameSpeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSpeed.size(); i++)
	{
		string name = "选手";
		name += nameSpeed[i];
		Speaker sp(name);
		// 12名选手编号
		this->v1.push_back(i + 10001);
		// 选手编号 以及对应的选手 存放到map容器中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

// 开始比赛
void SpeechManger::start_Speech()
{
	// 第一轮比赛
	// 1.抽签
	this->speechDraw();
	// 2.比赛
	this->speechContest();
	// 3.显示晋级效果
	this->showScore();
	// 第二轮比赛
	this->m_Index++;
	// 1.抽签
	this->speechDraw();
	// 2.比赛
	this->speechContest();
	// 3.显示最终结果
	this->showScore();
	// 4.保存分数
	this->saveRecord();

	// 重置比赛 while循环后与开始状态一致
	// 容器初始化
	this->initSpeech();
	// 创建选手
	this->createSpeaker();
	// 读取记录
	this->loadRecord();
}

// 查看记录
void SpeechManger::show_Record()
{
	if (this->fileIsEmpty)
	{
		cout << "文件为空或者文件不存在！" << endl;
	}
	else
	{

		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届" <<
				" 冠军编号：" << this->m_Record[i][0] << " 得分：" << this->m_Record[i][1] <<
				" 亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3] <<
				" 季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
		}
	}
	system("pause");
	system("cls");
}
void SpeechManger::clear_Record()
{
	cout << "是否清空文件？" << endl;
	cout << "1、是" << endl;
	cout << "2、否" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//确认清空
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		// 容器初始化
		this->initSpeech();
		// 创建选手
		this->createSpeaker();
		// 读取记录
		this->loadRecord();
		cout << "清空成功！" << endl;
		
	}
	system("pause");
	system("cls");

}
void Print::operator()(int val)
{
	cout << val << " ";
}
// 抽签
void SpeechManger::speechDraw()
{
	cout << "第《" << this->m_Index << "》轮比赛选手正在抽签" << endl;
	cout << "---------------------" << endl;
	cout << "抽签顺序如下：" << endl;
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

// 比赛
void SpeechManger::speechContest()
{
	cout << "----------------第" << this->m_Index << "轮比赛正式开始----------------" << endl;
	//准备一个临时容器 存放小组成绩
	multimap<double, int, greater<int>> groupScore;
	int num = 0; //用于统计和记录人员的个数 6人一组
	vector<int> v_src; // 比赛选手的容器
	if (this->m_Index == 1)
	{
		v_src = v1;
	}
	else
	{
		v_src = v2;
	}
	// 遍历所有选手进行打分
	for (vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++)
	{
		num++;
		// 评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}
		sort(d.begin(), d.end(), greater<double>()); // 排序
		d.pop_front();                               // 去除最高分
		d.pop_back();                                // 去除最低分
		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size(); // 平均分
		//打印平均分
		//cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 获取平均分：" << avg << endl;
		//将平均分放到map容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;
		//将打分数据 放到临时小组容器中
		groupScore.insert(make_pair(avg, *it));
		//每六人取出前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << this->m_Speaker[it->second].m_Name << " 比赛成绩：" << it->first << endl;
			}
			//取走前三名
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
	cout << "----------------第" << this->m_Index << "轮比赛完毕！----------------" << endl;
	cout << endl;
	system("pause");
}

// 显示得分
void SpeechManger::showScore()
{
	cout << "--------第" << this->m_Index << "轮晋级选手信息如下：--------------" << endl;
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
		cout << "选手编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;
	system("pause");
	system("cls");
	this->show_Menu();
}

// 保存记录
void SpeechManger::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); //用输出的方式打开文件 -- 写文件
	//将每个人数据写入到文件中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << " ,"
			<< m_Speaker[*it].m_Score[1] << " ,";
	}
	ofs << endl;
	//关闭文件
	cout << "记录保存完毕！" << endl;
	//更新文件
	fileIsEmpty = false;
	system("pause");
	system("cls");
}

// 读取记录
void SpeechManger::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //读文件
	//文件不存在情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在！" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件清空情况
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch); //将上面读取的字符 放回来
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
// 析构函数
SpeechManger::~SpeechManger()
{
}
