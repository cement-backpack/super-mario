#include "brick.h"

Brick::Brick(const Point &pos)
    : GameObject("res/images/brick.png", pos)
{
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Brick;
}

void Brick::update(ALLEGRO_EVENT event) {

}

void Brick::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), box->left(), box->top(), scaledWidth, scaledHeight, 0);
}

void Brick::moveLeft() {
    box->move(Point(box->left() - 5, box->top()));
}
