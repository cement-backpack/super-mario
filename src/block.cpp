#include "block.h"

Block::Block(int size, const Position &pos)
    : GameObject(pos), size(size)
{
    image = al_load_bitmap("res/images/block.png");
    imageWidth = al_get_bitmap_width(image);
    imageHeight = al_get_bitmap_height(image);
    scaledWidth = imageWidth * SCALE;
    scaledHeight = imageHeight * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Block;
}
