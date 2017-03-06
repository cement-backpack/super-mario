#include "mario.h"

Mario::Mario(SoundManager *sound)
    : GameObject("res/images/mario-small.png", Point(32 * SCALE, 32 * SCALE))
{
    type = Mario::Small;

    scaledWidth = bitmap.getWidth() / 3 * SCALE;
    scaledHeight = bitmap.getHeight() / 3 * SCALE;
    stand = new Rectangle(bitmap.getWidth() / 3 * 2, bitmap.getHeight() / 3, bitmap.getWidth() / 3, bitmap.getHeight() / 3);
    run = new Rectangle(bitmap.getWidth() / 3, bitmap.getHeight() / 3, bitmap.getWidth() / 3, bitmap.getHeight() / 3);
    crouchOrDie = new Rectangle(0, 0, bitmap.getWidth() / 3, bitmap.getHeight() / 3);
    for (int i = 0; i < 2; i++)
        hang[i] = new Rectangle(bitmap.getWidth() / 3 * (i + 1), 0, bitmap.getWidth() / 3, bitmap.getHeight() / 3);
    for (int i = 0; i < 3; i++)
        walk[i] = new Rectangle(bitmap.getWidth() / 3 * i, bitmap.getHeight() / 3 * 2, bitmap.getWidth() / 3, bitmap.getHeight() / 3);

    currentFrame = stand;
    jumpSpeed = 9;
    moveSpeed = 5;
    gravity = 0.5;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Mario;
    isCollidable = true;

    this->sound = sound;
}

void Mario::update(ALLEGRO_EVENT event, InputManager input) {
    input.update();
    if (input.isKeyDown(ALLEGRO_KEY_UP) || input.isKeyDown(ALLEGRO_KEY_DOWN)
            || input.isKeyDown(ALLEGRO_KEY_LEFT) || input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
        if (input.isKeyDown(ALLEGRO_KEY_UP)) {
            if (!isOnAir) {
                if (type == Mario::Big)
                    sound->playJumpBig();
                else
                    sound->playJumpSmall();
                dir = Up;
                isOnAir = true;
                velocity.y = -jumpSpeed;
                activeGravity = true;
            }
        } if (input.isKeyDown(ALLEGRO_KEY_LEFT)) {
            dir = Left;
            rightOrLeftFlag = 1;
            if (!isObstacleOnLeft)
                velocity.x = -moveSpeed;
            currentFrameNumber += frameChangeSpeed;
            if (currentFrameNumber >= 9)
                currentFrameNumber = 0;
            currentFrame = walk[(int)currentFrameNumber / 3];
        } if (input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
            dir = Right;
            rightOrLeftFlag = 0;
            if (!isObstacleOnRight)
                velocity.x = moveSpeed;
            currentFrameNumber += frameChangeSpeed;
            if (currentFrameNumber >= 9)
                currentFrameNumber = 0;
            currentFrame = walk[(int)currentFrameNumber / 3];
        } if (input.isKeyDown(ALLEGRO_KEY_DOWN)){
            dir = Down;
        }
    } else {
        velocity.x = 0;
    }

    if (velocity.x == 0 && velocity.y == 0) {
        currentFrame = stand;
        currentFrameNumber = 0;
    }

    if (activeGravity)
        velocity.y += gravity;

    position.x += velocity.x;
    position.y += velocity.y;

    box->move(position);

    isObstacleOnBottom = isObstacleOnLeft = isObstacleOnRight = isObstacleOnTop = false;
}
void Mario::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), currentFrame->left(), currentFrame->top(), currentFrame->width(), currentFrame->height(), box->left(), box->top(), scaledWidth, scaledHeight, rightOrLeftFlag);
}

bool Mario::haveCollideWith(GameObject *obj) {
    if (this->isCollidable && obj->isCollidable && this->box->intersects(*obj->box)) {
        return true;
    }
    return false;
}

void Mario::collide(GameObject *obj) {
    if (obj->objectType == GameObject::Wall) {
        velocity.y = 0;
        box->updateWithBottom(obj->box->top());
        isOnAir = false;
        activeGravity = false;
    } else if (obj->objectType == GameObject::Pipe) {
        int edge = this->box->intersects(*obj->box);
        if ((edge & Rectangle::Bottom) == Rectangle::Bottom) {
            velocity.y = 0;
            box->updateWithBottom(obj->box->top());
            isObstacleOnBottom = true;
            isOnAir = false;
            activeGravity = false;
        } if ((edge & Rectangle::Right) == Rectangle::Right) {
            velocity.x = 0;
            box->updateWithRight(obj->box->left());
            isObstacleOnRight = true;
        } if ((edge & Rectangle::Left) == Rectangle::Left) {
            velocity.x = 0;
            box->updateWithLeft(obj->box->right());
            isObstacleOnLeft = true;
        }
    } else if (obj->objectType == GameObject::Enemy) {
        sound->PlayPlayerDie();
    }
}
