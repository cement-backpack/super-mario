#include "position.h"

Position::Position(float x, float y)
    : x(x), y(y)
{
}

Position::Position(const Position &pos)
    : x(pos.x), y(pos.y)
{
}
