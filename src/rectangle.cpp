#include "rectangle.h"

Rectangle::Rectangle(float x, float y, float w, float h)
    : position(x, y), size(w, h)
{
}

float
Rectangle::left() const
{
    return position.x;
}

float
Rectangle::right() const
{
    return position.x + size.x;
}

float
Rectangle::bottom() const
{
    return position.y + size.y;
}

float
Rectangle::top() const
{
    return position.y;
}

float
Rectangle::width() const
{
    return size.x;
}

float
Rectangle::height() const
{
    return size.y;
}

Point
Rectangle::getLowerLeft() const
{
    return Point(position.x, position.y + size.y);
}

Point
Rectangle::getUpperLeft() const
{
    return position;
}

Point
Rectangle::getUpperRight() const
{
    return Point(position.x + size.x, position.y);
}

Point
Rectangle::getLowerRight() const
{
    return Point(position.x + size.x, position.y + size.y);
}

bool
Rectangle::intersects(const Point &point) const
{
    return (position.x <= point.x) &&
        ((position.x + size.x) >= point.x) &&
        (position.y <= point.y) &&
        ((position.y + size.y) >= point.y);
}

int
Rectangle::intersects(const Rectangle &rect) const
{
    int res = Rectangle::None;

    if (intersects(rect.getLowerLeft()) || rect.intersects(getUpperRight()))
        res |= Rectangle::Right | Rectangle::Top;
    if (intersects(rect.getUpperLeft()) || rect.intersects(getLowerRight()))
        res |= Rectangle::Right | Rectangle::Bottom;
    if (intersects(rect.getUpperRight()) || rect.intersects(getLowerLeft()))
        res |= Rectangle::Left | Rectangle::Bottom;
    if (intersects(rect.getLowerRight()) || rect.intersects(getUpperLeft()))
        res |= Rectangle::Left | Rectangle::Top;

    return res;
}

void
Rectangle::move(const Point &point)
{
    position = point;
}

void
Rectangle::resize(const Point &point)
{
    size = point;
}

void
Rectangle::updateWithLeft(float left)
{
    position.x = left;
}

void
Rectangle::updateWithBottom(float bottom)
{
    position.y = bottom - size.y;
}

void
Rectangle::updateWithRight(float right)
{
    position.x = right - size.x;
}

void
Rectangle::updateWithTop(float top)
{
    position.y = top;
}
