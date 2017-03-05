#ifndef BITMAP_H
#define BITMAP_H

#include <string>

struct ALLEGRO_BITMAP;

class
Bitmap
{
private:
    ALLEGRO_BITMAP *image;

public:
    Bitmap();
    Bitmap(const std::string &filename);
    ~Bitmap();

    ALLEGRO_BITMAP *getImage();

    bool load(const std::string &filename);
    void destroy();

    int getWidth();
    int getHeight();
};

#endif // BITMAP_H
