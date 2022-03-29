#include <iostream>
using namespace std;
class person
{
public:
    string m_Name;

protected:
    string m_Car;

private:
    int m_Password;

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 110;
    }
};
int main()
{
    person p1;
    p1.m_Name = "李四";
   // p1.m_Car = "跑车"; protected 保护权限    成员  类内可以访问 类外不可以访问
   // p1.m_password = 120; private 私有权限      成员  类内可以访问 类外不可以访问
    system("pause");
    return 0;
}
/***********************************
类在设计的时，可以吧属性和行为放在不同的权限下，加以控制
访问权限有三种：
1.public 公共权限       成员  类内可以访问 类外可以访问
2.protected 保护权限    成员  类内可以访问 类外不可以访问
3.private 私有权限      成员  类内可以访问 类外不可以访问
***********************************/