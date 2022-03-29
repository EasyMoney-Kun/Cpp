#pragma once
#include <iostream>
using namespace std;
#include "point.h"
class Circle
{
private:
    int m_R;
    Point m_Center;

public:
    void setR(int r);
    int getR();
    void setCenter(Point center);
    Point getCenter();
};