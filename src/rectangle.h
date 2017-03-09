#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"

class Rectangle {
protected:
    Point position, size;

public:
    enum Edge {
        None = 0,
        Top = 1,
        Bottom = 2,
        Left = 4,
        Right = 8,
    };

    Rectangle(float x, float y, float w, float h);
    Rectangle(const Point &position, const Point &size);

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

    void shift(const Point &point);
    void move(const Point &point);
    void resize(const Point &point);

    void updateWithBottom(float bottom);
    void updateWithLeft(float left);
    void updateWithRight(float right);
    void updateWithTop(float top);
};

#endif // FLOATRECT_H
