#ifndef MARIO_H
#define MARIO_H

#include "gameobject.h"
#include "inputmanager.h"
#include "mariosprite.h"
#include "soundmanager.h"

class Mario : public GameObject {
private:
    SoundManager *sound;

    MarioSprite sprite;
    enum MarioType {Big, Small};
    MarioType type;
    const float jumpSpeed = 9, moveSpeed = 5;
    bool isOnAir = false;
    float frameChangeSpeed = 0.5;
    float currentFrameNumber = 0;
    bool isObstacleOnTop = false, isObstacleOnBottom = false, isObstacleOnRight = false, isObstacleOnLeft = false;

public:
    enum Direction {Up, Down, Left, Right};

    Mario(SoundManager *sound);

    void update(ALLEGRO_EVENT event, InputManager input);
    void draw();
    bool haveCollideWith(GameObject *obj);
    void collide(GameObject *obj);

    float right();
    void updateWithRight(float x);
};

#endif // MARIO_H
