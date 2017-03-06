#include "wall.h"

Wall::Wall(const std::pair<int, int> &xRange, int y)
    : GameObject("res/images/wall.png", Point(0, 0)), xRange(xRange), y(y)
{
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    isCollidable = true;
    width = xRange.second - xRange.first;
    height = 100;

    box = new Rectangle(xRange.first, y, width, height);
    objectType = GameObject::Wall;
}

void Wall::update(ALLEGRO_EVENT event) {

}

void Wall::draw() {
    for (int i = box->left(); i < box->width(); i += scaledWidth) {
        for (int j = y; j < y + height; j += scaledHeight) {
            al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), i, j, scaledWidth, scaledHeight, 0);
        }
    }
}

void Wall::moveLeft() {
    box->move(Point(box->left() - 5, box->top()));
}
