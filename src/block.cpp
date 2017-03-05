#include "block.h"

Block::Block(int size, const Point &pos)
    : GameObject("res/images/block.png", pos), size(size)
{
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box = new Rectangle(position.x, position.y, scaledWidth, scaledHeight);
    objectType = GameObject::Block;
}
