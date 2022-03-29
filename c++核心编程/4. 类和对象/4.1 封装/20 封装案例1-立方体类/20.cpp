#include <iostream>
using namespace std;
class Cube
{
private:
    int m_L;
    int m_W;
    int m_H;

public:
    void setL(int l)
    {
        m_L = l;
    }
    int getL()
    {
        return m_L;
    }
    void setW(int w)
    {
        m_W = w;
    }
    int getW()
    {
        return m_W;
    }
    void setH(int h)
    {
        m_H = h;
    }
    int getH()
    {
        return m_H;
    }
    int calculateS()
    {
        return 2 * m_L * m_W + 2 * m_W * m_H + 2 * m_L * m_H;
    }
    int calculateV()
    {
        return m_L * m_W * m_H;
    }
    bool isSame(Cube &c)
    {
        if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())

            return true;

        else
            return false;
    }
};
bool isSame(Cube &c1, Cube &c2)
{
    if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH())

        return true;

    else
        return false;
}

int main()
{
    Cube c1;
    c1.setH(10);
    c1.setL(10);
    c1.setW(10);
    cout << c1.getH() << endl;
    cout << c1.getL() << endl;
    cout << c1.getW() << endl;
    int s = c1.calculateS();
    int v = c1.calculateV();
    cout << s << endl;
    cout << v << endl;
    Cube c2;
    c2.setH(10);
    c2.setL(20);
    c2.setW(10);
    bool ret = isSame(c1, c2);
    if (ret)
    {
        cout << "全局函数判断相等" << endl;
    }
    else
    {
        cout << "全局函数判断不相等" << endl;
    }
    bool ret1 = c2.isSame(c1);
    if (ret1)
    {
        cout << "成员函数判断相等" << endl;
    }
    else
    {
        cout << "成员函数判断不相等" << endl;
    }
    system("pause");
    return 0;
}
/***********************************
案例：设计长方体类 求出长方体的面积和体积
分别用全局函数和成员函数判断两个长方体是否相等
***********************************/