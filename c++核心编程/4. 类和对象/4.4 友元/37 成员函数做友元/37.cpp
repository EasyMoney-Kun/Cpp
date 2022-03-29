#include <iostream>
using namespace std;
#include <string>
class Building;
class GoodGay
{
public:
    Building *building;
    GoodGay();
    void visit01();
    void visit02();
};
class Building
{
    friend void GoodGay::visit01();

public:
    string m_SittingRoom;
    Building();

private:
    string m_BedRoom;
};
Building::Building()
{
    m_BedRoom = "卧室";
    m_SittingRoom = "客厅";
}
GoodGay::GoodGay()
{
    building = new Building;
}
void GoodGay::visit01()
{
    cout << "visit01正在访问" << building->m_SittingRoom << endl;
    cout << "visit01正在访问" << building->m_BedRoom << endl;
}
void GoodGay::visit02()
{
    cout << "visit02正在访问" << building->m_SittingRoom << endl;
    // cout << "visit01正在访问" << building->m_BedRoom << endl;
}
void test01()
{
    GoodGay gg;
    gg.visit01();
    gg.visit02();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
/***********************************

***********************************/