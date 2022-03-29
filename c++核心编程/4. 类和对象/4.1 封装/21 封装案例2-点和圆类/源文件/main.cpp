#include"point.h"
#include"circle.h"
#include"global function.h"
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