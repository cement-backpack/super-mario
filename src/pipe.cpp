#include "pipe.h"

Pipe::Pipe(PipeType type, const Point &pos)
    : GameObject(pos), type(type)
{
    switch (type) {
    case Pipe::Big:
        bitmap.load("res/images/pipe-big.png");
        break;
    case Pipe::Medium:
        bitmap.load("res/images/pipe-medium.png");
        break;
    case Pipe::Small:
        bitmap.load("res/images/pipe-small.png");
        break;
    }
    isCollidable = true;
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box.move(position);
    box.resize(Point(scaledWidth, scaledHeight));
    objectType = GameObject::Pipe;
}

void Pipe::update(ALLEGRO_EVENT event) {

}

void Pipe::draw() {
     al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), box.left(), box.top(), scaledWidth, scaledHeight, 0);
}

void Pipe::moveLeft() {
    box.move(Point(box.left() - 5, box.top()));
}
