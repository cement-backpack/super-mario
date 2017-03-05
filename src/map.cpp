#include "map.h"

Map::Map(const std::string &mapID) {
    loader.loadMap(mapID);

    for (const std::pair<std::string, std::string> &object : loader.objects) {
        float x, y;
        std::pair<float, float> xRange;
        std::string xString, yString;
        bool isX = true;
        for (int j = 0; j < object.second.length(); j++) {
            if (object.second[j] == ',') {
                isX = false;
                continue;
            }
            if (isX)
                xString += object.second[j];
            else
                yString += object.second[j];
        }

        if (object.first != "wall") {
            x = atof(xString.c_str());
        } else {
            int dashPos = xString.find('-');
            x = xRange.first = atof(xString.substr(0, dashPos).c_str());
            xRange.second = atof(xString.substr(dashPos + 1, xString.length() - dashPos - 1).c_str());
        }
        y = atoi(yString.c_str());

        x *= SCALE;
        y *= SCALE;
        xRange.first *= SCALE;
        xRange.second *= SCALE;

        if (object.first == "hill-big") {
            objects.push_back(new Hill(Hill::Big, Point(x, y)));
        } else if (object.first == "hill-small") {
            objects.push_back(new Hill(Hill::Small, Point(x, y)));
        } else if (object.first == "bush-big") {
            objects.push_back(new Bush(Bush::Big, Point(x, y)));
        } else if (object.first == "bush-medium") {
            objects.push_back(new Bush(Bush::Medium, Point(x, y)));
        } else if (object.first == "bush-small") {
            objects.push_back(new Bush(Bush::Small, Point(x, y)));
        } else if (object.first == "wall") {
            objects.push_back(new Wall(xRange, y));
        } else if (object.first == "cloud-big") {
            objects.push_back(new Cloud(Cloud::Big, Point(x, y)));
        } else if (object.first == "cloud-medium") {
            objects.push_back(new Cloud(Cloud::Medium, Point(x, y)));
        } else if (object.first == "cloud-small") {
            objects.push_back(new Cloud(Cloud::Small, Point(x, y)));
        } else if (object.first == "castle") {
            objects.push_back(new Castle(Point(x, y)));
        } else if (object.first == "pipe-big") {
            objects.push_back(new Pipe(Pipe::Big, Point(x, y)));
        } else if (object.first == "pipe-medium") {
            objects.push_back(new Pipe(Pipe::Medium, Point(x, y)));
        } else if (object.first == "pipe-small") {
            objects.push_back(new Pipe(Pipe::Small, Point(x, y)));
        } else if (object.first == "secret-box-coin") {
            objects.push_back(new SecretBox(SecretBox::Coin, Point(x, y)));
        } else if (object.first == "secret-box-mushroom") {
            objects.push_back(new SecretBox(SecretBox::Mushroom, Point(x, y)));
        } else if (object.first == "hidden-secret-box") {
            objects.push_back(new SecretBox(SecretBox::Hidden, Point(x, y)));
        } else if (object.first == "brick-secret-box-coin") {
            objects.push_back(new SecretBox(SecretBox::Brick_Coin, Point(x, y)));
        } else if (object.first == "brick-secret-box-star") {
            objects.push_back(new SecretBox(SecretBox::Brick_Star, Point(x, y)));
        } else if (object.first == "brick") {
            objects.push_back(new Brick(Point(x, y)));
        } else if (object.first == "block-1") {
            objects.push_back(new Block(1, Point(x, y)));
        } else if (object.first == "block-2") {
            objects.push_back(new Block(2, Point(x, y)));
        } else if (object.first == "block-3") {
            objects.push_back(new Block(3, Point(x, y)));
        } else if (object.first == "block-4") {
            objects.push_back(new Block(4, Point(x, y)));
        } else if (object.first == "block-5") {
            objects.push_back(new Block(5, Point(x, y)));
        } else if (object.first == "block-6") {
            objects.push_back(new Block(6, Point(x, y)));
        } else if (object.first == "block-7") {
            objects.push_back(new Block(7, Point(x, y)));
        } else if (object.first == "block-8") {
            objects.push_back(new Block(8, Point(x, y)));
        } else if (object.first == "flag") {
            objects.push_back(new Flag(Point(x, y)));
        } else if (object.first == "owl") {
            objects.push_back(new Owl(Point(x, y)));
        }/* else if (object.first == "turtle") {
            objects.push_back(new Turtle(Point(x, y)));
        }*/
    }
}

Map::~Map()
{
    for (GameObject *go : objects) {
        delete go;
    }

    objects.clear();
}

void Map::update(ALLEGRO_EVENT event) {
    for (std::vector<GameObject*>::iterator itr = objects.begin(); itr != objects.end(); itr++) {
        (*itr)->update(event);
    }
}

void Map::draw() {
    for (std::vector<GameObject*>::iterator itr = objects.begin(); itr != objects.end(); itr++) {
        (*itr)->draw();
    }
}

void Map::moveMapToLeft() {
    for (std::vector<GameObject*>::iterator itr = objects.begin(); itr != objects.end(); itr++) {
        (*itr)->moveLeft();
    }
}
