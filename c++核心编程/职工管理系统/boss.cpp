#include "boss.h"

Boss::Boss(int id, string name, int dID)
{

    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dID;
};
// 显示个人信息
void Boss::showINfo()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位职责：管理公司所有事物" << endl;
};
// 获取岗位
string Boss::getDeptName()
{
    return string("总裁");
};