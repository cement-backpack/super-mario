#ifndef MARIOSPRITE_H
#define MARIOSPRITE_H

#include "gameobject.h"
#include "inputmanager.h"
#include "soundmanager.h"

class
MarioSprite
{
public:
    enum class MarioState {
        CrouchingOrDead,
        Hung,
        Jumping,
        Running,
        Standing,
        Walking,
    };

    enum class MarioDirection {
        Right,
        Left,
    };

private:
    const Bitmap &bitmap;
    Rectangle crouchingOrDead, hung[2], jumping, running, standing, walking[3];

    MarioState state;
    MarioDirection direction;

    unsigned int step;

public:
    MarioSprite(const Bitmap &bitmap);

    const Rectangle &getRectangle() const;

    void setState(MarioState s);

    void setDirection(MarioDirection d);
    MarioDirection getDirection() const;

    void setStep(unsigned int s);
};

#endif // MARIOSPRITE_H
