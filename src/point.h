#ifndef POSITION_H
#define POSITION_H

#include <ostream>

struct Point {
    float x, y;

    Point(float x, float y);
    Point(const Point &p);

    Point &operator =(const Point &p);
    Point &operator +=(const Point &p);
    Point &operator -=(const Point &p);

    friend std::ostream &
    operator <<(std::ostream &stream, const Point &point)
    {
        return stream << point.x << ", " << point.y;
    }
};

#endif // POSITION_H
