#include "mariosprite.h"

MarioSprite::MarioSprite(const Bitmap &bitmap)
    : bitmap(bitmap),
    crouchingOrDead    (bitmap.getWidth() / 3 * 0, bitmap.getHeight() / 3 * 0, bitmap.getWidth() / 3, bitmap.getHeight() / 3),
    hung({    Rectangle(bitmap.getWidth() / 3 * 1, bitmap.getHeight() / 3 * 0, bitmap.getWidth() / 3, bitmap.getHeight() / 3),
              Rectangle(bitmap.getWidth() / 3 * 2, bitmap.getHeight() / 3 * 0, bitmap.getWidth() / 3, bitmap.getHeight() / 3), }),
    jumping            (bitmap.getWidth() / 3 * 0, bitmap.getHeight() / 3 * 1, bitmap.getWidth() / 3, bitmap.getHeight() / 3),
    running            (bitmap.getWidth() / 3 * 1, bitmap.getHeight() / 3 * 1, bitmap.getWidth() / 3, bitmap.getHeight() / 3),
    standing           (bitmap.getWidth() / 3 * 2, bitmap.getHeight() / 3 * 1, bitmap.getWidth() / 3, bitmap.getHeight() / 3),
    walking({ Rectangle(bitmap.getWidth() / 3 * 0, bitmap.getHeight() / 3 * 2, bitmap.getWidth() / 3, bitmap.getHeight() / 3),
              Rectangle(bitmap.getWidth() / 3 * 1, bitmap.getHeight() / 3 * 2, bitmap.getWidth() / 3, bitmap.getHeight() / 3),
              Rectangle(bitmap.getWidth() / 3 * 2, bitmap.getHeight() / 3 * 2, bitmap.getWidth() / 3, bitmap.getHeight() / 3),
            }),
    state(MarioState::Standing),
    direction(MarioDirection::Right),
    step(0)
{
}

const Rectangle &
MarioSprite::getRectangle() const
{
    switch (state) {
    case MarioState::CrouchingOrDead: return crouchingOrDead;
    case MarioState::Hung: return hung[step % (sizeof(hung) / sizeof(hung[0]))];
    case MarioState::Jumping: return standing;
    case MarioState::Running: return running;
    case MarioState::Standing: return standing;
    case MarioState::Walking: return walking[step % (sizeof(walking) / sizeof(walking[0]))];
    }
}

void
MarioSprite::setState(MarioState s)
{
    if (state == MarioState::Walking && s == state)
        return;

    state = s;
    step = 0;
}

void
MarioSprite::setDirection(MarioDirection d)
{
    direction = d;
    step = 0;
}

MarioSprite::MarioDirection
MarioSprite::getDirection() const
{
    return direction;
}

void
MarioSprite::setStep(unsigned int s)
{
    step = s;
}
