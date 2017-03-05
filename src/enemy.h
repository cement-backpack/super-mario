#ifndef ENEMY_H
#define ENEMY_H

#include "gameobject.h"

class Enemy : public GameObject {
public:
    Enemy(const Position &pos);
    virtual void update(ALLEGRO_EVENT event);
    virtual void draw();
    virtual void moveLeft();
};

#endif // ENEMY_H
