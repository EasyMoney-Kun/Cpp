#include <iostream>
using namespace std;
#include <string>
class Student
{
public:
    string m_Name;
    int m_Id;
    void showStudent()
    {
        cout << "姓名：" << m_Name << "学号：" << m_Id << endl;
    }
    void setName(string name)
    {
        m_Name = name;
    }
    void setId(int id)
    {
        m_Id = id;
    }
};
int main()
{
    Student s1;
    s1.m_Name = "张三";
    s1.m_Id = 1;
    s1.showStudent();
    Student s2;
    s2.setName("李四");
    s2.setId(2);
    s2.showStudent();
    system("pause");
    return 0;
}
/***********************************
类中的属性和行为 我们统称为 成员
属性 成员属性 成员变量
行为 成员函数 成员方法
***********************************/