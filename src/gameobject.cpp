#include "gameobject.h"

GameObject::GameObject(const Point &pos)
    : position(pos), velocity(0, 0), box(0, 0, 0, 0)
{
}

GameObject::GameObject(const std::string &bitmapFilename, const Point &pos)
    : bitmap(bitmapFilename), position(pos), velocity(0, 0), box(0, 0, 0, 0)
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
