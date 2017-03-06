#include "point.h"

Point::Point(float x, float y)
    : x(x), y(y)
{
}

Point::Point(const Point &p)
    : x(p.x), y(p.y)
{
}

Point &
Point::operator =(const Point &p)
{
    x = p.x;
    y = p.y;
    return *this;
}

Point &
Point::operator +=(const Point &p)
{
    x += p.x;
    y += p.y;
    return *this;
}

Point &
Point::operator -=(const Point &p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}
