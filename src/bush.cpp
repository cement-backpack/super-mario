#include "bush.h"

Bush::Bush(BushType type, const Point &pos)
    : GameObject(pos), type(type)
{
    switch (type) {
    case Bush::Big:
        bitmap.load("res/images/bush-big.png");
        break;
    case Bush::Medium:
        bitmap.load("res/images/bush-medium.png");
        break;
    case Bush::Small:
        bitmap.load("res/images/bush-small.png");
        break;
    }
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Bush;
}

void Bush::update(ALLEGRO_EVENT event) {

}

void Bush::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), box->left(), box->top(), scaledWidth, scaledHeight, 0);
}

void Bush::moveLeft() {
    box->move(Point(box->left() - 5, box->top()));
}
