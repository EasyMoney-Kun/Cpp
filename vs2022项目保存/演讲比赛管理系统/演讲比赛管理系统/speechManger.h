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
// ��ƹ�����
class SpeechManger
{
public:
    // ���캯��
    SpeechManger();
    // չʾ�˵�
    void show_Menu();
    // ��ʼ����
    void start_Speech();
    // �鿴��¼
    void show_Record();
    // ����ļ�
    void clear_Record();
    // �˳�ϵͳ
    void exit_System();
    // ��������
    ~SpeechManger();
    // ��ʼ������������
    void initSpeech();
    // ����ѡ��
    void createSpeaker();
    // ��ǩ
    void speechDraw();
    // ����
    void speechContest();
    // ��ʾ�÷�
    void showScore();
    // �����¼
    void saveRecord();
    // ��ȡ��¼
    void loadRecord();
    
    
    // �ж��ļ��Ƿ�Ϊ��
    bool fileIsEmpty;
    // ��������¼������
    map<int, vector<string>> m_Record;
    // �����һ�ֱ���ѡ�ֱ������
    vector<int> v1;
    // ��һ�ֽ���ѡ�ֱ������
    vector<int> v2;
    // ����ǰ����ѡ�ֱ������
    vector<int> vVictory;
    // ��ű���Լ���Ӧ����ѡ������
    map<int, Speaker> m_Speaker;
    // ��ű�������
    int m_Index;
};
class Print
{
public:
    void operator()(int val);
};