#ifndef POSITION_H
#define POSITION_H

struct Point {
    float x, y;

    Point(float x, float y);
    Point(const Point &pos);
};

#endif // POSITION_H
