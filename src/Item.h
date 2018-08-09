#ifndef _ITEM_H
#define _ITEM_H 1

#include "Color.h"

/**
 * in the world is every non whith point an item (robot, location, tile)
 */
class Item {
public:
    int x;
    int y;
    Color color;
};

#endif