#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle {
protected:
    Point position, size;

public:
    enum Edge {Top = 1, Bottom = 2, Left = 4, Right = 8, None = 0};

    Rectangle(float x, float y, float w, float h);

    float left() const;
    float right() const;
    float bottom() const;
    float top() const;
    float width() const;
    float height() const;

protected:
    Point getLowerLeft() const;
    Point getUpperLeft() const;
    Point getUpperRight() const;
    Point getLowerRight() const;

public:
    bool intersects(const Point &point) const;
    int intersects(const Rectangle &rect) const;

    void move(const Point &bl);

    void updateWithBottom(float bottom);
    void updateWithLeft(float left);
    void updateWithRight(float right);
    void updateWithTop(float top);
};

#endif // FLOATRECT_H
