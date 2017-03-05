#include "gameobject.h"

GameObject::GameObject(const Position &pos)
    : position(pos)
{
}

GameObject::GameObject(const std::string &bitmapFilename, const Position &pos)
    : bitmap(bitmapFilename), position(pos)
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
