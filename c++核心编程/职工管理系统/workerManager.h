#pragma once // 防止头文件重复包含
#include <iostream>
using namespace std;
#include "worker.h"
class WorkerManager
{
public:
    // 显示菜单
    void Show_Menu();
    // 退出系统
    void ExitSystem();
    // 添加职工
    void Add_Emp();
    // 保存文件
    void save();
    // 统计文件中的人数
    int get_EmpNum();
    // 初始化员工
    void init_Emp();
    // 显示员工
    void show_Emp();
    // 删除职工
    void Del_Emp();
    // 判断职工是否存在
    int IsExist(int id);
    // 修改职工
    void Mod_Emp();
    // 查找职工
    void Find_Emp();
    // 排序职工
    void Sort_Emp();
    // 清空文件
    void Clean_File();
    // 构造函数
    WorkerManager();
    // 析构函数
    ~WorkerManager();

    // 记录职工人数
    int m_EmpNum;
    // 职工数组指针
    Worker **m_EmpArray;
    // 标志文件是否为空
    bool m_FileIsEmpty;
};