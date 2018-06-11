#ifndef _ITEM_H
#define _ITEM_H 1

#include "Color.h"

/**
 * in the world is every non whithe point an item (robug, poi, sensor)
 */
class Item {
public:
    int x;
    int y;
    Color color;
};

#endif