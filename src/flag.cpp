#include "flag.h"

Flag::Flag(const Point &pos)
    : GameObject("res/images/flag.png", pos)
{
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box.resize(Point(scaledWidth, scaledHeight));
    objectType = GameObject::Bush;
}

void Flag::update(ALLEGRO_EVENT event) {

}

void Flag::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), box.left(), box.top(), scaledWidth, scaledHeight, 0);
}

void Flag::moveLeft() {
    box.move(Point(box.left() - 5, box.top()));
}
