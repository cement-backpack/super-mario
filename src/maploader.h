#ifndef MAPLOADER_H
#define MAPLOADER_H

#include <string>
#include <list>

class MapLoader {
public:
    std::list<std::pair< std::string, std::string> > objects;
    MapLoader();
    void loadMap(const std::string &mapID);
};

#endif // MAPLOADER_H
