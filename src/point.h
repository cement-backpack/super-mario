#ifndef POSITION_H
#define POSITION_H

struct Point {
    float x, y;

    Point(float x, float y);
    Point(const Point &p);

    Point &operator =(const Point &p);
    Point &operator +=(const Point &p);
    Point &operator -=(const Point &p);
};

#endif // POSITION_H
