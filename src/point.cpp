#include "point.h"

Point::Point(float x, float y)
    : x(x), y(y)
{
}

Point::Point(const Point &pos)
    : x(pos.x), y(pos.y)
{
}
