#include <iostream>
using namespace std;
class Point
{
private:
    int m_X;
    int m_Y;

public:
    void setX(int x)
    {
        m_X = x;
    }
    int getX()
    {
        return m_X;
    }
    void setY(int y)
    {
        m_Y = y;
    }
    int getY()
    {
        return m_Y;
    }
};
class Circle
{
private:
    int m_R;
    Point m_Center;

public:
    void setR(int r)
    {
        m_R = r;
    }
    int getR()
    {
        return m_R;
    }
    void setCenter(Point center)
    {
        m_Center = center;
    }
    Point getCenter()
    {
        return m_Center;
    }
};
void isInCircle(Circle &c, Point &p)
{
    int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
                   (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    int rdistance = c.getR() * c.getR();
    if (distance == rdistance)
    {
        cout << "点在圆上" << endl;
    }
    else if (distance > rdistance)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
}
int main()
{
    Circle c;
    c.setR(1);
    Point p;
    Point center;
    p.setX(0);
    p.setY(0);
    center.setX(0);
    center.setY(0);
    c.setCenter(center);
    isInCircle(c, p);
    system("pause");
    return 0;
}
/***********************************
设计一个圆类（Circle）和一个点类（Point），计算点和圆的位置关系
***********************************/