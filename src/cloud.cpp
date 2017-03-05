#include "cloud.h"

Cloud::Cloud(CloudType type, const Point &pos)
    : GameObject(pos), type(type)
{
    switch (type) {
    case Cloud::Big:
        bitmap.load("res/images/cloud-big.png");
        break;
    case Cloud::Medium:
        bitmap.load("res/images/cloud-medium.png");
        break;
    case Cloud::Small:
        bitmap.load("res/images/cloud-small.png");
        break;
    }
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Cloud;
}

void Cloud::update(ALLEGRO_EVENT event) {

}

void Cloud::draw() {
    al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), box->left, box->top, scaledWidth, scaledHeight, 0);
}

void Cloud::moveLeft() {
    box->update(box->left - 5, box->top);
}
