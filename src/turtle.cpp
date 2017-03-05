#include "turtle.h"

Turtle::Turtle(const Position &pos)
    : Enemy("res/images/turtle.png", pos)
{
    scaledWidth = bitmap.getWidth() / 2 * SCALE;
    scaledHeight = bitmap.getHeight() / 3 * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Enemy;

    for (int i = 0; i < 2; i++)
        walk[i] = new Rectangle(bitmap.getWidth() / 2 * i, bitmap.getHeight() / 3 * 2, bitmap.getWidth() / 2, bitmap.getHeight() / 3);

    currentFrameNumber = 0;
    dir = Left;
    currentFrame = walk[0];
    moveSpeed = 1;
    gravity = 0.5;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    isCollidable = true;
}

void Turtle::update(ALLEGRO_EVENT event) {
    if (dir == Left) {
        if (!isObstacleOnLeft)
            velocity.first = -moveSpeed;
    } else {
        if (!isObstacleOnRight)
            velocity.first = moveSpeed;
    }
    currentFrameNumber += frameChangeSpeed;
    if (currentFrameNumber >= 4)
        currentFrameNumber = 0;
    currentFrame = walk[(int)currentFrameNumber / 2];
}

void Turtle::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), currentFrame->left, currentFrame->top, currentFrame->width, currentFrame->height, box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Turtle::moveLeft() {
    box->update(box->left - 5, box->top);
}
