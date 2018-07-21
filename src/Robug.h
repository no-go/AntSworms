#ifndef _ROBUG_H
#define _ROBUG_H 1

#include "Item.h"
#include "Direction.h"
#include "Color.h"
class World;
#include "World.h"

/**
 * a bug robot
 */
class Robug : public Item {
public:
    int orient;
    Color lastColor;
    static Color color;
    
    Robug();
    
    void wakeup(World * world);
    void move();
};

#endif