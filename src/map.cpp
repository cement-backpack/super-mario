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
            objects.push_back(new Hill(Hill::Big, Position(x, y)));
        } else if (object.first == "hill-small") {
            objects.push_back(new Hill(Hill::Small, Position(x, y)));
        } else if (object.first == "bush-big") {
            objects.push_back(new Bush(Bush::Big, Position(x, y)));
        } else if (object.first == "bush-medium") {
            objects.push_back(new Bush(Bush::Medium, Position(x, y)));
        } else if (object.first == "bush-small") {
            objects.push_back(new Bush(Bush::Small, Position(x, y)));
        } else if (object.first == "wall") {
            objects.push_back(new Wall(xRange, y));
        } else if (object.first == "cloud-big") {
            objects.push_back(new Cloud(Cloud::Big, Position(x, y)));
        } else if (object.first == "cloud-medium") {
            objects.push_back(new Cloud(Cloud::Medium, Position(x, y)));
        } else if (object.first == "cloud-small") {
            objects.push_back(new Cloud(Cloud::Small, Position(x, y)));
        } else if (object.first == "castle") {
            objects.push_back(new Castle(Position(x, y)));
        } else if (object.first == "pipe-big") {
            objects.push_back(new Pipe(Pipe::Big, Position(x, y)));
        } else if (object.first == "pipe-medium") {
            objects.push_back(new Pipe(Pipe::Medium, Position(x, y)));
        } else if (object.first == "pipe-small") {
            objects.push_back(new Pipe(Pipe::Small, Position(x, y)));
        } else if (object.first == "secret-box-coin") {
            objects.push_back(new SecretBox(SecretBox::Coin, Position(x, y)));
        } else if (object.first == "secret-box-mushroom") {
            objects.push_back(new SecretBox(SecretBox::Mushroom, Position(x, y)));
        } else if (object.first == "hidden-secret-box") {
            objects.push_back(new SecretBox(SecretBox::Hidden, Position(x, y)));
        } else if (object.first == "brick-secret-box-coin") {
            objects.push_back(new SecretBox(SecretBox::Brick_Coin, Position(x, y)));
        } else if (object.first == "brick-secret-box-star") {
            objects.push_back(new SecretBox(SecretBox::Brick_Star, Position(x, y)));
        } else if (object.first == "brick") {
            objects.push_back(new Brick(Position(x, y)));
        } else if (object.first == "block-1") {
            objects.push_back(new Block(1, Position(x, y)));
        } else if (object.first == "block-2") {
            objects.push_back(new Block(2, Position(x, y)));
        } else if (object.first == "block-3") {
            objects.push_back(new Block(3, Position(x, y)));
        } else if (object.first == "block-4") {
            objects.push_back(new Block(4, Position(x, y)));
        } else if (object.first == "block-5") {
            objects.push_back(new Block(5, Position(x, y)));
        } else if (object.first == "block-6") {
            objects.push_back(new Block(6, Position(x, y)));
        } else if (object.first == "block-7") {
            objects.push_back(new Block(7, Position(x, y)));
        } else if (object.first == "block-8") {
            objects.push_back(new Block(8, Position(x, y)));
        } else if (object.first == "flag") {
            objects.push_back(new Flag(Position(x, y)));
        } else if (object.first == "owl") {
            objects.push_back(new Owl(Position(x, y)));
        }/* else if (object.first == "turtle") {
            objects.push_back(new Turtle(Position(x, y)));
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
