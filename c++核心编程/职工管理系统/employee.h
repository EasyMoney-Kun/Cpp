// 普通员工文件
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
class Employee : public Worker
{
public:
    Employee(int id, string name, int dID);
    // 显示个人信息
    virtual void showINfo();
    // 获取岗位
    virtual string getDeptName();
};
