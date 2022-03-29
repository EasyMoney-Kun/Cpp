#include <iostream>
using namespace std;
#include <string>
class Person
{
private:
    string m_Name;
    int m_Age;
    string m_Lover;

public:
    void setName(string name)
    {
        m_Name = name;
    }
    string getName()
    {
        return m_Name;
    }
    void setAge(int age)
    {
        if (age < 0 || age > 130)
        {
            m_Age = 0;
            cout << "您的输入有误！" << endl;
            return;
        }
        m_Age = age;
    }
    int getAge()
    {
        m_Age = 0;
        return m_Age;
    }
    void setLover(string lover)
    {
        m_Lover = lover;
    }
};
int main()
{
    Person p1;
    p1.setName("张三");
    p1.setAge(100);
    cout << "姓名为：" << p1.getName() << endl;
    cout << "年龄为：" << p1.getAge() << endl;
    p1.setLover("哈哈");

    system("pause");
    return 0;
}
/***********************************
优点1：将所有的成员属性设为私有，可以自己控制读写权限
优点2；对于写权限，我们可以检测数据的有效性
***********************************/