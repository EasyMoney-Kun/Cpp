#pragma once
#include <iostream>
using namespace std;
#include <string>
class Speaker
{
public:
    Speaker(string name)
    {
        this->m_Name = name;
         for (int i = 0; i < 2; i++)
         {
             this->m_Score[i] = 0;
         }
    }
	Speaker()
	{}
	string m_Name;     // 姓名
    double m_Score[2]; // 分数 最多有两轮得分
};