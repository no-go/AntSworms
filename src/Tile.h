#ifndef _TILE_H
#define _TILE_H 1

#include "Item.h"
#include "Color.h"

class Tile : public Item {
public:
    float value;
    
    Tile() {
        color = {255,155,80,255};
        value = 0.0;
    }
};

#endif