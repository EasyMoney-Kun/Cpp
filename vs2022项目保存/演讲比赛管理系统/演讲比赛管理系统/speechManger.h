#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include<deque>
#include<string>
#include <algorithm>
#include<numeric>
#include "speaker.h"
#include<fstream>
// 设计管理类
class SpeechManger
{
public:
    // 构造函数
    SpeechManger();
    // 展示菜单
    void show_Menu();
    // 开始比赛
    void start_Speech();
    // 查看记录
    void show_Record();
    // 清空文件
    void clear_Record();
    // 退出系统
    void exit_System();
    // 析构函数
    ~SpeechManger();
    // 初始化容器和属性
    void initSpeech();
    // 创建选手
    void createSpeaker();
    // 抽签
    void speechDraw();
    // 比赛
    void speechContest();
    // 显示得分
    void showScore();
    // 保存记录
    void saveRecord();
    // 读取记录
    void loadRecord();
    
    
    // 判断文件是否为空
    bool fileIsEmpty;
    // 存放往届记录的容器
    map<int, vector<string>> m_Record;
    // 保存第一轮比赛选手编号容器
    vector<int> v1;
    // 第一轮晋级选手编号容器
    vector<int> v2;
    // 处于前三名选手编号容器
    vector<int> vVictory;
    // 存放编号以及对应具体选手容器
    map<int, Speaker> m_Speaker;
    // 存放比赛轮数
    int m_Index;
};
class Print
{
public:
    void operator()(int val);
};