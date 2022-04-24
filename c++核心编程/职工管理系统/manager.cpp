#include "manager.h"
Manager::Manager(int id, string name, int dID)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dID;
};
// 显示个人信息
void Manager::showINfo()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
};
// 获取岗位
string Manager::getDeptName()
{
    return string("经理");
};