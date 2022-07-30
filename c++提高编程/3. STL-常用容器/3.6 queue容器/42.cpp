#include <iostream>
using namespace std;
#include <string>
#include <queue>
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};
void test01()
{
    queue<Person> q;
    string nameSeed = "ABCD";
    for (int i = 0; i < 4; i++)
    {
        string name = "小";
        name += nameSeed[i];
        Person p(name, i);
        q.push(p);
    }
    cout << "队列大小：" << q.size() << endl;
    while (!q.empty())
    {
        cout << "队头元素--姓名：" << q.front().m_Name << " 年龄：" << q.front().m_Age << endl;
        cout << "队尾元素--姓名：" << q.back().m_Name << " 年龄：" << q.back().m_Age << endl;
        q.pop();
    }
    cout << "队列大小：" << q.size() << endl;
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************
队列

构造函数：
queue<T> que;
queue(const queue &que);

赋值操作：
queue& operator=(const queue &que);

数据存取：
push(elem); //队尾插入元素
pop(); //队头弹出元素
back(); //返回最后一个元素
front(); //返回第一个元素

大小操作：
empty();
size();
***********************************/