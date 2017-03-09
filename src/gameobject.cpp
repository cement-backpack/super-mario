#include "gameobject.h"

GameObject::GameObject(const Point &pos)
    : box(pos, Point(0, 0)), velocity(0, 0)
{
}

GameObject::GameObject(const std::string &bitmapFilename, const Point &pos)
    : bitmap(bitmapFilename), box(pos, Point(0, 0)), velocity(0, 0)
{
}

void GameObject::update(ALLEGRO_EVENT event) {

}

void GameObject::draw() {

}

bool GameObject::haveCollideWith(GameObject *obj) {

}

void GameObject::collide(GameObject *obj) {

}

void GameObject::moveLeft() {

}
