#include <iostream>
using namespace std;
#include <string>
class Building
{
    friend void goodGuy(Building &building); // 全局函数做友元

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_Bedroon = "卧室";
    }

public:
    string m_SittingRoom;

private:
    string m_Bedroon;
};
// 全局函数做友元
void goodGuy(Building &building)
{
    cout << "好基友全局函数正在访问" << building.m_SittingRoom << endl;
    cout << "好基友全局函数正在访问" << building.m_Bedroon << endl;
}
void test01()
{
    Building b;
    goodGuy(b);
}
int main()
{
    test01();

    system("pause");
    return 0;
}
/***********************************
友元的三种实现：
    全局函数做友元
    类做友元
    成员函数做友元
***********************************/