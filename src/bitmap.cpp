#include "bitmap.h"

#include <allegro5/allegro.h>

#include <cmath>

Bitmap::Bitmap()
    : image(NULL)
{
}

Bitmap::Bitmap(const std::string &filename)
    : image(NULL)
{
    load(filename);
}

Bitmap::~Bitmap()
{
    destroy();
}

ALLEGRO_BITMAP *
Bitmap::getImage()
{
    return image;
}

bool
Bitmap::load(const std::string &filename)
{
    destroy();
    image = al_load_bitmap(filename.c_str());
    return image != NULL;
}

void
Bitmap::destroy()
{
    if (image != NULL) {
        al_destroy_bitmap(image);
        image = NULL;
    }
}

int
Bitmap::getWidth() const
{
    if (image == NULL)
        return -1;
    return al_get_bitmap_width(image);
}

int
Bitmap::getHeight() const
{
    if (image == NULL)
        return -1;
    return al_get_bitmap_height(image);
}
