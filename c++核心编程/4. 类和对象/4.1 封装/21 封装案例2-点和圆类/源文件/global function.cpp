#include "point.h"
#include "circle.h"
#include "global function.h"
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