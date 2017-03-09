#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "bitmap.h"
#include "point.h"
#include "rectangle.h"

#include <allegro5/allegro.h>

#define SCALE 2

class GameObject {
protected:
    Bitmap bitmap;
    float scaledWidth, scaledHeight;
    float gravity;

public:
    bool activeGravity;
    enum ObjectType {
        Block = 0,
        Bush = 1,
        Castle = 2,
        Cloud = 4,
        Hill = 8,
        Mario = 16,
        Pipe = 32,
        SecretBox = 64,
        Wall = 128,
        Brick = 256,
        Enemy = 512
    };
    ObjectType objectType;

    Rectangle box;
    bool isCollidable = false;
    Point velocity;

    GameObject(const Point &pos);
    GameObject(const std::string &bitmapFilename, const Point &pos);

    virtual void update(ALLEGRO_EVENT event);
    virtual void draw();
    virtual bool haveCollideWith(GameObject *obj);
    virtual void collide(GameObject *obj);
    virtual void moveLeft();
};

#endif // GAMEOBJECT_H
