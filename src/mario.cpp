#include "mario.h"

Mario::Mario(SoundManager *sound)
    : GameObject("res/images/mario-small.png", Point(32 * SCALE, 32 * SCALE)), sprite(bitmap)
{
    type = Mario::Small;
    activeGravity = true;

    scaledWidth = bitmap.getWidth() / 3 * SCALE;
    scaledHeight = bitmap.getHeight() / 3 * SCALE;

    gravity = 0.5;

    box.resize(Point(scaledWidth, scaledHeight));

    objectType = GameObject::Mario;
    isCollidable = true;

    this->sound = sound;

    currentFrameNumber = 0;
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
                isOnAir = true;
                velocity.y = -jumpSpeed;
                activeGravity = true;
            }
        }

        if (input.isKeyDown(ALLEGRO_KEY_LEFT)) {
            sprite.setDirection(MarioSprite::MarioDirection::Left);
            if (!isObstacleOnLeft)
                velocity.x = -moveSpeed;
            currentFrameNumber += frameChangeSpeed;
            sprite.setState(MarioSprite::MarioState::Walking);
            sprite.setStep(currentFrameNumber / 3);
        }

        if (input.isKeyDown(ALLEGRO_KEY_RIGHT)) {
            sprite.setDirection(MarioSprite::MarioDirection::Right);
            if (!isObstacleOnRight)
                velocity.x = moveSpeed;
            currentFrameNumber += frameChangeSpeed;
            sprite.setState(MarioSprite::MarioState::Walking);
            sprite.setStep(currentFrameNumber / 3);
        }
    } else {
        velocity.x = 0;
    }

    if (velocity.x == 0 && velocity.y == 0) {
        sprite.setState(MarioSprite::MarioState::Standing);
    }

    if (activeGravity)
        velocity.y += gravity;

    box.shift(velocity);

    isObstacleOnBottom = isObstacleOnLeft = isObstacleOnRight = isObstacleOnTop = false;
}
void Mario::draw() {
    const Rectangle &frame = sprite.getRectangle();
    al_draw_scaled_bitmap(bitmap.getImage(), frame.left(), frame.top(), frame.width(), frame.height(), box.left(), box.top(), scaledWidth, scaledHeight, sprite.getDirection() == MarioSprite::MarioDirection::Left);
}

bool Mario::haveCollideWith(GameObject *obj) {
    if (isCollidable && obj->isCollidable && box.intersects(obj->box)) {
        return true;
    }
    return false;
}

void Mario::collide(GameObject *obj) {
    if (obj->objectType == GameObject::Wall) {
        velocity.y = 0;
        box.updateWithBottom(obj->box.top());
        isOnAir = false;
        activeGravity = false;
    } else if (obj->objectType == GameObject::Pipe) {
        int edge = box.intersects(obj->box);

        if ((edge & Rectangle::Bottom) == Rectangle::Bottom) {
            velocity.y = 0;
            box.updateWithBottom(obj->box.top());
            isObstacleOnBottom = true;
            isOnAir = false;
            activeGravity = false;
        }

        if ((edge & Rectangle::Right) == Rectangle::Right) {
            velocity.x = 0;
            box.updateWithRight(obj->box.left());
            isObstacleOnRight = true;
        }

        if ((edge & Rectangle::Left) == Rectangle::Left) {
            velocity.x = 0;
            box.updateWithLeft(obj->box.right());
            isObstacleOnLeft = true;
        }
    } else if (obj->objectType == GameObject::Enemy) {
        sound->PlayPlayerDie();
    }
}

float
Mario::right()
{
    return box.right();
}

void
Mario::updateWithRight(float x)
{
    box.updateWithRight(x);
}
