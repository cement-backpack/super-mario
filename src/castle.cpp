#include "castle.h"

Castle::Castle(const Point &pos)
    : GameObject("res/images/castle.png", pos)
{
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Castle;
}

void Castle::update(ALLEGRO_EVENT event) {

}

void Castle::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), box->left(), box->top(), scaledWidth, scaledHeight, 0);
}

void Castle::moveLeft() {
    box->move(Point(box->left() - 5, box->top()));
}
