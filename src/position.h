#ifndef POSITION_H
#define POSITION_H

struct Position {
    float x, y;

    Position(float x, float y);
    Position(const Position &pos);
};

#endif // POSITION_H
