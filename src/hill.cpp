#include "hill.h"

Hill::Hill(HillType type, const Point &pos)
    : GameObject(pos), type(type)
{
    switch (type) {
    case Hill::Big:
        bitmap.load("res/images/hill-big.png");
        break;
    case Hill::Small:
        bitmap.load("res/images/hill-small.png");
        break;
    }
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Hill;
}

void Hill::update(ALLEGRO_EVENT event) {

}

void Hill::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Hill::moveLeft() {
    box->update(box->left - 5, box->top);
}
