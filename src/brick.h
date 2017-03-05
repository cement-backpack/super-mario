#ifndef BRICK_H
#define BRICK_H

#include "gameobject.h"

class Brick : public GameObject {
public:
    Brick(const Point &pos);
    void update(ALLEGRO_EVENT event);
    void draw();
    void moveLeft();
};

#endif // BRICK_H
