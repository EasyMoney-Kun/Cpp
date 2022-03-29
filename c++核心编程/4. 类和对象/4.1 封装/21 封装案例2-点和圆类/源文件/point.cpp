#include "point.h"

void Point::setX(int x) // 告诉编译器该函数为成员函数
{
    m_X = x;
}
int Point::getX()
{
    return m_X;
}
void Point::setY(int y)
{
    m_Y = y;
}
int Point::getY()
{
    return m_Y;
}
