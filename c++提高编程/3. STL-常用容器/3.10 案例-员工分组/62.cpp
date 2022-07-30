#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include<ctime>
#define CHEHUA 0
#define MEISHU 1
#define YANFA 2
class Worker
{
public:
    Worker(string name, int salary)
    {
        this->m_Name = name;
        this->m_Salary = salary;
    }
    string m_Name;
    int m_Salary;
};
void creatWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        string name = "员工";
        name += nameSeed[i];
        int salary = rand() % 10000 + 20000;
        Worker worker(name, salary);
        v.push_back(worker);
    }
}
void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        //产生随机的部门编号
        int deptID = rand() % 3;
        m.insert(make_pair(deptID, *it));
    }
}
void showOne(const multimap<int, Worker> &m, int part) //输入部门编号展示详细信息
{
    multimap<int, Worker>::const_iterator pos = m.find(part);
    int count = m.count(part); //统计人数
    for (int index = 0; index < count && pos != m.end(); pos++, index++)
    {
        cout << "姓名：" << (*pos).second.m_Name << " "
             << "薪水：" << (*pos).second.m_Salary << endl;
    }
}
void showWorkerByGroup(const multimap<int, Worker> &m)
{
    cout << "策划部门：" << endl;
    showOne(m, CHEHUA);
    cout << "------------------" << endl;
    cout << "美术部门：" << endl;
    showOne(m, MEISHU);
    cout << "------------------" << endl;
    cout << "研发部门：" << endl;
    showOne(m, YANFA);
}
int main()
{
    srand((unsigned int)time(NULL));
    // 1.创建员工
    vector<Worker> vWorker;
    creatWorker(vWorker);
    // 2.员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);
    // 3.显示员工
    showWorkerByGroup(mWorker);
    system("pause");
    return 0;
}
/***********************************

***********************************/