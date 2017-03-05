#include "secretbox.h"

SecretBox::SecretBox(SecretBoxType type, const Position &pos)
    : GameObject(pos), type(type)
{
    switch (type) {
    case SecretBox::Coin:
    case SecretBox::Mushroom:
        bitmap.load("res/images/secret-box.png");
        break;
    case SecretBox::Brick_Coin:
    case SecretBox::Brick_Star:
        bitmap.load("res/images/brick.png");
        break;
    case SecretBox::Hidden:
        bitmap.load("res/images/solid.png");
        isHidden = true;
        break;
    }
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::SecretBox;
}

void SecretBox::update(ALLEGRO_EVENT event){

}

void SecretBox::draw(){
    al_draw_scaled_bitmap(bitmap.getImage(), 0, 0, bitmap.getWidth(), bitmap.getHeight(), box->left, box->top, scaledWidth, scaledHeight, 0);
}

void SecretBox::moveLeft() {
    box->update(box->left - 5, box->top);
}
