#include "block.h"

Block::Block(int size, const Point &pos)
    : GameObject("res/images/block.png", pos), size(size)
{
    scaledWidth = bitmap.getWidth() * SCALE;
    scaledHeight = bitmap.getHeight() * SCALE;
    box.move(position);
    box.resize(Point(scaledWidth, scaledHeight));
    objectType = GameObject::Block;
}
